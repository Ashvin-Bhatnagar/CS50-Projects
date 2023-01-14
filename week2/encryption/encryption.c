#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
    string s = get_string("Message: ");
    
    srand(time(NULL));
    
    int randomno = rand() % 126;
    printf("%i \n", randomno);
}