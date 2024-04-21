#include <stdio.h>
#include <limits.h>

#define TESTED_STRING1 "Trouverez vous Charly dans cette phrase? Attention, le second Charly est un piège!"
#define TESTED_STRING2 "Charly"
#define TESTED_SIZE 83

char	*ft_strnstr(const char *big, const char *little, size_t n);

int main(void) {
	printf("strnstr(%s, %s, %d) returned \"%s\"\n", TESTED_STRING1, TESTED_STRING2, TESTED_SIZE, ft_strnstr(TESTED_STRING1, TESTED_STRING2, TESTED_SIZE));
	return (0);
}