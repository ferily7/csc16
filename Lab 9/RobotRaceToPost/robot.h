#ifndef ROBOT_H
#define ROBOT_H
#include <Qt>

class Robot{
private:
    int position;
public:
    Robot();
    void resetRobot();
    void update();
    int getPosition();
};

#endif // ROBOT_H
