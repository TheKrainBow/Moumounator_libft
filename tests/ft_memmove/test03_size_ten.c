#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

int main(void)
{
	char	bytes[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
	char	src[10] = {42, 43, 44};

	ft_memmove(bytes, src, 10);
	for (int i = 0; i < 10; i++)
		if (bytes[i])
			printf("%c ", bytes[i]);
		else
			printf("\\0 ");
}
