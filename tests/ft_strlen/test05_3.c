#define TESTED_STRING "012"

#include <stdio.h>

int ft_strlen(char *str);

int main(void) {
	printf("ft_strlen(\"%s\") = %d\n", TESTED_STRING, ft_strlen(TESTED_STRING));
	return (0);
}