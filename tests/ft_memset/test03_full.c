#include <stdio.h>

void	*ft_memset(void *dest, int c, size_t n);

int main(void)
{
	char	bytes[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

	ft_memset(bytes, 0, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", bytes[i]);
}