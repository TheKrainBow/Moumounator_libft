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
	(void)size;
    return NULL;
}

void __wrap_free(void *ptr)
{
	(void)ptr;
}

char	*ft_itoa(int str);

int main(void)
{
	char	*dest = ft_itoa(42);
	if (dest == NULL)
	{
		printf("calloc returned NULL\n");
		return 1;
	}
	strcpy(dest, "test");
	printf("%s\n", dest);
	free(dest);
}