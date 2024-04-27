#include <stdlib.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int main(void)
{
    char    *test = "";
	char	*dest = ft_strrchr(test, 0);
	if (dest == NULL)
	{
		printf("memchr returned NULL\n");
		return 1;
	}
    printf("strrchr(\"%s\", '%d') returned %s\n", test, 0, dest);
}