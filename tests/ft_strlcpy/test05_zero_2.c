#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int main(void)
{
	char	dst[10] = {1, 1, 0, 1, 1, 1, 1, 1, 1, 0};
	char	src[10] = {5, 5, 5, 0, 0, 0, 0, 0, 0, 0};

	printf("strlcpy returned %ld\n", ft_strlcpy(dst, src, 0));
	for (int i = 0; i < 10; i++)
		printf("%d ", dst[i]);
}