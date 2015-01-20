#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int d = GetInt();
    //declares array that will hold board values
    int square[d][d];
    
    //makes all rows except final
    for(int row = 1; row <= (d-1); row++)        
    {
        //makes cols in rows
        for(int col = 1; col <= d; col++)
        {
            square[row][col] = (d*d-1) - ((row-1)*d + (col-1));
            printf("%i", square[row][col]);
        };
    };
    //makes final row except square[d][1,2,_]
    if (d != 3)
    {    
        for (int col = 1, row = d; col <= (d - 3); col++)
        {
            square[row][col] = (d*d-1) - ((row-1)*d + (col-1));
            printf("%i", square[row][col]);
        }
    };
    square[d][d] = ' ';
    square[d][d-1] = 2;
    square [d][d-2] = 1;    
return 0;
}
