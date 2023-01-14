#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    else
    {
        // Open card.raw
        char *name_input_file = argv[1];
        FILE *input_pointer = fopen(name_input_file, "r");
        
        if (input_pointer == NULL)
        {
            printf("Error: cannot open %s\n", name_input_file);
            return 2;
        }
        
        // Initialise variables
        BYTE buffer[512];
        int counter = 0;
        FILE *img_pointer = NULL;
        char filename[8];
        
        // Repeat until end of card:
        while (fread(&buffer, 512, 1, input_pointer) == 1)
        {
            // If start of a new JPEG (0xff 0xd8 0xff 0xe*):
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                // If not first JPEG, close previous
                if (!(counter == 0))
                {
                    fclose(img_pointer);
                }
                // Initialise file
                sprintf(filename, "%03i.jpg", counter);
                img_pointer = fopen(filename, "w");
                counter++;
            }
            // If JPEG has been found, write to file
            if (!(counter == 0))
            {
                fwrite(&buffer, 512, 1, img_pointer);
            }
        }
        fclose(input_pointer);
        fclose(img_pointer);
        return 0;
    }
}