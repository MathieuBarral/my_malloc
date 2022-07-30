#ifndef MY_MALLOC_H
    #define MY_MALLOC_H

    #include <unistd.h>
    #include <stdint.h>
    #include <sys/types.h>

    // Chunk metadata structure
    typedef struct mem_chunk_s {
        void *ptr;
        size_t size;
        int is_free;
        struct mem_chunk_s *prev;
        struct mem_chunk_s *next;
    } mem_chunk_t;

    /**
     * @brief Allocate new memory chunk of specified size
     *
     * @param size
     *
     * @return void *
     */
    void *malloc(size_t size);

    /**
     * @brief Free memory chunk of specified pointer
     *
     * @param ptr
     *
     * @return none
     */
    void free(void *ptr);

    /**
     * @brief Get memory chunks metadata list head
     *
     * @return mem_chunk_t **
     */
    mem_chunk_t **get_list_head(void);

    /**
     * @brief Allocate memory chunk
     *
     * @param head
     * @param size
     * @param new_pos
     *
     * @return mem_chunk_t *
     */
    mem_chunk_t *alloc_chunk(mem_chunk_t **head, size_t size, void *new_pos);

    /**
     * @brief Find specified memory chunk in list
     *
     * @param ptr
     *
     * @return mem_chunk_t *
     */
    mem_chunk_t *find_chunk(void *ptr);

    /**
     * @brief Check for free memory chunks in list
     *
     * @param head
     * @param size
     *
     * @return mem_chunk_t *
     */
    mem_chunk_t *check_free_mem(mem_chunk_t **head, size_t size);

    /**
     * @brief Allocate new page of memory to fit new chunk
     *
     * @param head
     * @param size
     * @param new_size
     *
     * @return mem_chunk_t *
     */
    mem_chunk_t *alloc_new_mem(mem_chunk_t **head, size_t size, size_t new_size);

    /**
     * @brief Get the total size of allocated memory pages
     *
     * @return size_t *
     */
    size_t *get_tot_size(void);

    /**
     * @brief Get the total size of used memory pages
     *
     * @return size_t *
     */
    size_t *get_used_tot_size(void);

    /**
     * @brief Get pointer for new memory chunk
     *
     * @param head
     *
     * @return void *
     */
    void *get_new_ptr(mem_chunk_t **head);

    /**
     * @brief Copy src chunk metadata content to dst
     *
     * @param src
     * @param dst
     * @param size
     *
     * @return none
     */
    void chunkcpy(void *src, void *dst, size_t size);

    /**
     * @brief Allocate nmemb chunks of specified size
     *
     * @param nmemb
     * @param size
     *
     * @return void *
     */
    void *calloc(size_t nmemb, size_t size);

    /**
     * @brief Reallocate and resize memory chunk of specified pointer
     *
     * @param ptr
     * @param size
     *
     * @return void *
     */
    void *realloc(void *ptr, size_t size);

#endif
