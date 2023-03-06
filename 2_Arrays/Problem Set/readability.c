// Computes the Coleman-Liau index of text.
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");

    // printf("%i letters\n", count_letters(text));
    // printf("%i words\n", count_words(text));
    // printf("%i sentences\n", count_sentences(text));

    int grade = calculate(count_letters(text), count_words(text), count_sentences(text));
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int sum = 0;
    for (int i = 0; text[i]; i++)
    {
        if (isalpha(text[i]))
        {
            sum++;
        }
    }
    return sum;
}

int count_words(string text)
{
    int sum = 1;
    for (int i = 0; text[i]; i++)
    {
        if (isspace(text[i]))
        {
            sum++;
        }
    }
    return sum;
}

int count_sentences(string text)
{
    int sum = 0;
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sum++;
        }
    }
    return sum;
}

int calculate(int letters, int words, int sentences)
{
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);
}