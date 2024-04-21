#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int main(void)
{
	char	dst[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
	char	src[10] = {5, 5, 5, 0, 0, 0, 0, 0, 0, 0};

	printf("strlcat returned %ld\n", ft_strlcat(dst, src, 4));
	for (int i = 0; i < 10; i++)
		printf("%d ", dst[i]);
}