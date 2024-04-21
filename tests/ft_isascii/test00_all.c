#include <stdio.h>
#include <limits.h>

int ft_isascii(int c);

int main(void) {
	for (int i = -255; i <= 255; i++) {
		printf("isascii(%d) returned %d\n", i, ft_isascii(i) > 0);
	}
	return (0);
}