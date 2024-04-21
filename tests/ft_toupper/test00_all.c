#include <stdio.h>
#include <limits.h>

int ft_toupper(int c);

int main(void) {
	for (int i = 0; i <= 127; i++) {
		printf("toupper(%d) returned %d\n", i, ft_toupper(i));
	}
	return (0);
}