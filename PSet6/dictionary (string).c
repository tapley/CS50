/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <cs50.h>
#include <ctype.h>
#include "dictionary.h"

typedef struct node
{
    bool EOW;
    struct node *letter[27];
} 
node;

node *root;
int *word_count;

node* find_endnode(node* startnode);


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node *curr;
    curr = root;
    
    int i = 0;
    
    // start a loop moving through each char of word until it gets to null
    while (true)
    {                        
        char c = tolower(word[i]);
        
        if (c == '\0')
        {
            if (curr->EOW == true)
            {
                return true;
            }
            else
            {
                return false;
            };       
        }
        else if (c == 39)
        {
            if (curr->letter[c - 13] == NULL)
            {
                return false;
            }
            else
            {
                curr = curr->letter[c - 13];
            };      
        }
        else
        {
            if (curr->letter[c - 97] == NULL)
            {
                return false;
            }
            else
            {          
                curr = curr->letter[c - 97];           
            }
        };
        
        i++;      
    }; 
}

/**
 * Loads dictionary into memory.  Returns true if successful else false. Uses char checking process from speller.c in CS50.
 */
bool load(const char* dictionary)
{    
    if (dictionary == NULL)
    {
        return false;   
    };
    
    root = malloc(sizeof(node));
    word_count = malloc(sizeof(int));
    for (int i = 0; i < 27; i++)
    {
        root->letter[i] = NULL;   
    };    
        
    *word_count = 0;
        
    node *curr;
    node *next;
    curr = root;
          
    int i = -1;
    
    // move through entire dictionary char by char until it hits the EOF
    do
    {       
        i++;
                
                                
        //move through each word char by char until it hits the end of a word or EOF
        do
        {            
            int di = dictionary[i];
            curr->EOW = false;           
            
            // special case of apostrophe in ASCII.
            if (di == 39)
            {
                if (curr->letter[di - 13] == NULL)
                {
                    next = malloc(sizeof(node));
                    for (int i = 0; i < 27; i++)
                    {
                        next->letter[i] = NULL;   
                    }; 
                    curr->letter[di - 13] = next;
                    curr = next;            
                }
                else
                {
                    curr = curr->letter[di - 13];
                };
            } 
                       
            // a-z in ASCII
            else
            {
                if (curr->letter[di - 97] == NULL)
                {
                    next = malloc(sizeof(node));
                    for (int i = 0; i < 27; i++)
                    {
                        next->letter[i] = NULL;   
                    }; 
                    curr->letter[di - 97] = next;
                    curr = next;            
                }
                else
                {
                    curr = curr->letter[di - 97];
                };
            };
            
            i++;
            *word_count = *word_count+1;
            
        } while (dictionary[i] != '\n' && dictionary[i] != '\0');
        
        curr->EOW = true;
        curr = root;                   
    }
    while (dictionary[i] != '\0');
    
    free(next);
    // TODO see if you need to free(curr);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return *word_count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    while (root != NULL)
    {
        node *unloader;
        unloader = find_endnode(root);
        free (unloader);    
    }    
    
    return true;
}

node* find_endnode(node *startnode)
{
    int i = 0;
    while (i < 26)
    {
        if (startnode->letter[i] != NULL)
        {
            return find_endnode(startnode->letter[i]);       
        }
        else
        {
            i++;
        };  
    }
    return startnode;
}
