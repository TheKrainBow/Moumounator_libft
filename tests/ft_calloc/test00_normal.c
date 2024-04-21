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

void	*ft_calloc(size_t nmemb, size_t size);

int main(void)
{
	char	*dest = ft_calloc(sizeof(char), 5);
	if (dest == NULL)
	{
		printf("calloc returned NULL\n");
		return 1;
	}
	printf("calloc allocated %ld bytes\n", allocated_size(dest));
	free(dest);
}