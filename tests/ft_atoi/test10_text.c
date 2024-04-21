#include <stdio.h>
#define TESTED_STRING "forty-two"

int	ft_atoi(char *str);

int main(void)
{
	printf("\"%s\" returned %d\n", TESTED_STRING, ft_atoi(TESTED_STRING));
}