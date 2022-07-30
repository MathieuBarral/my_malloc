#include "my_malloc.h"

size_t get_new_size(size_t size)
{
    size_t new_size = 2;

    for (; new_size < size; new_size *= 2);
    return (new_size);
}

size_t check_tot_size(size_t size)
{
    size_t new_size = 0;
    size_t *tot_size = get_tot_size();
    size_t *used_size = get_used_tot_size();
    size_t page_size = getpagesize() * 2;

    if (((*tot_size) - (*used_size)) < (size + sizeof(mem_chunk_t))) {
        for (; (size + sizeof(mem_chunk_t)) > new_size; new_size += page_size);
        (*tot_size) += new_size;
        (*used_size) += (size + sizeof(mem_chunk_t));
        return (new_size);
    }
    (*used_size) += (size + sizeof(mem_chunk_t));
    return (0);
}

void *malloc(size_t size)
{
    mem_chunk_t **head = get_list_head();
    mem_chunk_t *tmp = NULL;
    size_t new_size = 0;

    if (size <= 0)
        return (NULL);
    size = get_new_size(size);
    if ((tmp = check_free_mem(head, size)))
        return (tmp + 1);
    new_size = check_tot_size(size);
    if ((tmp = alloc_new_mem(head, size, new_size)))
        return (tmp + 1);
    tmp = alloc_chunk(head, size, get_new_ptr(head));
    return (tmp + 1);
}