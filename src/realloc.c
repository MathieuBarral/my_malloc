#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *tmp = malloc(size);

    if (!ptr || !tmp)
        return (tmp);
    chunkcpy(ptr, tmp, size);
    free(ptr);
    return (tmp);
}