//A Sorting visualization program
//Author: Farrah Lee

#include "Plotter.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUMITEMS = 20;

void drawData(Plotter & p, int data[NUMITEMS]);

int main(){
    Plotter p; //This will display a window in which you can draw shapes
               //This window has width 640, and height 480 pixels.

    int data[NUMITEMS];


    //Putting random numbers into the array
    int r;
    for(int i = 0; i < NUMITEMS; i++){
        r = rand() % 400;
        data[i] = r;
    }

    //Now, we display the data array
    drawData(p, data);

    //Insertion Sort for the array
    for(int prefix = 2; prefix <= NUMITEMS; prefix ++){
        int newest = data[prefix-1];
        int position = prefix-2;

        while(position >= 0 && data[position] > newest){
            data[position+1] = data[position];
	        data[position] = newest; //Helps see the sorting on the display
            position = position - 1;

            //Drawing of a rectangle
            drawData(p, data);

            int sleep_time = (int)(1000000 * .5); // half a second wait
            usleep(sleep_time);
        }
        data[position+1] = newest;
    }

    //Leave these lines untouched.
    p.waitToClose();
    return 0;
}

void drawData(Plotter & p, int data[NUMITEMS]){
    p.lock();
    p.clear();

    int x[NUMITEMS];

    //Spacing between the rectangles
    for(int i = 0; i < NUMITEMS; i++){
        x[i] = i * 25;
    }

    //Drawing of rectangles
    for(int i = 0; i < NUMITEMS; i ++)
        p.drawRect(x[i], 0, 20, data[i]);
        //location of rectangle, 0, width of rectangle, height of rectangle
    p.unlock();
}
