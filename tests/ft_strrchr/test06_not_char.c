#include <stdlib.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int main(void)
{
    char    *test = "a b c";
	char	*dest = ft_strrchr(test, 12345);
	if (dest == NULL)
	{
		printf("memchr returned NULL\n");
		return 1;
	}
    printf("strrchr(\"%s\", '%d') returned %s\n", test, 12345, dest);
}