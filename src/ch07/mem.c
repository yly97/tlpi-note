// 7-2 实现malloc和free
// 需要注意的是第一次调用printf时，底层后调用malloc分配一部分内存，
// 因此连续两次调用sbrk(0)所获得地址不同

#include <stdint.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

#include "mem.h"

// 将32位的无符号整型按8字节对齐
#define ALIGN32_3(x) (((x) + 0x7) & 0xFFFFFFFF8)
// 将32位的无符号整型按4096字节对齐
#define ALIGN32_12(x) (((x) + 0xFFF) & 0xFFFFFF000)
// 将64位的无符号整型按4字节对齐
#define ALIGN64_2(x) (((x) + 0x3) & 0xFFFFFFFFFFFFFFFC)
#define HEAP_MIN_ADDR 0

// typedef unsigned long m_ptrval_t;
// typedef unsigned int m_size_t;

static uint64_t heap_start = HEAP_MIN_ADDR;
static uint64_t heap_end;

// 块大小按8字节对齐，因此存储块的32位整型后3位必位0，
// 因此，将最后一位用来标记块是否已分配
static uint32_t getBlockSize(uint32_t metadata) {
    return metadata & 0xFFFFFFF8;
}

static uint32_t getAllocated(uint32_t metadata) {
    return metadata & 0x1;
}

// 设置块大小的时候默认就把块是否分配的标志位设为0
void setBlockSize(uint64_t block_addrv, uint32_t size) {
    uint32_t *header_addr = (uint32_t *)block_addrv;
    uint32_t *footer_addr = (uint32_t *)(block_addrv + size - 4);
    *header_addr = *footer_addr = size;
}

void setAllocated(uint64_t block_addrv, uint32_t size) {
    uint32_t *header_addr = (uint32_t *)block_addrv;
    uint32_t *footer_addr = (uint32_t *)(block_addrv + size - 4);
    *header_addr = *footer_addr |= 0x1;
}

// 只有第一次分配内存时会调用该函数
int initHeap(uint32_t size) {
    intptr_t increment = ALIGN32_12(size);
    void * start = sbrk(increment);
    if (start == (void *)-1) {
        return -1;
    }
    heap_start = ALIGN64_2((uint64_t)start);
    heap_end = heap_start + increment - 8;
    setBlockSize(heap_start, increment - 8);
    return 0;
}

// 增加堆大小，以页（4KB）为单位扩大，并且将新申请到的内存块添加到尾部，
// 申请成功返回0，失败返回-1；
int appendHeap(uint32_t size) {
    intptr_t increment = ALIGN32_12(size);
    if (sbrk(increment) == (void *)-1) {
        return -1;
    }
    setBlockSize(heap_end, increment);
    heap_end += increment;
    return 0;
}

// 内存大小不够时，向堆申请增加内存时，应该将尾部内存空闲块合并后再分配，待优化。。
void *memAlloc(uint32_t size) {
    uint64_t block_addrv = heap_start;
    uint32_t request_size = ALIGN32_3(size) + 8;
    
    // 第一次分配内存
    if (heap_start == HEAP_MIN_ADDR) {
        if (initHeap(size) == -1) return NULL;
    }

    while (1) {
        // 找不到空闲块就增加堆大小
        if (block_addrv >= heap_end) {
            if (appendHeap(size) == -1) return NULL;
        }
        uint32_t header = *(uint32_t *)block_addrv;
        uint32_t block_size = getBlockSize(header);
        uint32_t allocated = getAllocated(header);

        if (allocated || block_size < request_size) {
            block_addrv += block_size;
            continue;
        }

        // 如果剩余块不小于16B，将块进行分割；
        // 否则将块全部分配给用户
        uint32_t remain_size = block_size - request_size;
        if (remain_size >= 16) {
            uint64_t next_block_addrv = block_addrv + request_size;
            setBlockSize(block_addrv, request_size);
            setAllocated(block_addrv, request_size);
            setBlockSize(next_block_addrv, remain_size);
        } else {
            setAllocated(block_addrv, block_size);
        }

        return (void *)(block_addrv + 4);
    }

    return NULL;
}

// 如果释放完内存块后，尾部连续的空闲大小超过1页（4KB），
// 则应该按页位单位释放一部分堆内存，暂未实现。。
void memFree(void *ptr) {
    if (ptr == NULL) return;

    uint64_t addrv = (uint64_t)(ptr - 4);
    uint32_t header = *(uint32_t *)addrv;
    if (!getAllocated(header)) {
        write(STDERR_FILENO, "free twice\n", 15);
        exit(EXIT_FAILURE);
    }
    
    uint32_t next_allocated = 1;
    uint32_t next_size = 0;
    uint32_t prev_allocated = 1;
    uint32_t prev_size = 0;

    uint32_t size = getBlockSize(header);
    uint64_t next_addrv = addrv + size;

    if (next_addrv < heap_end) {
        uint32_t next_header = *(uint32_t *)(next_addrv);
        next_allocated = getAllocated(next_header);
        next_size = getBlockSize(next_header);
    }

    if (addrv > heap_start) {
        uint32_t prev_footer =  *(uint32_t*)(addrv - 4);
        prev_allocated = getAllocated(prev_footer);
        prev_size = getBlockSize(prev_footer);
    }

    // 释放的的起始地址和释放大小
    uint32_t free_size = size;
    uint64_t free_addrv = addrv;

    // 如果前一个块为空闲，起始地址为前一个块，加上前一个块大小
    if (!prev_allocated) {
        free_addrv = addrv - prev_size;
        free_size += prev_size;
    }

    // 如果后一个块空闲，加上后一个块大小
    if (!next_allocated) {
        free_size += next_size;
    }
    // printf("addrv = %lx, size = %d\n", free_addrv, free_size);
    setBlockSize(free_addrv, free_size);
}

int main() {
    printf("dummy program break: %p\n", sbrk(0));
    printf("Intial program break: %p\n", sbrk(0));
    int ret = initHeap(4000);
    assert(ret != -1);

    // 堆的起始位置和终止位置
    printf("heap_start = %lx, heap_end = %lx\n", heap_start, heap_end);
    uint64_t block_addrv = heap_start;
    
    memAlloc(8);
    memAlloc(10);
    void *p = memAlloc(100);
    void *q = memAlloc(1000);
    void *r = memAlloc(2000);
    memAlloc(920);
    memAlloc(1000);

    int i = 0;
    while (block_addrv < heap_end) {
        uint32_t header = *(uint32_t *)block_addrv;
        uint32_t block_size = getBlockSize(header);
        uint32_t allocated = getAllocated(header);

        printf("%d:\taddres:%lx, size = %d, allocated = %d\n", i++,
                block_addrv, block_size, allocated);

        block_addrv += block_size;
    }

    printf("=======================================\n");
    memFree(p);
    memFree(q);
    memFree(r);
    i = 0;
    block_addrv = heap_start;
    while (block_addrv < heap_end) {
        uint32_t header = *(uint32_t *)block_addrv;
        uint32_t block_size = getBlockSize(header);
        uint32_t allocated = getAllocated(header);

        printf("%d:\taddres:%lx, size = %d, allocated = %d\n", i++,
                block_addrv, block_size, allocated);

        block_addrv += block_size;
    }
    printf("heap_start = %lx, heap_end = %lx\n", heap_start, heap_end);
    return 0;
}
