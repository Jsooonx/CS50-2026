#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{
    float a = get_float("Side 1: ");
    float b = get_float("Side 2: ");
    float c = get_float("Side 3: ");

    if (valid_triangle(a, b, c))
    {
        printf("Valid Triangle\n");
    } else
    {
        printf("Invalid Triangle\n");
    }
}

bool valid_triangle(float x, float y, float z)
{
    if (x < 0 || y < 0 || z < 0)
    {
        return false;
    }

    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }

    return true;
}
