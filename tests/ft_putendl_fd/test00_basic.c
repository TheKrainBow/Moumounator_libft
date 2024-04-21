#define TESTED_STRING "Bien jouer, tu sais écrire!"

#include <stdio.h>

void ft_putendl_fd(char *str, int fd);

int main(void) {
	ft_putendl_fd(TESTED_STRING, 1);
	return (0);
}