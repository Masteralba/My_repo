#include <stdio.h>
#include <stdlib.h>

#include "help_functions.c"
#include "struct.c"

#define BITS_PER_PIXEl 24
#define PLANES 1
#define SIGNATURE 19778

Rgb **read_bmp(char file_name[], BitmapFileHeader* bmfh, BitmapInfoHeader* bmif)
{
    FILE *f = fopen(file_name, "rb");
    if ( f == NULL )
    {
        error("Error in 'read_bmp': file was not read sucsessfully", bmfh, bmif, NULL);
    }
    unsigned int readed = 0;
    readed += fread(bmfh, 1, sizeof(BitmapFileHeader), f);
    if ( bmfh->signature != SIGNATURE)
    {
        fclose(f);
        error("Error in 'read_bmp': file is not bmp format", bmfh, bmif, NULL);
    }
    readed += fread(bmif, 1, sizeof(BitmapInfoHeader), f);
    if ( bmif->planes != PLANES)
    {
        error("Error in 'read_bmp': planes are not equal to 1", bmfh, bmif, NULL);
    }
    if ( bmif->bitsPerPixel != BITS_PER_PIXEl)
    {
        error("Error in 'read_bmp': bits_per_pixel are not equal to 24", bmfh, bmif, NULL);
    }
    unsigned int H = bmif->height;
    unsigned int W = bmif->width;
    unsigned int padding = (W * sizeof(Rgb)) % 4;
    if ( padding ) padding = 4 - padding;
    size_t total_size = W * sizeof(Rgb) + padding;
    Rgb **arr = (Rgb**)malloc(H * sizeof(Rgb*));
    for(int i = 0; i < H; i++)
    {
        arr[i] = (Rgb*)calloc(1, total_size);   
        readed += fread(arr[i], 1, W * sizeof(Rgb) + padding,f);
    }
    if (readed!= bmfh->filesize)
    {
        
    }
    fclose(f);
    return arr;
}

// malloc(W * sizeof(Rgb) + padding)

void print_file_header(BitmapFileHeader header)
{
    printf("signature:\t%x (%hu)\n", header.signature,header.signature);
    printf("filesize:\t%x (%u)\n", header.filesize,header.filesize);
    printf("reserved1:\t%x (%hu)\n", header.reserved1,header.reserved1);
    printf("reserved2:\t%x (%hu)\n", header.reserved2,header.reserved2);
    printf("pixelArrOffset:\t%x (%u)\n", header.pixelArrOffset, header.pixelArrOffset);
}
void print_info_header(BitmapInfoHeader header){
    printf("headerSize:\t%x (%u)\n", header.headerSize,header.headerSize);
    printf("width: \t%x (%u)\n", header.width, header.width); 
    printf("height: \t%x (%u)\n", header.height,header.height);
    printf("planes: \t%x (%hu)\n", header.planes,header.planes);
    printf("bitsPerPixel:\t%x (%hu)\n", header.bitsPerPixel, header.bitsPerPixel);
    printf("compression:\t%x (%u)\n", header.compression, header.compression);
    printf("imageSize:\t%x (%u)\n", header.imageSize,header.imageSize);
    printf("xPixelsPerMeter:\t%x (%u)\n", header.xPixelsPerMeter, header.xPixelsPerMeter);
    printf("yPixelsPerMeter:\t%x (%u)\n", header.yPixelsPerMeter, header.yPixelsPerMeter);
    printf("colorsInColorTable:\t%x (%u)\n", header.colorsInColorTable, header.colorsInColorTable);
    printf("importantColorCount:\t%x (%u)\n", header.importantColorCount, header.importantColorCount);
}



void write_bmp(char file_name[], Rgb **arr, unsigned int H, unsigned int W, BitmapFileHeader bmfh, BitmapInfoHeader bmif)
{
    FILE *ff = fopen(file_name, "wb");
    if (!ff) error("Error in 'write_bmp': file was not read sucsessfully", &bmfh, &bmif, NULL);    
    fwrite(&bmfh, 1, sizeof(BitmapFileHeader), ff);
    fwrite(&bmif, 1, sizeof(BitmapInfoHeader), ff);
    unsigned int padding = (W * sizeof(Rgb)) % 4;
    if ( padding ) padding = 4 - padding;
    for(int i = 0; i < H; i++)
    {
        fwrite(arr[i], 1, W * sizeof(Rgb) + padding, ff);
    }
    fclose(ff);
}