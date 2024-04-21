#include <stdio.h>
#include <limits.h>

int ft_isalpha(int c);

int main(void) {
	for (int i = -255; i <= 255; i++) {
		printf("isalpha(%d) returned %d\n", i, ft_isalpha(i) > 0);
	}
	return (0);
}