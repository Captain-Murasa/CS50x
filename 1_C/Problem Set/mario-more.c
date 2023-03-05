#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height * 2 + 2; j++)
        {
            if (i + j + 1 < height || j == height || j == height + 1)
            {
                printf(" ");
            }
            else if (j - i - 2 <= height)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}