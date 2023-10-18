#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100

// Function to split a string into an array of tokens
void tokenizeInput(char *input, char **args) {
    char *token = strtok(input, " \t\n");
    int i = 0;

    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, " \t\n");
        i++;
    }
    args[i] = NULL;
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];

    while (1) {
        printf("SimpleShell > ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Remove the newline character
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the shell.\n");
            break;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) { // Child process
            tokenizeInput(input, args);
            if (execvp(args[0], args) == -1) {
                perror("Command not found");
                exit(1);
            }
        } else { // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
