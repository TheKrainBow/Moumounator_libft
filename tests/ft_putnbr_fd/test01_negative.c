#define TESTED_NUMBER -42

#include <stdio.h>

void ft_putnbr_fd(int n, int fd);

int main(void) {
	ft_putnbr_fd(TESTED_NUMBER, 1);
	return (0);
}