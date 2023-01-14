#include <stdio.h>
#include <cs50.h>

int main(void){
    int startPopulation;
    do 
    {
        startPopulation = get_int("Starting population: \n");
    }
    while (startPopulation <9);
  
    int endPopulation;
    do 
    {
        endPopulation = get_int("Ending population: \n");
    }
    while (endPopulation < startPopulation);
    
    int years = 0;
    do 
    {
        startPopulation = startPopulation + startPopulation/3 - startPopulation/4;
        years++;
    }
    while (startPopulation < endPopulation);
    printf ("Years: %i \n", years);
}