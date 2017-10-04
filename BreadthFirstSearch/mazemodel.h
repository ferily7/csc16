#ifndef MAZEMODEL_H
#define MAZEMODEL_H
#include "queue.h"
#include "location.h"

class MazeModel{

public:
    static const int SIZE = 20;
private:
    int maze[SIZE][SIZE];
    Location predecessor[SIZE][SIZE];
    Queue nodeQueue;
    bool solved;
    Location destination;
    void mark(Location loc, Location current);
    void markSolution(Location current);
public:
    static const int OPEN = 0;
    static const int WALL = 1;
    static const int QUEUED = 2;
    static const int DEQUEUED = 3;
    static const int SOLUTION = 4;
    MazeModel();
    void exploreMore();
    int get(int row, int col);
    void toggle(int row, int col);
    void initSearch();
    Location getDestination();
};

#endif // MAZEMODEL_H
