#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    
    //checks number of command terminal inputs
    if (argc != 2)
    {
        printf("Input failed.\n");
        return 1; 
    };
    
    //checks each char in key to be sure it's an alpha. if isalpha is true, moves on. if isalpha is false, input fails.
    for (int i = 0, key_len = strlen(argv[1]); i < key_len; i++)
    {
        int key_char = argv[1][i];
        if (isalpha(key_char));       
        else
        {
            printf("Input failed.\n");
            return 1;
        };      
    };
 
    // set variables for key and phrase
    string key = argv[1];
    string phrase = GetString();
    int key_space = 0;
    int key_len = strlen(key);

    // variable check
    printf("%s is the key. %s is the phrase.\n", key, phrase);          
               
    //moves through each letter of phrase
    for (int i = 0, phrase_len = strlen(phrase); i < phrase_len; i++)
    {                       
                                        
        //changes capital letters, moves one character down key            
        if (isalpha(phrase[i]) && isupper(phrase[i]))
        {
            char code_char = (((phrase[i]- 65) + (toupper(key[key_space % key_len]) - 65)) % 26) + 65;
            printf("%c", code_char);
            key_space++;                
        }
        
        //changes lower-case letters, moves one character down key
        else if (isalpha(phrase[i]) && islower(phrase[i]))
        {
            char code_char = (((phrase[i]- 97) + (tolower(key[key_space % key_len]) - 97)) % 26) + 97;
            printf("%c", code_char);
            key_space++;
        }
        
        //leaves non-letters alone
        else
        {
            printf("%c", phrase[i]);
        };                                
    }
    
    printf("\n");
    return 0;        
}
