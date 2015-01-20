#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
//need to add operator that returns true if the string contains a digit
    if (argc != 2))
    {
        printf("Input failed.\n");
        return 1; 
    }
 
 
 // need to convert alphabetic key into numeric key. need a new string where nk[] will be equal to ak[] minus 65 or 97 depending on upper or lower case
 
 
 
    else
    {
        string key_a = argv[1];
        string phrase = GetString();
        int kc = 0;
        
        for (int h = 0, m = strlen(key_a); h < m; h++)
        {
            int key_n[h] = atoi(key_a[h];
            printf("%i\n",key_n[h]);
        }    
                      
        //moves through each letter of phrase
        /*for (int i = 0, n = strlen(phrase); i < n; i++)
        {                       
            //leaves non-letters alone
            if (phrase[i] < 'A' || (phrase[i] > 'Z' && phrase[i] < 'a') || phrase[i] > 'z')
                printf("%c", phrase[i]);
            //changes capital letters            
            else if (phrase[i] >= 'A' && phrase[i] <= 'Z')
            {
                char cc = (((phrase[i]- 65) + (key[kc] % 26)) % 26) + 65;
                printf("%c", cc);
                kc++;                
            }
            //changes lower-case letters
            else if (phrase[i] >= 'a' && phrase[i] <= 'z')
            {
                char cc = (((phrase[i]- 97) + (key[kc] % 26)) % 26) + 97;
                printf("%c", cc);
                kc++;
            };
                                                
        }
        return 0;
        */
    }
}
