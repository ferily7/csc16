#ifndef ROBOTRACE_H
#define ROBOTRACE_H
#include "robot.h"

class RobotRace{
private:
    Robot ** robots;
    int numRobots;
public:
    RobotRace(int N);
    void resetRace();
    void update();
    bool hasWinner(int & winner);
    int getRobotPos(int i);
    int getNumRobots();
    int getLeader();
};

#endif // ROBOTRACE_H
