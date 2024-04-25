#define TESTED_STRING "01"

#include <stdio.h>

void ft_putendl_fd(char *str, int fd);

int main(void) {
	ft_putendl_fd(TESTED_STRING, 1);
	return (0);
}
