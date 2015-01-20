#include <stdio.h>
#include <stdint.h>




int main(void)
{
    int JPEG_int = 3;
    char JPEG_str[8];

    sprintf(JPEG_str, "%03.3i.txt", JPEG_int);

    FILE* outptr = fopen(JPEG_str, "w");
    
    fwrite(&JPEG_int, sizeof(int), 1, outptr);
    

    printf("%s\n", JPEG_str);

    return 0;

}
