# my_malloc

A simple implementation of C dynamic memory management functions using [sbrk](https://linux.die.net/man/2/sbrk).

The allocated chunks are page and size aligned for performance reasons.

The implemented function are :

```c
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
```

## Build

To build the project you can use the following command :

```
make                build the project
make re             clean and rebuild the project
make clean          clean object files
make fclean         clean object files and shared library
```

The result of the build is and shared library file named `libmy_malloc.so`.
