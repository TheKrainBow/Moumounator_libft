#include <stdlib.h>
#include <stdio.h>

#define TESTED_STRING1 "abcde"
#define TESTED_STRING2 "abcd"
#define TESTED_SIZE 5

int		ft_strncmp(const void *s1, const void *s2, size_t n);

void	test_cmp(const void *s1, const void *s2, size_t n)
{
	int		cmp_return = ft_strncmp(s1, s2, n);

	if (cmp_return > 0)
		printf("strncmp(\"%s\", \"%s\", %zu) returned a positive value\n", (char *)s1, (char *)s2, n);
	else if (cmp_return < 0)
		printf("strncmp(\"%s\", \"%s\", %zu) returned a negative value\n", (char *)s1, (char *)s2, n);
	else
		printf("strncmp(\"%s\", \"%s\", %zu) returned zero\n", (char *)s1, (char *)s2, n);

}

int main(void)
{
	test_cmp(TESTED_STRING1, TESTED_STRING2, TESTED_SIZE);
}
