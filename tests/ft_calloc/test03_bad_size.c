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

void	test_calloc(int nmemb, int size)
{
	char	*dest = ft_calloc(nmemb, size);
	if (dest == NULL)
	{
		printf("calloc returned NULL\n");
		return ;
	}
	printf("calloc(%d, %d) allocated %ld bytes\n", nmemb, size, allocated_size(dest));
	free(dest);
}

int main(void)
{
	test_calloc(0, 4);
	test_calloc(4, 0);
	test_calloc(0, 0);
}