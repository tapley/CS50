/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Copies and resizes a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage of arguments
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    // ensure proper usage of n
    int n = atoi(argv[1]);
    if (n < 1 || n > 100)
    {
        printf("Usage: 0 <= n <= 100\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding values for infile and outfile
    int padding_i =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_o =  (4 - (n * bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // save infile height and width values, then makes  adjustments
    int biHeight_i = bi.biHeight;
    int biWidth_i = bi.biWidth;
    bi.biHeight = bi.biHeight * n;
    bi.biWidth = bi.biWidth * n;    
    
    // adjust BITMAPFILEHEADER for resize
    bf.bfSize = 54 + abs(bi.biHeight) * (bi.biWidth * sizeof(RGBTRIPLE) + padding_o);    
    
    // adjust BITMAPINFOHEADER for resize
    bi.biSizeImage = bf.bfSize - 54;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0; i < abs(biHeight_i); i++)
    {
        // add aditional iterations for vertical resize
        for (int ri = 0; ri < n; ri++)
        { 
            //return to beginning of scanline in infile
            fseek(inptr, bf.bfOffBits + (sizeof(RGBTRIPLE) * biWidth_i + padding_i) * i, SEEK_SET); 
            
            // iterate over infile pixels in scanline
            for (int j = 0; j < biWidth_i; j++)
            {
                              
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // add additional iterations for horizontal resize
                for (int rj = 0; rj < n; rj++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // add padding
            for (int k = 0; k < padding_o; k++)
            {
                fputc(0x00, outptr);
            }   
        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
