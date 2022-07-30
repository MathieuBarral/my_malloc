#include "my_malloc.h"

void chunkcpy(void *src, void *dst, size_t size)
{
    mem_chunk_t *chunk_src = find_chunk(src);
    mem_chunk_t *chunk_dst = find_chunk(dst);
    char *tmp_src = (char *) chunk_src->ptr;
    char *tmp_dst = (char *) chunk_dst->ptr;

    for (size_t index = 0; index < size; index++)
        tmp_dst[index] = tmp_src[index];
}