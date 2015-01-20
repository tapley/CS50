/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */


#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t ID_1;
    uint8_t ID_2;
    uint8_t ID_3;
    uint8_t ID_4;
    uint8_t body[508];
} block;

int search(FILE*);

int main(int argc, char* argv[])
{    
    // open mem card file
    FILE* inptr = fopen("card.raw", "r");
    
    //check proper usage 
    if (inptr == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    };    
      
    //search for placement of first jpeg block
    int placement = search(inptr);    
    printf("%i\n", placement);    
};



int search(FILE* inptr)
{
    // move down the file looking for the first set of jpeg magic numbers
    block block_search;
    int placement;
    
    for (placement = 0; fread(&block_search, sizeof(block), 1, inptr) == 1; placement++)
    {
                              
       if (block_search.ID_1 == 0xff)
        {
            if(block_search.ID_2 == 0xd8)
            {
                if(block_search.ID_3 == 0xff)
                {
                    if(block_search.ID_4 == 0xe0 || block_search.ID_4 == 0xe1)
                    {
                        printf("%i\n", placement);
                    };
                };
                
            };
        };

    };
    // check if EOF
         
    return placement;
};

    
// when hitting magic number, begin saving data to buffer

    // when hitting magic number against, save outfile as a jpg
        
        // write outfile to jpg
        
        // name jpg ###.jpg
    
    // begin process again

// close memcard file

// close buffer

