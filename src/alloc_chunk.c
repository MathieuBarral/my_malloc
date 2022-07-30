#include "my_malloc.h"

void init_chunk(mem_chunk_t **new_chunk, size_t size)
{
    (*new_chunk)->ptr = (void *)((*new_chunk) + 1);
    (*new_chunk)->size = size;
    (*new_chunk)->is_free = 0;
    (*new_chunk)->prev = NULL;
    (*new_chunk)->next = NULL;
}

mem_chunk_t *alloc_chunk(mem_chunk_t **head, size_t size, void *new_pos)
{
    mem_chunk_t *tmp = *head;
    mem_chunk_t *new_chunk = new_pos;

    if (size <= 0)
        return (NULL);
    init_chunk(&new_chunk, size);
    if (!(*head))
        *head = new_chunk;
    else {
        for (; tmp->next; tmp = tmp->next);
        new_chunk->prev = tmp;
        tmp->next = new_chunk;
    }
    return (new_chunk);
}