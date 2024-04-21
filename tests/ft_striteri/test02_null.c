#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	printf("Calling striteri with null\n");
	ft_striteri(NULL, &display_index);
}