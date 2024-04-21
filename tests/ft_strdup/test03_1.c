#define TESTED_STRING "0"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

void *__wrap_malloc(size_t size)
{
    size_t *ptr = __real_malloc(size + sizeof(size_t));
    *ptr = size;
    ptr++;
    return ptr;
}

void __wrap_free(void *ptr)
{
    size_t *p = ptr;
    p--;
    __real_free(p);
}

size_t allocated_size(void *ptr)
{
    size_t *p = ptr;
    p--;
    return (*p);
}

char *ft_strdup(char *str);

int main(void) {
	char	*str = ft_strdup(TESTED_STRING);
	printf("ft_strdup(\"%s\")\n  ->  returned \"%s\"\n  -> allocated %ld bytes\n", TESTED_STRING, str, allocated_size(str));
	free(str);
	return (0);
}