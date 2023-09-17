#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

void *mmalloc(uint32_t size);
void mfree(void *ptr);

#ifdef __cplusplus
}
#endif