// robocop.h
#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "humanic.h"

// derived class for robocop robots
class robocop : public humanic {
  public:
    // constructor that calls base class constructor
    robocop(int newType, int newStrength, int newHit, string newName);
    
    // override the getType function
    string getType();
    
    // no need to override the getDamage function as it is the same as the base class
};

#endif