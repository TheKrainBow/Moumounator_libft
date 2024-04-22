#include <stdio.h>
#include <unistd.h>

void ft_putchar_fd(int n, int fd);

int main(void) {
	for (int i = -255; i <= 255; i++)
	{
		ft_putchar_fd(i, 1);
		write(1, " ", 1);
	}
	return (0);
}
