#include <stdio.h>
#include <limits.h>

int ft_isdigit(int c);

int main(void) {
	for (int i = -255; i <= 255; i++) {
		printf("isdigit(%d) returned %d\n", i, ft_isdigit(i) > 0);
	}
	return (0);
}