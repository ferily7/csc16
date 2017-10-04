#include "mazemodel.h"
#include <iostream>
using namespace std;

//This function explores the next location listed in the nodequeue.
//NOTE: This function will be repeated called by another function.
//      It doesn't need a loop.
void MazeModel::exploreMore(){
    //1. If "solved == true" or the nodeQueue is empty, simply return.
    if(solved == true || nodeQueue.size() == 0){
        return;
    }
    //2. Remove the first location from the nodeQueue, and store it as "current."
    Location current = nodeQueue.dequeue();
    //3. Mark maze[current.row][current.col] as DEQUEUED
    maze[current.row][current.col] = DEQUEUED;
    //4. If the current location is the destination
    if(current == destination){
        solved = true;
        markSolution(current);
    }

    else{
    //   c. Location up = the location above current in the maze
        Location up;
        up.row = current.row - 1;
        up.col =  current.col;
    //   d. call mark(up, current) to add this "up" location to the nodeQueue
        mark(up, current);
    //   e. Location down = the location below current in the maze
        Location down;
        down.row = current.row + 1;
        down.col = current.col;
    //   f. Location left = the location to the left of current
        Location left;
        left.row = current.row;
        left.col = current.col - 1;
    //   g. Location right = the location to the right of current.
        Location right;
        right.row = current.row;
        right.col = current.col +1;
    //   h. call the mark function for down, left, and right (just as you did for "up")
        mark(down, current);
        mark(left, current);
        mark(right, current);
    }
}


//This function marks a location in the maze as QUEUED (ready to be explored).
void MazeModel::mark(Location loc, Location current){

    //Check if "loc" is a valid location in the maze (row and col are both OK)
    if(loc.row >= 0 && loc.col >= 0 && loc.row < SIZE && loc.col < SIZE){
    //Also, check to see that if maze[row][col] is OPEN
        if(maze[loc.row][loc.col] == OPEN){
    //If both checks pass, then do the following:
    // (a) add loc to the nodeQueue
            nodeQueue.enqueue(loc);
    // (b) Change this maze location from OPEN to QUEUED
            maze[loc.row][loc.col] = QUEUED;
    // (c) Set the predecessor of this location to current.
            predecessor[loc.row][loc.col] = current;
        }
    }
}

/****** The functions below this line are all complete ******/

void MazeModel::markSolution(Location current) //This function is complete
{
    while ( ! (predecessor[current.row][current.col] == current) ){
        maze[current.row][current.col] = SOLUTION;
        current = predecessor[current.row][current.col];
    }
    maze[current.row][current.col] = SOLUTION;
}

MazeModel::MazeModel()
{
    for(int i = 0; i < SIZE ; i++)
        for(int j = 0; j < SIZE ; j ++)
            maze[i][j] = OPEN;
    for(int i = 0 ; i < SIZE/2 - 1; i ++)
        maze[i][SIZE/2-1] = WALL;

    for(int i = SIZE/4 ; i < SIZE/2 - 1; i ++)
        maze[SIZE/2-1][i] = WALL;

    for(int i = 0 ; i < SIZE/2 - 2; i ++)
        maze[SIZE/2-3][i] = WALL;

    for(int i = 0 ; i < SIZE/4 - 1; i ++)
        maze[i][3*SIZE/4-1] = WALL;

    for(int i = 0 ; i < SIZE/4 - 1; i ++){
        maze[i][SIZE/4-1] = WALL;
        maze[i][SIZE/4-3] = WALL;
    }

    for(int i = SIZE/4-2 ; i < SIZE - 1; i ++)
        maze[i][3*SIZE/4-3] = WALL;

    Location center;
    center.col=SIZE/2;
    center.row=SIZE/2;
    mark(center, center);
    solved = false;
    destination.row = 0;
    destination.col = SIZE - 1;
}



int MazeModel::get(int row, int col)
{
    return maze[row][col];
}

void MazeModel::toggle(int row, int col)
{
    if ( maze[row][col] != WALL )
        maze[row][col] = WALL;
    else
        maze[row][col] = OPEN;
}

void MazeModel::initSearch()
{
    for(int i = 0; i < SIZE ; i ++)
        for(int j = 0; j < SIZE ; j ++)
            if ( maze[i][j] != WALL )
                maze[i][j] = OPEN;
    Location center;
    center.col=SIZE/2;
    center.row=SIZE/2;
    nodeQueue.clear();
    mark(center, center);
    solved = false;
}

Location MazeModel::getDestination()
{
    return destination;
}
