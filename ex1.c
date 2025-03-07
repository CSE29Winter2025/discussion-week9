#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    printf("***main executing.***\n");

    char *ptr;
    char *token;

    char buf[50];

    int max_args = 10;
    char *cmd_argv[max_args];
    
    int i = 0;


    while (1 == 1) 
    {
	// Print prompt
	printf("psh > ");
	
	// Read from STDIN
	fgets(buf, 50, stdin);
	
	ptr = buf;
        i = 0;
	
	// Tokenize buffer
        while ((token = strtok(ptr, " ")) != NULL)
	{
		cmd_argv[i] = token;
		printf("%s\n", cmd_argv[i]);
		ptr = NULL;
		i += 1;
	}
	cmd_argv[i] = NULL;
	cmd_argv[i-1][2] = '\0';

	pid_t pid = fork();

	if (pid == 0) 
	{ 
		//child
    		execvp(cmd_argv[0], cmd_argv);
	}
	else if (pid > 0) 
	{
		wait(NULL);
	}
	else 
	{
		printf("Error on fork() call\n");
		return;
	}
	
    }

    return 0;
}
