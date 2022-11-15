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
char **acceptArgv(const char *argv);


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
	int pid, status;
	size_t  buffersize = 50;
	char *str;
	char **brokenToken = malloc(sizeof(char *) * buffersize);

	brokenToken = acceptArgv(buffer);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* child */
		if (execvp(brokenToken[0], brokenToken) == -1)
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
	free(buffer);
}


/**
 * acceptArgv - accept arguments and removes delimiter characters
 * @argv: argument in one string
 *
 * Return: argument list
*/

char **acceptArgv(const char *argv)
{
	int j = 0;
	char *buffer = strdup(argv);
	size_t  buffersize = 50;
	char *token, **buff_token;

	if (!buffer)
	{
		return (NULL);
	}

	buff_token = malloc(sizeof(char) * buffersize);
	token = malloc(sizeof(char) * buffersize);
	if (!token)
	{
		return (NULL);
	}

	token = strtok(buffer, " \t\r\n\a");
	while (token != NULL)
	{
		buff_token[j++] = token;
		token++;
		token = strtok(NULL, " \t\r\n\a");
	}
	buff_token[j] = NULL;

	return (buff_token);
	free(buffer);
	free(token);
}
