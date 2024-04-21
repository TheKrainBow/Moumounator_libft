#define TESTED_STRING "This is an example string"
#define TESTED_START 0
#define TESTED_LEN 50

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

char	*ft_substr(const char *s, unsigned int start, size_t len);

int main(void)
{
	char	*dest = ft_substr(TESTED_STRING, TESTED_START, TESTED_LEN);
	if (dest == NULL)
	{
		printf("substr returned NULL\n");
		return 1;
	}
	printf("substr(\"%s\", %d, %d) returned \"%s\" allocated a of %ld bytes\n", TESTED_STRING, TESTED_START, TESTED_LEN, dest, allocated_size(dest));
	free(dest);
}