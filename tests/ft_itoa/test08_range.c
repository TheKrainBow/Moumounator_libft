#include <stdio.h>
#include <string.h>
#define TESTED_STRING "42"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

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

void test_itoa(int n)
{
	char	*dest = ft_itoa(n);
	if (dest == NULL)
	{
		printf("itoa returned NULL\n");
		return ;
	}
	printf("itoa(%d) returned \"%s\" and allocated %ld bytes\n", n, dest, allocated_size(dest));
	free(dest);
}

int main(void)
{
	for (int i = -200; i < 200; i++)
		test_itoa(i);
}