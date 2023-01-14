#include <stdio.h>
#include <cs50.h>

int main(void) {
    // get height of steps from the user
    int height;
    do {
        height = get_int("Height: \n");
    }
    while (1 > height || height > 8);
   
   int i;
    for (i = 0; i < height; i++) {
        int j;
        int p;
        for (p = height - 1; p > i; p--) {
            printf(" ");
        }
        for (j = 0; j <= i; j++){
            printf("#");
        }
        printf("\n");
    }
}