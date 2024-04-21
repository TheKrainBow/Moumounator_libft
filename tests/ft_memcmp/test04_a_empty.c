#include <stdlib.h>
#include <stdio.h>

#define TESTED_STRING1 ""
#define TESTED_STRING2 "abcde"
#define TESTED_SIZE 5

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	test_cmp(const void *s1, const void *s2, size_t n)
{
	int		cmp_return = ft_memcmp(s1, s2, n);

	if (cmp_return > 0)
		printf("memcmp(\"%s\", \"%s\", %d) returned a positive value\n", TESTED_STRING1, TESTED_STRING2, TESTED_SIZE);
	else if (cmp_return < 0)
		printf("memcmp(\"%s\", \"%s\", %d) returned a negative value\n", TESTED_STRING1, TESTED_STRING2, TESTED_SIZE);
	else
		printf("memcmp(\"%s\", \"%s\", %d) returned zero\n", TESTED_STRING1, TESTED_STRING2, TESTED_SIZE);

}

int main(void)
{
	for (int i = 0; i <= 5; i++)
		test_cmp(TESTED_STRING1, TESTED_STRING2, i);
}