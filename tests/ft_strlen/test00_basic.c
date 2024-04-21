#define TESTED_STRING "Bien jouer, tu sais compter!"

#include <stdio.h>

int ft_strlen(char *str);

int main(void) {
	printf("ft_strlen(\"%s\") = %d\n", TESTED_STRING, ft_strlen(TESTED_STRING));
	return (0);
}