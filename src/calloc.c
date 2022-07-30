#include "my_malloc.h"

void my_memset(void *dst, char fill, size_t size)
{
    char *tmp = (char *) dst;

    for (size_t index = 0; index < size; index++)
        tmp[index] = fill;
}

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(size * nmemb);

    my_memset(ptr, '\0', size * nmemb);
    return (ptr);
}