#include <stdio.h>
#include <cs50.h>

int main(void) {
    long credit = get_long("Input your credit card numbers: \n");
    long temp = credit;
    int sum = 0;
    int position = 0;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (position % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            int product = digit * 2;

            if (product >= 10)
            {
                sum += product / 10;
                sum += product % 10;
            }
            else
            {
                sum += product;
            }
        }

        temp /= 10;
        position++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    temp = credit;
    int length = 0;

    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    long start = credit;

    while (start >= 100)
    {
        start /= 10;
    }

    if (length == 15 && (start == 34 || start == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && start >= 51 && start <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}