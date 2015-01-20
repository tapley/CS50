#include <stdio.h>



int main(VOID)
{
    int a;
    int *p;
    *p = &a;
    a = 5;
    printf("p = %i", p);
    printf("*p = %i", *p);





}

