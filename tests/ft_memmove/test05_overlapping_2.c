#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

void __real_free(void *ptr);
void __wrap_free(void *ptr)
{
	__real_free(ptr);
}
int main(void)
{
	
	char *bytes = strdup("123456789");

	ft_memmove(bytes + 3, bytes, 5);
	for (int i = 0; i < 10; i++)
		if (bytes[i])
			printf("%c ", bytes[i]);
		else
			printf("\\0 ");
	free(bytes);
}