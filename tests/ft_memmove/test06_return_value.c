#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

int main(void)
{
	char	bytes[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
	char	src[10] = {42, 43, 44};
	void	*ptr;

	ptr = ft_memmove(bytes, src, 3 * sizeof(char));
	printf("Return value address == input? %d", ptr == bytes);
}
