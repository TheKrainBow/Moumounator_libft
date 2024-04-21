#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TESTED_STRING ""

void __real_free(void *ptr);

void __wrap_free(void *ptr)
{
	__real_free(ptr);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void		display_index(unsigned int index, char *s)
{
	if (*s == 'i')
	{
		printf("%d\n", index);
		*s = '0';
	}
}

int main(void)
{
	char	*input = strdup(TESTED_STRING);
	printf("string before iteri: \"%s\"\n", input);
	ft_striteri(input, &display_index);
	printf("string after  iteri: \"%s\"\n", input);
	free(input);
}