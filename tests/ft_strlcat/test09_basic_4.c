#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int main(void)
{
	char	dst[30];
	char	*src = "AAAAAAAAA";

	memset(dst, 0, 30);
	memset(dst, 'X', 4);
	printf("strlcat returned %ld\n", ft_strlcat(dst, src, 3));
	printf("strlcat returned %ld\n", ft_strlcat(dst, src, 6));
	for (int i = 0; i < 30; i++)
		if (dst[i])
			printf("%c", dst[i]);
		else
			printf("?");
}