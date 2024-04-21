#include <stdio.h>
#include <limits.h>

int ft_isalnum(int c);

int main(void) {
	for (int i = -255; i <= 255; i++) {
		printf("isalnum(%d) returned %d\n", i, ft_isalnum(i) > 0);
	}
	return (0);
}