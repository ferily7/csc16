//Draw and move some rectangles around.
#include "Plotter.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int RWIDE = 20; //width of each rectangle

    int h[3]; //Heights of 3 rectangles
    int x[3]; //X coordinates of 3 rectangles

    Plotter p;

    h[0] = 20;
    h[1] = 40;
    h[2] = 60;

    x[0] = 0;
    x[1] = 50;
    x[2] = 100;

    //Here is how we draw them
    //
    p.lock();

    for(int i = 0; i < 3; i ++)
        p.drawRect(x[i], 0, RWIDE, h[i]);

    p.unlock();

    
    for(int i = 0; i < 10  ; i ++ )
    {
        x[0] = x[0] + 10;
        x[1] = x[1] - 5;
        x[2] = x[2] - 10;

        p.lock();
        p.clear(); //clear out the window

        for(int i = 0; i < 3; i ++)
            p.drawRect(x[i], 0, RWIDE, h[i]);
        p.unlock();

        int sleep_time = (int)(1000000 * .5); // half a second wait
        usleep(sleep_time);
    }
    p.waitToClose();
}

