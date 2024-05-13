#pragma once

#include <stdio.h>
#include "struct.c"

void free_memory(BitmapFileHeader* bmfh, BitmapInfoHeader* bmif, Rgb** pixels)
{
    if (pixels != NULL)
    {
        int H = 0;
        if ( bmif != NULL) H = bmif->height;
        {
            for ( size_t i=0; i < H; i++) free(pixels[i]);
        }
    }
    free(pixels);
    free(bmif);
    free(bmfh);
}

void error(const char* message, BitmapFileHeader* bmfh, BitmapInfoHeader* bmif, Rgb** pixels)
{
    fprintf(stderr, "%s\n", message);
    free_memory(bmfh, bmif, pixels);
    exit(0);
}