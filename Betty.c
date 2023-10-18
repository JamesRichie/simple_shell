#include "shell.h"

int is_snake_case(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            return 0; // Not snake_case, contains spaces or tabs.
        }
    }
    return 1; // Snake_case.
}

int is_valid_identifier(const char *str) {
    int len = strlen(str);
    
    if (str[0] >= '0' && str[0] <= '9') {
        return 0; // Identifier cannot start with a digit.
    }

    for (int i = 0; i < len; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] == '_')) {
            return 0; // Invalid character in the identifier.
        }
    }
    
    return 1; // Valid identifier.
}

int main() {
    char function_name[] = "my_function_name";
    char variable_name[] = "myVariableName";
    char identifier1[] = "123identifier";
    char identifier2[] = "good_identifier";
    
    if (is_snake_case(function_name)) {
        printf("Function name follows snake_case.\n");
    } else {
        printf("Function name does not follow snake_case.\n");
    }
    
    if (is_snake_case(variable_name)) {
        printf("Variable name follows snake_case.\n");
    } else {
        printf("Variable name does not follow snake_case.\n");
    }
    
    if (is_valid_identifier(identifier1)) {
        printf("Identifier 1 is a valid identifier.\n");
    } else {
        printf("Identifier 1 is not a valid identifier.\n");
    }
    
    if (is_valid_identifier(identifier2)) {
        printf("Identifier 2 is a valid identifier.\n");
    } else {
        printf("Identifier 2 is not a valid identifier.\n");
    }
    
    return 0;
}
