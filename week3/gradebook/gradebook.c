#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    string name;
    int grade;
}
student;

int main(int argc, string argv[])
{

     //checking right amount of arguments
    if (argc != 2)
    {
        printf("Usage: ./gradebook n (no of students) \n");
        return 1;
    }
    
    //num of students being placed into variable as int
    int num = atoi(argv[1]);
    
    student gradebook[num];
    
    //checking if non-negative integer
    if (num < 0)
    {
        printf("Usage: ./gradebook n (no of students \n");
        return 1;
    }
    else
    {
        for (int i = 1; i < num + 1; i++)
        {
            gradebook[i].name = get_string("Student #%i, name: \n", i);
            gradebook[i].grade = get_int("Student #%i, grade: \n", i);
        }
        return 0;
    }
} 
