#include <stdio.h>
#include <unistd.h>

void ft_putnbr_fd(int n, int fd);

int main(void) {
	for (int i = -255; i <= 255; i++)
	{
		ft_putnbr_fd(i, 1);
		write(1, " ", 1);
	}
	return (0);
}