#include "mySDL/SDL.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;
const int BPP = 4;
const int DEPTH = 32;

struct point{
    int x, y;
};

class Plotter{
private:
    SDL_Surface *screen;
    SDL_Event event;
    Uint32 *pixmem32;
    Uint32 color;
    
    void whiteout(){
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
    
    void setpoint(int x, int y){
        if ( x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
            return;
        Uint8 r = 0, g = 0, b = 0;
        color = SDL_MapRGB( screen->format, r, g, b );
        int ytimesw = y*screen->pitch/BPP;
        
        pixmem32 = (Uint32*) screen->pixels  + ytimesw + x;
        *pixmem32 = color;
    }

    void lock(){
        if(SDL_MUSTLOCK(screen)){
            if(SDL_LockSurface(screen) < 0) return;
        }
    }
    
    void unlock(){
        if(SDL_MUSTLOCK(screen))
            SDL_UnlockSurface(screen);
        SDL_Flip(screen);
    }
    
    void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
public:
    Plotter(){
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
    
    void clear(){
        lock();
        whiteout();
        unlock();
    }
    
    void drawPoint(int x, int y)
    {
        lock();
        setpoint(x, y);
        unlock();
    }
    
    void drawLine(int x0, int y0, int x1, int y1){
        lock();
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
        unlock();
    }
    
    void drawRect(int x0, int y0, int width, int height){
        width--;
        height--;
        drawLine(x0, y0, x0+width, y0);
        drawLine(x0+width,y0,x0+width,y0+height);
        drawLine(x0+width,y0+height,x0,y0+height);
        drawLine(x0, y0+height, x0, y0);
    }
    
    void drawCircle(int x0, int y0, int radius){
        lock();
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
        unlock();
    }
    
    void drawPoly(const vector<point> & points){
        lock();
        for(int i = 0; i < points.size()-1; i ++){
            drawLine(points[i].x,points[i].y,points[i+1].x,points[i+1].y);
        }
        unlock();
    }
    
    void waitToClose(){
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
    void close(){
        SDL_Quit();
    }
};

void usage(){
    cout << "Allowed plot commands:" << endl
        << "window - Opens a plotting window\n"
        << "clear - Clears the plotting window\n"
        << "line x0 y0 x1 y1 - Draws a line segment between (x0,y0) and (x1,y1)\n"
        << "rect x0 y0 width height - Draws an axis parallel rectangle with top left (x0,y0)\n"
        << "circle x0 y0 radius - Draws a circle centered at (x0,y0) of given radius\n"
        << "poly n x1 y1 x2 y2 ... xn yn - Draws a n-sided polygon\n"
        << "quit - Exits the program\n";
}

int main(){
    Plotter * plotter;
    string option;
    plotter = 0;
    cout << "Plot> ";
    while ( cin >> option ){
        if ( option == "point" ){
            int x, y;
            cin >> x >> y;
            if ( plotter != 0 )
                plotter->drawPoint(x, y);
        }
        else if ( option == "clear" ){
            plotter->clear();
        }
        else if ( option == "line" ){
            int x0, y0, x1, y1;
            cin >> x0 >> y0;
            cin >> x1 >> y1;
            if ( plotter != 0 )
                plotter->drawLine(x0,y0,x1,y1);
        }
        else if ( option == "rect" ){
            int x0, y0, width, height;
            cin >> x0 >> y0;
            cin >> width >> height;
            if ( plotter != 0 )
                plotter->drawRect(x0, y0, width, height);
        }
        else if ( option == "circle" ){
            int x0, y0, radius;
            cin >> x0 >> y0 >> radius;
            if ( plotter != 0)
                plotter->drawCircle(x0, y0, radius);
        }
        else if ( option == "window" ){
            plotter = new Plotter;
        }
        else if ( option == "poly" ){
            int n;
            cin >> n;
            vector<point> points(n);
            for(int i = 0; i < n; i ++)
                cin >> points[i].x >> points[i].y;
            if ( plotter != 0 )
                plotter->drawPoly(points);
        }
        else if ( option == "quit" ){
            break;
        }
        else{
            usage();
        }
        cout << "Plot> ";
    }
    plotter->close();
}
