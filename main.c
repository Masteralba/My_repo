#include <stdlib.h>

#include "input_functions.c"

void swap(char *a, char *b){
 char t = *a;
 *a = *b;
 *b = t;
}

void swap_int(int* a, int* b)
{
    int t = *a;
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
 for(int i = 0; i < H; i++){
 for(int j = 0; j < W; j++){
 arr[i][j].r = 255;
 }
 }
 return arr;
} 

void draw_line(Rgb **arr, int H, int W, int x0, int y0,
int x1, int y1, int thickness, int* color){
 if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || thickness <= 0){
 return ;
 }
 // вертикальная линия
 if (x0 == x1){
 if (y0 > y1){
 swap_int(&y0, &y1);
 }
 for (int y = y0; y < y1; y++){
 for (int j = 0; j < thickness; j++){
 if (H - y >= 0 && x0 - j >= 0 && x0 - j
< W && H - y < H){
 arr[H - y][x0 - j].r = *(color);
 arr[H - y][x0 - j].g = *(color + 1);
 arr[H - y][x0 - j].b = *(color + 2);
 }
 }
 }
 // горизонтальная линия
 } else if (y0 == y1){ if (x0 > x1){
 swap_int(&x0, &x1);
 }
 for (int x = x0; x < x1; x++){
 for (int j = 0; j < thickness; j++){
 if (H - y0 + j >= 0 && x >= 0 && x < W
&& H - y0 + j < H){
 arr[H - y0 + j][x].r = *(color);
 arr[H - y0 + j][x].g = *(color + 1);
 arr[H - y0 + j][x].b = *(color + 2);
 }
 }
 }
 }
} 

int main()
{
    BitmapFileHeader* fileheader = (BitmapFileHeader*)malloc(sizeof(BitmapFileHeader));
    BitmapInfoHeader* infoheader = (BitmapInfoHeader*)malloc(sizeof(BitmapInfoHeader));
    Rgb** image = read_bmp("blackbuck.bmp", fileheader, infoheader);
    print_file_header(*fileheader);
    printf("\n");
    print_info_header(*infoheader);
    int c[] = {100, 200, 100};
    draw_line(image, 100, 255, 0, 0, 100, 100, 10, c);
}