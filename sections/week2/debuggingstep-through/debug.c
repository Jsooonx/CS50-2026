#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number = 5;

    int guess = get_int("What's your guess? ");

    if (guess != number)
    {
        printf("Wrong guess!\n");
    }
    else
    {
        printf("You're correct!\n");
    }
}