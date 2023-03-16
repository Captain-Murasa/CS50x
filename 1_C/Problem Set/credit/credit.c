#include <cs50.h>
#include <stdio.h>

#define THIRTEEN 1000000000000
#define FOURTEEN 10000000000000
#define FIFTEEN 100000000000000
#define SIXTEEN 1000000000000000

string check(long num);
bool AE(long num);
bool MC(long num);
bool Visa(long num);
bool valid(long num);

int main(void)
{
    long num = get_long("Number: ");
    string msg = check(num);
    printf("%s\n", msg);
}

// Determine the last string to print
string check(long num)
{
    if (AE(num) && valid(num))
    {
        return "AMEX";
    }
    else if (MC(num) && valid(num))
    {
        return "MASTERCARD";
    }
    else if (Visa(num) && valid(num))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

// Check if the number likes Amercan Express
bool AE(long num)
{
    if ((num / FIFTEEN < 10) && ((num / FOURTEEN == 34) || (num / FOURTEEN == 37)))
    {
        return true;
    }
    return false;
}

// Check if the number likes MasterCard
bool MC(long num)
{
    if ((num / SIXTEEN == 5) && (num / FIFTEEN % 10 < 6))
    {
        return true;
    }
    return false;
}

// Check if the number likes Visa
bool Visa(long num)
{
    if ((num / THIRTEEN == 4) || (num / SIXTEEN == 4))
    {
        return true;
    }
    return false;
}

// Use Luhn’s Algorithm checks if the number is valid.
bool valid(long num)
{
    long temp = num;
    int sum = 0;
    while (temp)
    {
        int first = temp % 100 / 10 * 2;
        if (first > 9)
        {
            first = first % 10 + first / 10;
        }
        int second = temp % 10;
        sum += first + second;
        temp /= 100;
    }
    return !(sum % 10);
}