#include <stdio.h>
#include "SDL.h"
#include "SDL_ttf.h"

int main(int argc, const char *argv[])
{
    char * pstr = "2019-11-21 15:40:28 Front";
    SDL_PixelFormat *fmt;
    TTF_Font *font;  
    SDL_Surface *text, *temp;  

    if (TTF_Init() < 0 ) 
    {  
        fprintf(stderr, "Couldn't initialize TTF: %s\n",SDL_GetError());  
        SDL_Quit();
    }  

    font = TTF_OpenFont("/root/res/wqy-microhei.ttc", 48); 
    if ( font == NULL ) 
    {  
        fprintf(stderr, "Couldn't load %d pt font from %s: %s\n", 18, "ptsize", SDL_GetError());  
    }  

    SDL_Color forecol = {  0xff, 0xff, 0xff, 0xff };  
    text = TTF_RenderUTF8_Solid(font, pstr, forecol);

    fmt = (SDL_PixelFormat*)malloc(sizeof(SDL_PixelFormat));
    memset(fmt,0,sizeof(SDL_PixelFormat));
    fmt->BitsPerPixel = 16;
    fmt->BytesPerPixel = 2;
    fmt->colorkey = 0xffffffff;
    fmt->alpha = 0xff;

    temp = SDL_ConvertSurface(text, fmt, 0);
    SDL_SaveBMP(temp, "save.bmp"); 

    SDL_FreeSurface(text);  
    SDL_FreeSurface(temp);
    TTF_CloseFont(font);  
    TTF_Quit();  

    return 0;
}




