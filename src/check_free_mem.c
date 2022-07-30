#include "my_malloc.h"

void split_chunk(mem_chunk_t *chunk, size_t size)
{
    mem_chunk_t *new_chunk = chunk->ptr + size;

    new_chunk->size = chunk->size - (size + sizeof(mem_chunk_t));
    new_chunk->is_free = 1;
    new_chunk->ptr = (void *)(new_chunk + 1);
    new_chunk->next = chunk->next;
    new_chunk->prev = chunk;
    if (chunk->next)
        chunk->next->prev = new_chunk;
    chunk->size = size;
    chunk->is_free = 0;
    chunk->next = new_chunk;
}

mem_chunk_t *check_free_chunk(mem_chunk_t **head, size_t size)
{
    mem_chunk_t *tmp = *head;

    for (; tmp; tmp = tmp->next) {
        if (tmp->is_free && tmp->size >= (size + sizeof(mem_chunk_t)))
            return (tmp);
    }
    return (tmp);
}

mem_chunk_t *check_free_mem(mem_chunk_t **head, size_t size)
{
    mem_chunk_t *tmp = check_free_chunk(head, size);

    if (tmp && tmp->size > (size + sizeof(mem_chunk_t))) {
        split_chunk(tmp, size);
        return (tmp);
    } else if (tmp && tmp->size == size) {
        tmp->is_free = 0;
        return (tmp);
    }
    return (NULL);
}