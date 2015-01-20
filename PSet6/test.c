/**
 * linked.c
 *
 * week 7 section
 * fall 2013
 *
 * practice using linked lists
 */

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

void pyramid_search(char);

int main (void)
{
    int i = 0;
    char dictionary[2];
    dictionary[i] = GetChar();
    
    pyramid_search(dictionary[i]);    
    
}

void pyramid_search(char di);
{
    if (di > 13)
    {
        if (di > 20)
        {
            if (di > 23)
            { 
                //24,25,26
            }
            else if (di < 23)
            {
                // 20 21,22        
            }
            else // 23       
        }
        else 
        {
            if (di > 16)
            {
                // 17,18,19
            }
            else
            {            
                //14,15,16
            }      
        }               
    };
    else if (di < 13)
    {
        if (di > 6)
            if (di > 9)
                // 10, 11, 12
            else if
                // 7, 8, 9
        else
            if (di > 3)
                // 4, 5, 6
            else
                // 1, 2, 3   
    };
    else
        //13
    

}







