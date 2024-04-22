#include <stdlib.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);

int main(void)
{
    char    *test = "a b c";
	char	*dest = ft_strchr(test, 12345);
	if (dest == NULL)
	{
		printf("memchr returned NULL\n");
		return 1;
	}
    printf("strchr(\"%s\", '%d') returned %s\n", test, 12345, dest);
}