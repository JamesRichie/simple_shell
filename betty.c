#include "shell.h"
/**
 * snake_case - stores strings
 * @str: variable
 *
 */

int snake_case(const char *str)
{
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
	{
            return 0;
        }
    }
    return 1;
}

/**
 * valid_id - identifies strings
 * @str: variable
 *
 */

int valid_id(const char *str)
{
    int len = strlen(str);
    int i;

    if (str[0] >= '0' && str[0] <= '9')
    {
        return 0; 
    }

    for (i = 0; i < len; i++)
    {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] == '_')) {
            return 0;
        }
    }
    
    return 1;
}
