#define FILE_PATH "SomeFileToWriteIn"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void ft_putnbr_fd(int n, int fd);


void reset_file()
{
	FILE *fd = fopen(FILE_PATH, "w");
	fclose(fd);
}

void read_file()
{
	FILE *fd = fopen(FILE_PATH, "r");
	char s[50];

	while (EOF != fscanf(fd, "%[^\n]\n", s))
	{
		printf("> %s\n", s);
	}
	fclose(fd);
}

int main(void) {
	reset_file();
	int fd = open(FILE_PATH, O_WRONLY);
	ft_putnbr_fd(42, fd);
	close(fd);
	read_file();
	return (0);
}