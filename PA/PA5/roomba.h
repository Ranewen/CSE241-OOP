// roomba.h
#ifndef ROOMBA_H
#define ROOMBA_H

#include "robot.h"

// derived class for roomba robots
class roomba : public Robot {
  public:
    // constructor that calls base class constructor
    roomba(int newType, int newStrength, int newHit, string newName);
    
    // override the getType function
    string getType();
    
    // override the getDamage function
    int getDamage();
};

#endif