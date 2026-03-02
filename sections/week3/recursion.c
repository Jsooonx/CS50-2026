#include <stdio.h>
#include <cs50.h>

int collatz(int number);

int main(void)
{
    int number = get_int("Input your number to count the collatz: \n");

    int steps = collatz(number);

    printf("Collatz steps for %i: %i\n", number, steps);
}

int collatz(int number)
{
    if (number == 1)
    {
        return 0;
    }
    else if ((number % 2) == 0)
    {
        return 1 + collatz(number / 2);
    }
    else
    {
        return 1 + collatz(3*number + 1);
    }
}