#include <stdlib.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n);

int main(void)
{
    char    *test = "a b c";
	char	*dest = ft_memchr(test, 12345, 4);
	if (dest == NULL)
	{
		printf("memchr returned NULL\n");
		return 1;
	}
    printf("memchr(\"%s\", '%d', %d) returned %s\n", test, 12345, 4, dest);
}