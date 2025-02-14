#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

#define TESTED_STRING ""

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

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

char	display_index(unsigned int index, char s)
{
	if (s == 'i')
	{
		printf("%d\n", index);
		return '0';
	}
	return s;
}

int main(void)
{
	printf("Calling strmapi with null\n");
	char *output = ft_strmapi(NULL, &display_index);
	if (output == NULL)
	{
		printf("mapi returned NULL");
		return 1;
	}
	printf("string after  mapi: \"%s\"\n", output);
	free(output);
}