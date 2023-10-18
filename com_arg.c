#include "shell.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main() {
    char input[MAX_COMMAND_LENGTH];
    
    while (1) {
        // Display the prompt
        printf("simple_shell$ ");
        
        // Read the user's input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            if (feof(stdin)) {
                // End of file condition (Ctrl+D)
                printf("\n");
                break;
            } else {
                perror("Error reading input");
                exit(EXIT_FAILURE);
            }
        }

        // Remove the trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Split the input into command and arguments
        char* args[MAX_ARGUMENTS];
        int arg_count = 0;
        char* token = strtok(input, " ");
        while (token != NULL && arg_count < MAX_ARGUMENTS) {
            args[arg_count] = token;
            token = strtok(NULL, " ");
            arg_count++;
        }
        args[arg_count] = NULL;

        if (arg_count > 0) {
            // Fork a child process
            pid_t pid = fork();
            if (pid < 0) {
                perror("Fork failed");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                // Child process
                if (execvp(args[0], args) < 0) {
                    // If execution fails, print an error message
                    perror("Command not found");
                    exit(EXIT_FAILURE);
                }
            } else {
                // Parent process
                int status;
                wait(&status); // Wait for the child process to finish
                if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                    printf("Command failed with error code %d\n", WEXITSTATUS(status));
                }
            }
        }
    }

    return 0;
}
