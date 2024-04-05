// bulldozer.h
#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "robot.h"

// derived class for bulldozer robots
class bulldozer : public Robot {
  public:
    // constructor that calls base class constructor
    bulldozer(int newType, int newStrength, int newHit, string newName);
    
    // override the getType function
    string getType();
    
    // no need to override the getDamage function as it is the same as the base class
};

#endif