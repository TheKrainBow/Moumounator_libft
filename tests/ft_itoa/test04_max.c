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

char	*ft_itoa(int str);

int main(void)
{
	char	*dest = ft_itoa(INT_MAX);
	if (dest == NULL)
	{
		printf("itoa returned NULL\n");
		return 1;
	}
	printf("itoa(%d) returned \"%s\" and allocated %ld bytes\n", INT_MAX, dest, allocated_size(dest));
	free(dest);
}