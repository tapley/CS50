
#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t ID_1;
    uint8_t ID_2;
    uint8_t ID_3;
    uint8_t ID_4;
    uint8_t body[508];
} BLOCK;


int main(void)
{
    int x = sizeof(BLOCK);
    printf("%i\n", x);



};





// check for jpeg magic numbers. if tree should save time (rather than checking four conditions every iteration).
        if (block_search.ID_1 == 0xff && block_search.ID_2 == 0xd8 && block_search.ID_3 == 0xff && block_search.ID_4 == 0xe0)
        {
            jpg_switch = 0;
            printf(" %i %i %i %i\n",block_search.ID_1, block_search.ID_2, block_search.ID_3, block_search.ID_4);
            for (int i=0; i < 508; i++)
            {
                printf("%hhu", block_search.body[i]);
            };
            printf("Success 1\n");
        }        
        else if (block_search.ID_1 == 0xff && block_search.ID_2 == 0xd8 && block_search.ID_3 == 0xff && block_search.ID_4 == 0xe1)
        {
            jpg_switch = 0;
            printf(" %i %i %i %i\n",block_search.ID_1, block_search.ID_2, block_search.ID_3, block_search.ID_4);
            printf("Success 2\n");
        }   
        
        
        
        
        
        
     if (block_search.ID_1 == 0xff)
        {
            if(block_search.ID_2 == 0xd8)
            {
                if(block_search.ID_3 == 0xff)
                {
                    if(block_search.ID_4 == 0xe0 || block_search.ID_4 == 0xe1)
                    {
                        jpg_switch = 0;
                        printf("Success\n");
                        printf("%i\n% i\n %i\n %i\n",block_search.ID_1, block_search.ID_2, block_search.ID_3, block_search.ID_4);
                    }
                    else
                    {
                        printf("Checking... Iteration1: %i\n", placement);
                    }
                }
                else
                {
                    printf("Checking... Iteration2: %i\n", placement);
                }
            }
            else
            {
            printf("Checking... Iteration3: %i\n", placement);
            }          
        }
        
        
        
        
        //recover2
        // check if EOF
        else if (fread(&block_search, sizeof(block), 1, inptr) != 1)
        {
            printf("No JPEG found.");
            jpg_switch = 0;
        };
        
        //recover
        // check if EOF
        else if (fread(&block_search, sizeof(block), 1, inptr) != 1)
        {
            printf("No JPEG found.");
            jpg_switch = 0;
        };
        
        
        
        
        
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
        if (fread(&block_search, sizeof(block), 1, inptr) != 1)
        {
            printf("No JPEG found.");
            jpg_switch = 0;
            break;
        }        
        else if (block_search.ID_1 == 0xff)
        {
            if(block_search.ID_2 == 0xd8)
            {
                if(block_search.ID_3 == 0xff)
                {
                    if(block_search.ID_4 == 0xe0 || block_search.ID_4 == 0xe1)
                    {
                        jpg_switch = 0;
                        printf("%i\n", placement);
                        break;
                    };
                };
                
            };
        };
        placement++;
        //fseek(inptr, sizeof(block), SEEK_CUR);
    } while(jpg_switch == 1);
    
    return placement;
};

    
// when hitting magic number, begin saving data to buffer

    // when hitting magic number against, save outfile as a jpg
        
        // write outfile to jpg
        
        // name jpg ###.jpg
    
    // begin process again

// close memcard file

// close buffer







        
        
