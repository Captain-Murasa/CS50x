#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string msg = get_string("Message: ");
    for (int i = 0; msg[i]; i++)
    {
        int bi[BITS_IN_BYTE] = {};
        int dec = (int)msg[i];
        int x = 0;
        while (dec)
        {
            bi[x++] = dec % 2;
            dec /= 2;
        }
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            print_bulb(bi[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
