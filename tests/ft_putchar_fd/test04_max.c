#include <limits.h>
#include <stdio.h>

void ft_putchar_fd(char c, int fd);

int main(void) {
	ft_putchar_fd(CHAR_MAX, 1);
	return (0);
}