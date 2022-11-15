#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define buf 1084
/**
 * main - main function
 * @argc: number of arguments
 * @argv: command line arguments
 *
 * Return: 0 on success
*/

int main(int argc, char *argv[])
{
	int fd, wfd, rfd;
	char *buffer = malloc(buf);

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s file name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	printf("%d", fd);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error opening %s\n", argv[1]);
	}

	rfd = read(fd, buffer, buf);
	if (rfd == -1)
	{
		dprintf(STDERR_FILENO, "Error reading %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	wfd = write(STDOUT_FILENO, buffer, rfd);
	if (wfd != rfd)
	{
		dprintf(STDERR_FILENO, "Error writing %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (0);
	free(buffer);

}
