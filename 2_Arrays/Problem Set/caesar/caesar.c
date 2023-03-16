// Caesar’s algorithm
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one digit command-line argument
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int k = atoi(argv[1]) % 26;

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Rotate every letter in the plaintext and print
    printf("ciphertext: ");
    for (int i = 0; plaintext[i]; i++)
    {
        printf("%c", rotate(plaintext[i], k));
    }
    printf("\n");
    
    return 0;
}

// Make sure every character in argv[1] is a digit
bool only_digits(string s)
{
    for (int i = 0; s[i]; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Rotate the character if it's a letter
char rotate(char c, int n)
{
    if (islower(c))
    {
        c = (c - 'a' + n) % 26 + 'a';
    }
    if (isupper(c))
    {
        c = (c - 'A' + n) % 26 + 'A';
    }
    return c;
}