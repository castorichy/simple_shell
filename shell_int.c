#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes*/
int createProcess(char *buffer);


/**
 * funCalls - calls all functions necessary
 * @buffer: the buffer
*/
void funCalls(char *buffer)
{
	createProcess(buffer);
}


/**
 * main - main function
 *
 * Return: 0
 */

int main(void)
{
	int err;
	char *buffer;
	size_t  buffersize = 50;


	while (1)
	{
		buffer = malloc(sizeof(char) * buffersize);
		if (!buffer)
		{
			free(buffer);
			perror("malloc");
			exit(1);
		}
		printf("#hsh~$ ");

		err = getline(&buffer, &buffersize, stdin);
		if (err == -1)
		{
			if (feof(stdin))
				exit(EXIT_FAILURE);
			free(buffer);
			perror("feof");
		}
		funCalls(buffer);
		}
	return (err);
	free(buffer);
}


/**
 * createProcess - create process using fork
 * @buffer: buffer
 *
 * Return: 0
*/
int createProcess(char *buffer)
{
	int i = 0, j = 0, pid, status;
	size_t  buffersize = 50;
	char *str, *cmd[2];
	/*char *env[] = {"HOME=/home/castorichy", (char *)0};*/

	if (buffer != NULL)
	{
		str = malloc(sizeof(char) * buffersize);
		while (buffer[i] != '\0' && buffer[i] != '\n')
		{
			str[j] = buffer[i];
			i++;
			j++;
		}
		str[j] = '\0';
		cmd[0] = str;
		cmd[1] = NULL;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* child */
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);

		}
	}
	else
	{
		/* parent */
		waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	return (0);
	free(str);
	free(buffer)
}


/**
 * 
*/


