#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string key);
char encrypt(char c, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (!valid(key))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");
    for (int i = 0; plaintext[i]; i++)
    {
        printf("%c", encrypt(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// Trial if the key is valid
bool valid(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }
    for (int i = 0; key[i]; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        for (int j = 0; j < i; j++)
        {
            if (tolower(key[j]) == tolower(key[i]))
            {
                return false;
            }
        }
    }
    return true;
}

// Encrypt the plaintext to ciphertext
char encrypt(char c, string key)
{
    if (islower(c))
    {
        return tolower(key[c - 'a']);
    }
    else if (isupper(c))
    {
        return toupper(key[c - 'A']);
    }
    else
    {
        return c;
    }
}