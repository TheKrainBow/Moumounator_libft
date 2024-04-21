#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

int main(void)
{
	
	char *bytes = strdup("123456789");

	ft_memmove(bytes + 3, bytes, 5);
	for (int i = 0; i < 10; i++)
		printf("%d ", bytes[i]);
}