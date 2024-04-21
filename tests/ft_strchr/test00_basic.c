#include <stdlib.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);

int main(void)
{
	char	*test = "a b c";
	char	*dest = ft_strchr(test, 'a');
	if (dest == NULL)
	{
		printf("strchr returned NULL\n");
		return 1;
	}
    printf("strchr(\"%s\", '%c') returned %s\n", test, 'a', dest);
}