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

// typedef a node for the linked list
typedef struct node
{
    int n;
    struct node* next;
}
node;

// function prototypes
bool insert_node(int value);
void print_nodes(node* list);
void free_nodes(node* list);

// global variable for the head of the list
node* head = NULL;

int main(void)
{
    // offer the user two options
    while (true)
    {
        printf("Please choose an option (0, 1, 2): ");
        int option = GetInt();
        
        switch (option)
        {
            // quit
            case 0:
                free_nodes(head);
                printf("Goodbye!\n");
                return 0;
            
            // insert int into linked list
            case 1:
                printf("Please enter an int: ");
                int v = GetInt();
                char* success = insert_node(v) ? "was" : "was not";
                printf("The insert %s successful.\n", success);
                break;
            
            // print all ints
            case 2:
                print_nodes(head);
                break;
            
            default:
                printf("Not a valid option.\n");
                break;
        }
    }
}

/**
 * Create a new node for a given value and insert it into a list.
 */
bool insert_node(int value)
{
    
    node *insert;
    insert = malloc(sizeof(node));
    if (insert == NULL)
    {
        return false;
    }
    
    insert->n = value;
    insert->next = NULL;
    
    if (head == NULL)
    {
        head = insert;
        return true;
    };
    
    node *curr;
    curr = head;
    
    node *next;
    next = curr->next;
    
     
    while (true)
    {
        if (curr->n == value)
        {
            printf("No duplicates. Please insert original int.");
            return false;
        }
        else if (next == NULL)
        {
            curr->next = insert;
            insert->next = NULL;
            return true;
        }
        else if (next->n == value)
        {
            printf("No duplicates. Please insert original int.");
            return false;
        }               
        else if (next->n < value)
        {
            curr = next;
            next = next->next;                                                    
        }
        else if (next->n > value)
        {
            curr->next = insert;
            insert->next = next;
            return true;
        } 
    };

    return false;
}

/**
 * Print out all of the ints in a list.
 */
void print_nodes(node* head)
{
    node *curr;
    curr = head;
    
    node *next;
    next = curr->next;
    
    if (head != NULL)
    {
        while (next != NULL)
        {
            printf("%i ", curr->n);
            curr = next;
            next = next->next;  
        };
        printf("%i ", curr->n);
    };
    printf("\n");   
}

/**
 * Frees all of the nodes in a list upon exiting the program.
 */
void free_nodes(node* head)
{   
    node *curr;
    curr = head;
    
    node *next;
    next = head->next;
    
    if (head != NULL)
    {
        while (next != NULL)
        {
            free(curr);
            curr = next;
            next = next->next;  
        };
        free(curr);
    };
}
