#include <stdlib.h>
#include <stdio.h>

#define TESTED_STRING1 ""
#define TESTED_STRING2 ""
#define TESTED_SIZE 5

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	test_cmp(const void *s1, const void *s2, size_t n)
{
	int		cmp_return = ft_memcmp(s1, s2, n);

	if (cmp_return > 0)
		printf("memcmp(\"%s\", \"%s\", %zu) returned a positive value\n", (char *)s1, (char *)s2, n);
	else if (cmp_return < 0)
		printf("memcmp(\"%s\", \"%s\", %zu) returned a negative value\n", (char *)s1, (char *)s2, n);
	else
		printf("memcmp(\"%s\", \"%s\", %zu) returned zero\n", (char *)s1, (char *)s2, n);

}

int main(void)
{
	for (int i = 0; i <= 5; i++)
		test_cmp(TESTED_STRING1, TESTED_STRING2, i);
}
