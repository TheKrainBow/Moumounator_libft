#define TESTED_STRING "Bien jouer, tu sais écrire!"

#include <stdio.h>

int ft_putstr_fd(char *str, int fd);

int main(void) {
	ft_putstr_fd(TESTED_STRING, 1);
	return (0);
}