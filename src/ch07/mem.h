#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

void *memAlloc(uint32_t size);
void memFree(void *ptr);

#ifdef __cplusplus
}
#endif