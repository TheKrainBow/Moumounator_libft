#include <stdio.h>
#include <limits.h>

int ft_tolower(int c);

int main(void) {
	for (int i = 0; i <= 127; i++) {
		printf("tolower(%d) returned %d\n", i, ft_tolower(i));
	}
	return (0);
}