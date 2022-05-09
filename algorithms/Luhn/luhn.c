#include <stdio.h>
#include <math.h>

int getNumLength(long long);
int sumOfDigits(int);

int main()
{
    long long int card_number_input = (long long int)"enter number here";
    short l = getNumLength(card_number_input);
    short card_number[l];
    int checksum = 0;

    for (int i = 0; i < l; i++)
    {
        card_number[i] = card_number_input % 10;
        card_number_input = card_number_input / 10;
    }

    for (int i = 0; i < l; i++)
    {
        if (i % 2 == 1)
        {
            checksum += sumOfDigits(card_number[i] * 2);
        }
        else
        {
            checksum += card_number[i];
        }

    }

    if (checksum % 10 == 0)
    {
        printf("VALID\n");
        return 1;
    }

    printf("checksum: %u", checksum);

    return 0;
}

int sumOfDigits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int getNumLength(long long int number)
{
    int l = (int)floor(log10((double)number)) + 1;

    return l;
}
