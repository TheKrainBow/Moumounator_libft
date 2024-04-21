#define TESTED_NUMBER 0

#include <stdio.h>

void ft_putchar_fd(char c, int fd);

int main(void) {
	ft_putchar_fd(TESTED_NUMBER, 1);
	return (0);
}