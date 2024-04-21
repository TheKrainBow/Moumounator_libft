#define TESTED_STRING1 "Nothing to trim"
#define TESTED_STRING2 " 	"

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

char	*ft_strtrim(const char *s1, char const *set);

int main(void)
{
	char	*dest = ft_strtrim(TESTED_STRING1, TESTED_STRING2);
	if (dest == NULL)
	{
		printf("strtrim returned NULL\n");
		return 1;
	}
	printf("strtrim(\"%s\", \"%s\") returned \"%s\" allocated a of %ld bytes\n", TESTED_STRING1, TESTED_STRING2, dest, allocated_size(dest));
	free(dest);
}