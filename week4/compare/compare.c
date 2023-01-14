#include <cs50.h>
#include <stdio.h>
#include <string.h>

int max(int num1, int num2);

int main(void)
{
    printf("Would you like to compare strings or ints?");
    int sori = get_int(" 1 for string, 2 for int: ");
    
    if (sori == 1)
    {
        char *string1 = get_string("string 1: ");
        char *string2 = get_string("string 2: ");

        int n = max(strlen(string1), strlen(string2));
        int correctletters = 0;
    
        for (int i = 0; i < n; i++)
        {
            if (string1[i] == string2[i])
            {
                correctletters++;
            }
        }

        if (correctletters == n)
        {
            printf("These strings are the same. \n");
        }
        else
        {
            printf("Not the same string. \n");
        }    
    }
    else if (sori == 2)
    {
        int int1 = get_int("int 1: ");
        int int2 = get_int("int 2: ");
        
        if (int1 == int2)
        {
            printf("These integers are the same.\n");
        }
        else 
        {
            printf("These integers are not the same.\n");
        }
    }
    else 
    {
        printf("Only 1 or 2. Come on!");
    }
}

int max(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else if (num2 > num1)
    {
        return num2;
    }
    else
    {
        return num1;
    }
}