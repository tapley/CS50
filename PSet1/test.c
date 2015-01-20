#include <stdio.h>
#include <cs50.h>

int main()
{
    int x = GetInt();
    if (x > 10)
    {
        printf("X is larger than 10");
    }
    else
    {
        printf("X is smaller than 10");
    };
}
