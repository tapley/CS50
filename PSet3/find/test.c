#include <cs50.h>
#include <stdio.h>


int main(void)
{

string s = GetString();
int n = StrLen (s);
        
for (int i = 0; i < (n-i); i++)
    {
        int first = values [i];
        int second = values [i + 1];        
        if (first > second)
        {
            values[i] = second;
            values[i + 1] = first;
            
        };
        printf("%i/n", values [i])
    }

return;

}
