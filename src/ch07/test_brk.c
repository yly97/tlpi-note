#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Initial program break:      %p\n", sbrk(0));
    
    printf("Program break is now:       %p\n", sbrk(0));

    printf("Program break is now:       %p\n", sbrk(0));

    printf("Program break is now:       %p\n", sbrk(0));

    printf("Program break is now:       %p\n", sbrk(0));
}