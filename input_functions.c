#include <stdio.h>
#include <stdlib.h>

#include "help_functions.c"
#include "struct.c"

Rgb **read_bmp(char file_name[], BitmapFileHeader* bmfh, BitmapInfoHeader* bmif)
{
    FILE *f = fopen(file_name, "rb");
    if (!f) error("Error in 'read_bmp': file was not read sucsessfully");
    fread(bmfh, 1, sizeof(BitmapFileHeader), f);
    fread(bmif, 1, sizeof(BitmapInfoHeader), f);
    unsigned int H = bmif->height;
    unsigned int W = bmif->width;
    Rgb **arr = (Rgb**)malloc(H * sizeof(Rgb*));
    for(int i = 0; i < H; i++)
    {
        arr[i] = (Rgb*)malloc(W * sizeof(Rgb) + (W * 3) % 4);
        fread(arr[i], 1, W * sizeof(Rgb) + (W * 3) % 4,f);
    }
    fclose(f);
    return arr;
}

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



void write_bmp(char file_name[], Rgb **arr, int H, int W, BitmapFileHeader bmfh, BitmapInfoHeader bmif)
{
    FILE *ff = fopen(file_name, "wb");
    if (!ff) error("Error in 'write_bmp': file was not read sucsessfully");    
    fwrite(&bmfh, 1, sizeof(BitmapFileHeader), ff);
    fwrite(&bmif, 1, sizeof(BitmapInfoHeader), ff);
    for(int i = 0; i < H; i++)
    {
        fwrite(arr[i], 1, W * sizeof(Rgb) + (W * 3) % 4, ff);
    }
    fclose(ff);
}