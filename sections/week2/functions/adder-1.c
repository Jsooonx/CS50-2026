#include <stdio.h>
#include <cs50.h>

int add_two_ints(int a, int b);

int main(void)
{
    int x = get_int("Give me an integer: ");
    int y = get_int("Give me another integer: ");

    int z = add_two_ints(x, y);

    printf("The sum of %i and %i is %i!\n", x, y, z);
}

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}