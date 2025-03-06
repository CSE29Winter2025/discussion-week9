#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

    // take input from the user
    char buf[50];
    
    while (1) {

        printf("YSH> ");
        fgets(buf, sizeof(buf), stdin);


      
        // parse the input into a valid parameter for execvp
        // "ls -a hello\n" ----> ["ls", "-a", "hello", NULL]
        // strtok
        char *exec_args[100];
        int i = 0;
        char * token = strtok(buf, " \n");

        while(token) {

            exec_args[i] = token;
            i++;
            token = strtok(NULL, " \n");

        }

        // explicitly set exec_args at i to NULL
        exec_args[i] = NULL;
        
        // fork a new process that runs the user-input command
        int ret = (int) fork();
        
        if (ret == 0) {
            execvp(exec_args[0], exec_args);
        } else if (ret > 0) {
            wait(NULL);
        } else {
            return 1;
        }



        // run execvp to run the command

        printf("All done with this command!\n");
   }

}
