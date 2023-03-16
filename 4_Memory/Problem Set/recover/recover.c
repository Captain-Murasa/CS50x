#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File open failed!\n");
        return 1;
    }

    // Buffer to store the read data
    BYTE buffer[BLOCK_SIZE];
    // File name for output image
    char file_name[8];
    // Detect the number of image
    int cnt = 0;
    // The file will be wrote
    FILE *img = NULL;

    // Loop until up to the end of .raw file
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // If it's a new file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(file_name, "%03i.jpg", cnt);
            img = fopen(file_name, "w");
            cnt++;
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    fclose(img);
    fclose(file);

    return 0;
}