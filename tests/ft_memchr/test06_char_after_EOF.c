#include <stdlib.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n);

int main(void)
{
    char    test[10] = {1, 1, 1, 0, 4, 1, 1, 1};
	char	*dest = ft_memchr(test, 4, 7);
	if (dest == NULL)
	{
		printf("memchr returned NULL\n");
		return 1;
	}
    printf("memchr(\"%s\", '%d', %d) returned %s\n", test, 4, 7, dest);
}