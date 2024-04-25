#include <limits.h>
#include <stdio.h>

void ft_putnbr_fd(int n, int fd);

int main(void) {
	ft_putnbr_fd(INT_MAX, 1);
	return (0);
}