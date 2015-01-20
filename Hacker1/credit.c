#include <cs50.h>
#include <stdio.h>

/*had to lookup how to put a math equation into the for loop update. had been using (i*100), rather than (i=(i*100)). hope the update isn't cheating.
source: http://www.tutorialspoint.com/cprogramming/c_for_loop.htm
realized once i saw example at the bottom of the page*/


int main ()
{
    printf("Number:\n");
    long long card = GetLongLong();
    //pulls the first two digits of a 16 digit card number
    int check_16_digit = card / 100000000000000;
    //pulls the first two digits of a 15-digit card number
    int check_15_digit = card / 10000000000000;
    //pulls the first two digits of a 13-digit card number
    int check_13_digit = card / 100000000000;
    int edd = 0;
    int es1 = 0;
    int es2 = 0;
    int od = 0;
    int os1 = 0;
    int os2 = 0;

    
        for(long long i = 1; i <= 100000000000000; i = (i*100))
        {
            //es1 holds 'even sum' from the previous iteration. on first iteration, es1 will be zero
            es1 =es2;
            //edd is the even digit doubled. each iteration will move two decimal spaces to the left, starting with the 10s space.
            edd = ((card % (i*100))/(i*10))*2;
            // edd1 is the value of edd's first digit. edd2 is the value of edd's second digit
            int edd1 = edd / 10;
            int edd2 = edd % 10;
            //updates the value of es2 for new iteration 
            es2 = es1 + edd1 + edd2;        
        };
    
    
        for(long long i = 1; i <= 100000000000000; i = (i*100))
        {
            //os1 holds the 'odd sum' from the previous iteration. on the first iteration, os1 will be zero
            os1 = os2;
            //od is each odd digit in the card number. each iteration will move two decimal places to the left, starting with the 1s space.
            od = ((card % (i*10))/i);
            // updates the value of os2 for new iteration
            os2 = os1 + od;
        };
        
        // adds up every even digit along with every digit of the product of an odd digit doubled. this is the figure meant to end in 0.
        int check_card = es2 + os2;


        // checks for validity then card type
        if ((check_card % 10) != 0)
            printf("INVALID\n");
        else if (check_16_digit >= 51 && check_16_digit <= 55)
            printf("MASTERCARD\n");
        else if (check_16_digit >= 40 && check_16_digit <=49)
            printf("VISA\n");
        else if (check_13_digit >= 40 && check_13_digit <=49)
            printf("VISA\n");
        else if (check_15_digit == 34 || check_15_digit == 37)
            printf("AMEX\n");

            
            
             
              

}







