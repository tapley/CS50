#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Enter an integer between 0 and 23:\n");
    int height = GetInt();
   
    //will keep running until an integer between 1-23 is entered
  
        while (height < 0 || height > 23) 
        {
            printf("Integer outside range. Try again:\n");
            height = GetInt();
        };

    
    for (int i = height; i > 0; i--)
    {
        //uses spaces to keep pyramid aligned with left side of page
        for (int j = 1; j < i; j++)
        {
            printf(" ");
        };
        //prints as many # as height units, ensuring pyramid shape
        for (int k = i; k <= height; k++)
        {
            printf("#");
        };
        //ensures extra # in each row
        printf("#\n");
        
    };
}  
