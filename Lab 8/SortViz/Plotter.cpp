#include "Plotter.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void Plotter::setpoints(int x0, int x1, int y){
        y = HEIGHT - y;
        if ( x0 < 0      || x1 < 0      || y < 0 || 
             x0 >= WIDTH || x1 >= WIDTH || y >= HEIGHT)
            return;
        Uint8 r = 255, g = 0, b = 0;
        color = SDL_MapRGB( screen->format, r, g, b );
        int ytimesw = y*screen->pitch/BPP;
         
        for(int x = x0; x <= x1 ; x++){
            pixmem32 = (Uint32*) screen->pixels  + ytimesw + x;
            *pixmem32 = color;
        }
    }

void Plotter::fillRect(int x0, int y0, int width, int height){
        width --;
        for(int y = y0; y < y0+height; y++)
            setpoints(x0,x0+width,y);
    }

void Plotter::whiteout(){
    int x, y, ytimesw;
    color = SDL_MapRGB( screen->format, 255, 255, 255 );
    for(y = 0; y < screen->h; y++ )
    {
        ytimesw = y*screen->pitch/BPP;
        for( x = 0; x < screen->w; x++ )
        {
            pixmem32 = (Uint32*) screen->pixels  + ytimesw + x;
            *pixmem32 = color;
        }
    }
}

void Plotter::setpoint(int x, int y){
    y = HEIGHT - y;
    if ( x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
        return;
    Uint8 r = 0, g = 0, b = 0;
    color = SDL_MapRGB( screen->format, r, g, b );
    int ytimesw = y*screen->pitch/BPP;
    
    pixmem32 = (Uint32*) screen->pixels  + ytimesw + x;
    *pixmem32 = color;
}

void Plotter::lock(){
    if(SDL_MUSTLOCK(screen)){
        if(SDL_LockSurface(screen) < 0) return;
    }
}

void Plotter::unlock(){
    if(SDL_MUSTLOCK(screen))
        SDL_UnlockSurface(screen);
    SDL_Flip(screen);
}

void Plotter::swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

Plotter::Plotter(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ){
        cout << "Something went wrong and I wasn't able to initialize graphics. Quitting ..." << endl;
        exit(1);
    }
    
    if (!(screen = SDL_SetVideoMode(WIDTH, HEIGHT, DEPTH, SDL_SWSURFACE))){
        SDL_Quit();
        exit(1);
    }
    clear();
}

void Plotter::clear(){
    //lock();
    whiteout();
    //unlock();
}

void Plotter::drawPoint(int x, int y)
{
    //lock();
    setpoint(x, y);
    //unlock();
}

void Plotter::drawLine(int x0, int y0, int x1, int y1){
    //lock();
    if ( x1 < x0 ){
        swap(&x0,&x1);
        swap(&y0,&y1);
    }
    double deltax = x1 - x0;
    double deltay = y1 - y0;
    double error = 0;
    if ( deltax != 0 ){
        double deltaerr = abs (deltay / deltax);
        int y = y0;
        for(int x = x0; x <= x1 ; x++){
            setpoint(x,y);
            error = error + deltaerr;
            while (error >= 0.5){
                setpoint(x, y);
                y = y + ((y1 - y0) >=0 ? 1 : -1);
                error = error - 1.0;
            }
        }
    }
    else{
        if ( y1 < y0 ){
            swap(&x0,&x1);
            swap(&y0,&y1);
        }
        for(int y = y0; y <= y1 ; y ++){
            setpoint(x0,y);
        }
    }
    //unlock();
}

void Plotter::drawRect(int x0, int y0, int width, int height){
    width--;
    height--;
    drawLine(x0, y0, x0+width, y0);
    drawLine(x0+width,y0,x0+width,y0+height);
    drawLine(x0+width,y0+height,x0,y0+height);
    drawLine(x0, y0+height, x0, y0);
}

void Plotter::drawCircle(int x0, int y0, int radius){
    //lock();
    int x = radius;
    int y = 0;
    int radiusError = 1-x;
    
    while(x >= y)
    {
        setpoint( x + x0,  y + y0);
        setpoint( y + x0,  x + y0);
        setpoint(-x + x0,  y + y0);
        setpoint(-y + x0,  x + y0);
        setpoint(-x + x0, -y + y0);
        setpoint(-y + x0, -x + y0);
        setpoint( x + x0, -y + y0);
        setpoint( y + x0, -x + y0);
        y++;
        if (radiusError<0)
        {
            radiusError += 2 * y + 1;
        }
        else
        {
            x--;
            radiusError += 2 * (y - x) + 1;
        }
    }
    //unlock();
}

void Plotter::waitToClose(){
    int keypress = 0;
    while(!keypress)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT )
            {
                keypress = 1;
            }
        }
    }
    
    SDL_Quit();
}
void Plotter::close(){
    SDL_Quit();
}
