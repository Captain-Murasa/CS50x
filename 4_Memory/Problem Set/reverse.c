#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Open file %s failed.\n", argv[1]);
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, 1, 44, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("Format Wrong.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Open file %s failed.\n", argv[2]);
    }

    // Write header to file
    // TODO #6
    fwrite(&header, 1, 44, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    int *buffer[size];
    fseek(input, 0, SEEK_END);
    while (ftell(input) > 44)
    {
        fseek(input, -1 * size, SEEK_CUR);
        fread(buffer, 1, size, input);
        fwrite(buffer, 1, size, output);
        fseek(input, -1 * size, SEEK_CUR);
    }

    fclose(output);
    fclose(input);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * header.bitsPerSample / 8;
}