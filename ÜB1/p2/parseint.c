#include "parseint.h"
#include <string.h>
#include <stdio.h> //remove

/*
 * Returns the power of two not negative integers
 */
int powPositivInt(int base, int exp) 
{
    if(base >= 0 && exp >=0) {
        int result = 1;
        
        for (int i = 0; i < exp; i++)
        {
            result *= base;
        }
        
        return result;
    } 
    return -1;
}

//remove
int main() {
    int num = parseInt("987");
    int err = parseInt("jjj");

    printf("%d\n", err);

    printf("%d\n", parseInt("987"));
    printf("%d\n", parseInt("92387"));
    printf("%d\n", parseInt("0023423"));
    printf("%d\n", parseInt("12345"));
    printf("%d\n", parseInt("012345"));
    printf("%d\n", parseInt("01"));
    printf("%d\n", parseInt("02"));
    printf("%d\n", parseInt("012"));
    printf("%d\n", parseInt("00000000000"));

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
    int base = 10;
    if (*string == '0')
    { //if string is an octal number
        base = 8;
    }
    

    double result = 0;
    for (int exp = strlen(string) - 1; *string != 0; string++, exp--)
    {
        int digit = parseDecimalChar(*string);
        if (digit == -1)        
        {//if current digit was not valid
            return -1;
        }
        
        result += digit * powPositivInt(base, exp);

    }
    

    return result;
}

