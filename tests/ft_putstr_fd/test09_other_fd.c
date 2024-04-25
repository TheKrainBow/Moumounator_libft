#define TESTED_STRING "Well done, you can write in a file"
#define FILE_PATH "SomeFileToWriteIn"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void ft_putstr_fd(char *s, int fd);

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

	ft_putstr_fd(TESTED_STRING, fd);

	close(fd);

	read_file();
	return (0);
}