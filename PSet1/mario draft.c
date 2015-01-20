#include <stdio.h>
#include <cs50.h>

int main()
{
    int height = 24
    printf("Enter an integer between 1 and 23:\n");
        while (height < 1 || height > 23) 
        {
            printf("Integer outside range. Try again:\n");
            GetInt();
        };
        printf("Thanks for fixing that.\n");    
    };    
    
    
   
 
}  
