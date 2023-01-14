#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float readability_score(string text);

int main(void)
{
    string passage = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for(int i = 0, n = strlen(passage); i < n; i++)
    {
        if(isalpha(passage[i]))
        {
            letters++;
        }

        if(passage[i] == ' ')
        {
            words++;
        }

        if(passage[i] == '.' || passage[i] == '!' || passage[i] == '?')
        {
            sentences++;
        }
    }

    int L = (100 * letters) / words;
    int S = (100 * sentences) / words;

    float index = 0.0588 * (float) L - 0.296 * (float) S - 15.8;

    int level = (int)round(index);

    if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    if (level > 7 && level > 8 )
    {
        printf("Grade 7\n");
    }
    if (level >= 1 && level < 16)
    {
        printf("Grade %i\n", level);
    }
    if (level >= 16)
    {
        printf("Grade 16+\n");
    }
}
