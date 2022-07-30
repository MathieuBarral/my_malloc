#include "my_malloc.h"

mem_chunk_t **get_list_head(void)
{
    static mem_chunk_t *head = NULL;

    return (&head);
}

size_t *get_tot_size(void)
{
    static size_t tot_size = 0;

    return (&tot_size);
}

size_t *get_used_tot_size(void)
{
    static size_t used_tot_size = 0;

    return (&used_tot_size);
}

void *get_new_ptr(mem_chunk_t **head)
{
    mem_chunk_t *tmp_chunk = *head;

    for (; tmp_chunk->next; tmp_chunk = tmp_chunk->next);
    return (tmp_chunk->ptr + tmp_chunk->size);
}