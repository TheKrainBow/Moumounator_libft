#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

void *__wrap_malloc(size_t size)
{
	(void)size;
    return NULL;
}

void __wrap_free(void *ptr)
{
	(void)ptr;
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
	char	*dest = ft_calloc(1, 1);
	if (dest == NULL)
	{
		printf("calloc returned NULL\n");
		return 1;
	}
	printf("calloc allocated %ld bytes\n", allocated_size(dest));
	free(dest);
}