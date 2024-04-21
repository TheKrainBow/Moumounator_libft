#include <limits.h>
#include <stdio.h>

void ft_putchar_fd(char c, int fd);

int main(void) {
	ft_putchar_fd(CHAR_MIN, 1);
	return (0);
}