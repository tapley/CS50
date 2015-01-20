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
    
    //set positioning to start of first jpeg block
    fseek(inptr, sizeof(block) * (placement-1), SEEK_SET);
    
    block block;
    fread(&block, sizeof(block), 1, inptr);     
};



int search(FILE* inptr)
{

    // move down the file looking for the first set of jpeg magic numbers
    int jpg_switch = 1;
    int placement = 0; 
    fseek(inptr, 0, SEEK_CUR);
    
    do
    {
        // declare a block to check
        block block_search; 
        
        // read inptr and insert data into block
        fread(&block_search, sizeof(block), 1, inptr); 
               
        // check for jpeg magic numbers. if tree should save time (rather than checking four conditions every iteration).
        if (block_search.ID_1 == 0xff && block_search.ID_2 == 0xd8 && block_search.ID_3 == 0xff && block_search.ID_4 == 0xe0)
        {
            jpg_switch = 0;
            printf("\n%i\n", placement);
        }        
        else if (block_search.ID_1 == 0xff && block_search.ID_2 == 0xd8 && block_search.ID_3 == 0xff && block_search.ID_4 == 0xe1)
        {
            jpg_switch = 0;
            printf("\n%i\n", placement);
        }
        else if (fread(&block_search, sizeof(block), 1, inptr) != 1)
        {
            printf("No JPEG found.");
            jpg_switch = 0;
        }; 
        placement++;
        fseek(inptr, sizeof(block), SEEK_CUR);
    } while(jpg_switch == 1);
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

