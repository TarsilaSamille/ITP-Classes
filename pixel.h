#ifndef PIXEL_H
#define PIXEL_H


typedef struct Pixel{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

Pixel colorir(int r, int g, int b);

#endif