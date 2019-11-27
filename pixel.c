#include "pixel.h"

//Função que colore determinado local de acordo com a cor prévia
Pixel colorir(int r, int g, int b)
{
    Pixel color;
    color.r = r; /* red */
    color.g = g; /* green */
    color.b = b; /* blue */
    return color;
}