#include <stdio.h>
#define TESTED_STRING "42"

void	ft_bzero(void *s, size_t n);

int main(void)
{
	int	bytes[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

	ft_bzero(bytes, 1);
	for (int i = 0; i < 10; i++)
		printf("%d ", bytes[i]);
}