#include <unistd.h>
#include <stdio.h>

void ft_putnbr_fd(int n, int fd);

int main(void) {
	for (int i = -100; i <= 100; i++)
	{
		ft_putnbr_fd(i, 1);
		write(1, "\n", 1);
	}
	return (0);
}
