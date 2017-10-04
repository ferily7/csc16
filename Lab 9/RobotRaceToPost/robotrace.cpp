#include "robotrace.h"
#include <QDebug>

RobotRace::RobotRace(int N){
    numRobots = N;
    robots = new Robot* [numRobots];
    for(int i=0; i < numRobots; i++){
        robots[i] = new Robot;
    }
}

void RobotRace::resetRace(){
    for(int i=0; i<numRobots; i++){
        robots[i]->resetRobot();
    }
}

void RobotRace::update(){
    for(int i=0; i<numRobots; i++){
       robots[i]->update();
    }
}

bool RobotRace::hasWinner(int & winner){
    for(int i=0; i<numRobots; i++){
        if(robots[i]->getPosition() == 100){
            robots[i] = robots[winner];
            return true;
        }
    }
    return false;
}

int RobotRace::getRobotPos(int i){
    return robots[i]->getPosition();
}

int RobotRace::getNumRobots(){
    return numRobots;
}

int RobotRace::getLeader(){
    int leader = 0;
    for(int i = 0; i < numRobots; i ++){
        if ( robots[i]->getPosition() > robots[leader]->getPosition()){
            leader = i;
        }
    }
    return leader;
}
