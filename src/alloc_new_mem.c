#include "my_malloc.h"

mem_chunk_t *alloc_new_mem(mem_chunk_t **head, size_t size, size_t new_size)
{
    mem_chunk_t *tmp = NULL;
    void *p = NULL;

    if (new_size != (size_t) 0) {
        p = sbrk(new_size);
        if (p == (void *) -1)
            return (NULL);
        tmp = alloc_chunk(head, size, (*head) ? get_new_ptr(head) : p);
        return (tmp);
    }
    return (NULL);
}