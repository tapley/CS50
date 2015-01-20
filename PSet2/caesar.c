#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>



int main (int argc, string argv[])
{
    //checks that two arguments are given and that the argument is greater than zero
    if (argc != 2 || atoi(argv[1]) <= 0)
    {
        printf("Input failed.\n");
        return 1; 
    }
    else
    {
        //sets key equal to the second argument. numbers over 26 will loop around alphabet with "% 26"
        int key = atoi(argv[1]) % 26;
        
        //sets phrase equal to a given string       
        string phrase = GetString();
        
        
        //moves across each character of the phrase
        for (int i = 0, n = strlen(phrase); i < n; i++)
        {            
            //checks if character is a capital letter
            if (phrase[i] >= 'A' && phrase[i] <= 'Z')
            {
                //caesar cipher. subtract then add 65 because 'A' = 65 on ASCII table
                char code = (((phrase[i] - 65) + key) % 26) + 65;
                printf("%c", code);
            }
            
            //checks if character is a lower-case letter
            else if (phrase[i] >= 'a' && phrase[i] <= 'z')
            {
                //caesar cipher. subtract then add 97 because 'a' = 97 on ASCII table
                char code = (((phrase[i] - 97) + key) % 26) + 97;
                printf("%c", code);
            }
            
            //leaves non-letters alone
            else
                printf("%c", phrase[i]);
        }   
    };
    printf("\n");
}
