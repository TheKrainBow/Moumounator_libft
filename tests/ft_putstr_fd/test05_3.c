#define TESTED_STRING "012"

#include <stdio.h>

int ft_putstr_fd(char *str, int fd);

int main(void) {
	ft_putstr_fd(TESTED_STRING, 1);
	return (0);
}