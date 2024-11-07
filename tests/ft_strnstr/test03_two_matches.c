#include <limits.h>
#include <stdio.h>
#include <string.h>

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = strlen(needle);
	if (needle_len > len)
	{
		return (NULL);
	}
	for (size_t i = 0; i <= len - needle_len; i++)
	{
		if (strncmp(haystack + i, needle, needle_len) == 0)
		{
			return (char *)(haystack + i);
		}
	}
	return (NULL);
}

#define TESTED_STRING1 "Trouverez vous Charly dans cette phrase? Attention, le second Charly est un piège!"
#define TESTED_STRING2 "Charly"
#define TESTED_SIZE 83

char	*ft_strnstr(const char *big, const char *little, size_t n);

int	main(void)
{
	printf("strnstr(%s, %s, %d) returned \"%s\"\n", TESTED_STRING1,
		TESTED_STRING2, TESTED_SIZE, ft_strnstr(TESTED_STRING1, TESTED_STRING2,
			TESTED_SIZE));
	return (0);
}