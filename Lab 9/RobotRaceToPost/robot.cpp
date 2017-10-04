#include "robot.h"

Robot::Robot(){
    position = 0;
}

void Robot::resetRobot(){
    position = 0;
}

void Robot::update(){  //Use the qrand() function instead of rand() in here.
    int r = qrand() % 6;
    position = position + r;

    if(position > 100){
        position = 100;
    }
}

int Robot::getPosition(){
    return position;
}
