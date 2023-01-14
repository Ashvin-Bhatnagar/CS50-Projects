#include <stdio.h>
#include <cs50.h>
#include <math.h>
int check_coin(int);

int main(void) {
   
    float dollars; 
    do
    {
        dollars = get_float("Change owed in dollars: \n");
    }
    while(dollars <= 0);
    
    int change = round(dollars * 100);
    int coins = 0;
    
    while (change >= 25)
    {
        change -= 25;
        coins++;
    }
    while (change >= 10)
    {
        change -= 10;
        coins++;
    }
    while (change >= 5)
    {
        change -= 5;
        coins++;
    }
    while (change >= 1)
    {
        change -= 1;
        coins++;
    }
        printf("%i \n", coins);
}
