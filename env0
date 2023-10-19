#include "shell.h"

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        // Display the prompt
        printf("simple_shell$ ");
        
        // Read the user's command
        if (fgets(command, sizeof(command), stdin) == NULL) {
            if (feof(stdin)) {
                // End of file condition (Ctrl+D)
                printf("\n");
                break;
            } else {
                // Handle other errors
                perror("Error reading command");
                exit(EXIT_FAILURE);
            }
        }

        // Remove the trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Fork a child process
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            if (execlp(command, command, (char *)NULL) < 0) {
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

    return 0;
}
