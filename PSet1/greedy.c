#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    // prompts user for change owed, in dollars (float)
    printf("How much change is owed?:\n");
    float change = GetFloat();
   
    // ensures user is entering a positive amount
    while (change < 0) 
    {
        printf("Error. Negative change impossible. Try again:\n");
        change = GetFloat();
    };

    // changes dollars (floats) into cents (ints)
    int cents = (roundf(change * 100));
    
    /* determines max number of quarters that can be taken from the given amount. 
    each time there's a remainder, the program will try using a smaller coin denomination.
    note the pattern of qr, q repeats until (p = nr).*/
    
    int qr = cents % 25;
    int q = (cents - qr) / 25;
    
    int dr = qr % 10;
    int d = (qr - dr) / 10;
    
    int nr = dr % 5;
    int n = (dr - nr) / 5;
    
    int p = nr;
    
    int min_coins_needed = q + d + n + p;
    
    printf("%i\n",min_coins_needed);
 }
