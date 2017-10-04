#if defined(__x86_64__)
#include <SDL/SDL.h>
#else
#include "mySDL/SDL.h"
#endif

const int WIDTH = 640;
const int HEIGHT = 480;
const int BPP = 4;
const int DEPTH = 32;

class Plotter{
private:
    SDL_Surface *screen;
    SDL_Event event;
    Uint32 *pixmem32;
    Uint32 color;
    
    void whiteout();
    void setpoint(int x, int y);
    void swap(int *a, int *b);
    void setpoints(int x0, int x1, int y);
public:
    Plotter();
    void clear();
    void lock();
    void unlock();
    void drawPoint(int x, int y);
    void drawLine(int x0, int y0, int x1, int y1);
    void drawRect(int x0, int y0, int width, int height);
    void fillRect(int x0, int y0, int width, int height);
    void drawCircle(int x0, int y0, int radius);
    void waitToClose();
    void close();
};
