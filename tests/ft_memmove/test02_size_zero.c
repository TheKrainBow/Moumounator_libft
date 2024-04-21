#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

int main(void)
{
	char	bytes[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
	char	src[10] = {42, 43, 44};

	ft_memcpy(bytes, src, 0);
	for (int i = 0; i < 10; i++)
		printf("%d ", bytes[i]);
}