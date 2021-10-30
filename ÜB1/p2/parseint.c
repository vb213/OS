#include "parseint.h"
#include <stdio.h> //remove

//remove
int main() {
    int num = parseInt("987");
    int err = parseInt("jjj");

    printf("%d %d", num, err);

    return 0;
}

/*
 * Returns the value of c or -1 on error
 */
int parseDecimalChar(char c)
{
    if(c >= 48 && c <= 57) {
        return c - 48;
    }

    return -1;
}

/*
 * Parses a non-negative integer, interpreted as octal when starting with 0,
 * decimal otherwise. Returns -1 on error.
 */
int parseInt(char *string)
{
    
    while (*string != 0)
    {
        printf("%c\n", parseDecimalChar(*string));
        string++;
    }
    

    return -1;
}
