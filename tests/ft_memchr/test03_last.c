#include <stdlib.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n);

int main(void)
{
    char    *test = "a b c";
	char	*dest = ft_memchr(test, 'c', 5 * sizeof(char));
	if (dest == NULL)
	{
		printf("memchr returned NULL\n");
		return 1;
	}
    printf("memchr(\"%s\", '%c', %d) returned %s\n", test, 'c', 4, dest);
}