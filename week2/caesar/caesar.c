#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //checking right amount of
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    //key being placed into variable as int
    int key = atoi(argv[1]);

    //checking if non-negative integer
    if (key < 0)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else
    {
        //getting plaintext from user to be converted
        string plaintext = get_string("plaintext: \n");

       //converting each character in the code according to key
        int i;
        int n;
        for (i = 0, n = strlen(plaintext); i < n; i++)
        {
            //checking if it is lowercase, uppercase, or neither, then converting
            if (islower(plaintext[i]))
            {
               plaintext[i] = (((plaintext[i] + key) - 97) % 26) + 97;
            }
            else if (isupper(plaintext[i]))
            {
                plaintext[i] = (((plaintext[i] + key) - 65) % 26) + 65;
            }
        }

        printf("ciphertext: %s\n", plaintext);
    }

}
