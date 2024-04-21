#define TESTED_STRING "Je suis un split simple"
#define TESTED_SEP ' '

#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
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

char	**ft_split(char const *s, char c);

int main(void)
{
	char	**dest = ft_split(TESTED_STRING, TESTED_SEP);
	if (dest == NULL)
	{
		printf("split returned NULL\n");
		return 1;
	}
	printf("split(\"%s\") allocated an array of %ld strings\n", TESTED_STRING, allocated_size(dest));
	for (int i = 0; dest[i]; i++)
	{
		printf(" -> dest[%d] = \"%s\" allocated %ld\n", i, dest[i], allocated_size(dest[i]));
		free(dest[i]);
	}
	free(dest);
}