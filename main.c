#include <stdlib.h>

#include "input_functions.c"
#include "function_2.c"
#include "function_3.c"
#include "function_1.c"

void swap(char *a, char *b){
 char t = *a;
 *a = *b;
 *b = t;
}


Rgb **swap_channels(Rgb **arr, int H, int W){
 for(int i=0; i<H; i++){
 for(int j=0; j<W; j++){
 swap(&arr[i][j].r, &arr[i][j].g);
 }
 }
 return arr;
}

Rgb **add_red(Rgb **arr, int H, int W){
 for(int i = 0; i < 100; i++){
 for(int j = 0; j < 100; j++){
 arr[i][j].g = 255;
 arr[i][j].r = 255;
 arr[i][j].b =255;
 }
 }
 return arr;
} 



int main()
{
    BitmapFileHeader* fileheader = (BitmapFileHeader*)malloc(sizeof(BitmapFileHeader));
    BitmapInfoHeader* infoheader = (BitmapInfoHeader*)malloc(sizeof(BitmapInfoHeader));
    Rgb** pixels = read_bmp("blackbuck.bmp", fileheader, infoheader);
    print_file_header(*fileheader);
    print_info_header(*infoheader);
    unsigned int H = infoheader->height;
    unsigned int W = infoheader->width;
    Rgb c = {255, 0, 0};
   // pixels = change_component(pixels, fileheader, infoheader, "red", 255);
    //pixels = split_lines(pixels, fileheader, infoheader, 20, 10, 1, c);
    //pixels = draw(pixels, 100, 100, 10, 10, c);
    /*
    for(size_t i=0; i<H; i++)
    {
        for(size_t j=0; j<W; j++)
        {
            pixels[i][j] = change_colour(pixels[i][j], c);
        }
    }
    */
    //pixels = draw(pixels, 100, 100, 10, 10, c);
    pixels = function_1(pixels, fileheader, infoheader, 200, 350, 100, 100, c, 0);
    write_bmp("out.bmp", pixels, H, W, *fileheader, *infoheader);
    return 0;
}