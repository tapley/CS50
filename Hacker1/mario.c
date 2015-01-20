#include <stdio.h>
#include <cs50.h>


int main()
{
    int height;
    
    do
    {
        printf("Height:\n");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    
    for (int i = 1; i <= height; i++)
        {
            for (int j = 0; j < (height-i); j++)
                printf(" ");
            for (int k = 1; k <= i; k++)
                printf("#");
            printf("  ");
            for (int l = 1; l <= i; l++)
                printf("#");
            printf("\n");
        }
    return 0;
}
