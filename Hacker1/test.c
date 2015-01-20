#include <cs50.h>
#include <stdio.h>

/*had to lookup how to put a math equation into the for loop update. had been using (i*100), rather than (i=(i*100)). hope the update isn't cheating.
source: http://www.tutorialspoint.com/cprogramming/c_for_loop.htm
realized once i saw example at the bottom of the page*/


int main ()
{
    printf("Number:\n");
    long long card = GetLongLong();
    int amex_check = card / 100000000000000;
    printf("%i\n", amex_check);
}
