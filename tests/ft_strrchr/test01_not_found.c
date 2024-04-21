#include <stdlib.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int main(void)
{
	char	*test = "b c d";
	char	*dest = ft_strrchr(test, 'a');
	if (dest == NULL)
	{
		printf("strrchr returned NULL\n");
		return 1;
	}
    printf("strrchr(\"%s\", '%c') returned %s\n", test, 'a', dest);
}