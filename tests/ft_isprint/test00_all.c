#include <stdio.h>
#include <limits.h>

int ft_isprint(int c);

int main(void) {
	for (int i = -255; i <= 255; i++) {
		printf("isprint(%d) returned %d\n", i, ft_isprint(i) > 0);
	}
	return (0);
}