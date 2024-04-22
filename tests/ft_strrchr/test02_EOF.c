#include <stdlib.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int main(void)
{
	char	*test = "a b c";
	char	*dest = ft_strrchr(test, 0);
	if (dest == NULL)
	{
		printf("strrchr returned NULL\n");
		return 1;
	}
    printf("strrchr(\"%s\", '\\0') returned %s\n", test, dest);
}