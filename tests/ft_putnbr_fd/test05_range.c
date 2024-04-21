#include <unistd.h>
#include <stdio.h>

int ft_putnbr_fd(int n, int fd);

int main(void) {
	for (int i = -100; i <= 100; i++)
	{
		ft_putnbr_fd(i, 1);
		write(1, " ", 1);
	}
	return (0);
}