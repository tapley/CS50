/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int min = 0;
    int max = n-1;
    int mid = (n-1) / 2;
    int stop;
    int found;
    
    do
    {
        stop = 1;
        found = 1;
        if (values[mid] == value)
        {
            stop = 0;
            found = 0;
        }
        else if (mid == min || mid == max)
        {
            stop = 0;
            found = 1;
        }
        else if (values[mid] < value)
        {
            stop = 1;
            min = mid;
            mid = ((max-min)/2) + min;
        }
        else
        {
            stop = 1;
            max = mid;
            mid = ((max-min)/2) + min;            
        };
    }  
    while (stop == 1);
    
    if (found == 0)
        return true;
    else
        return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int h = 0; h < n; h++)
    {
        for (int i = 0; i < n-h; i++)
        {
            int first = values [i];
            int second = values [i + 1];        
            if (first > second)
            {
                values[i] = second;
                values[i + 1] = first;
                
            };
        };
    };
    return;
} 

