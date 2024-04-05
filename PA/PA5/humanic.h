// humanic.h

#ifndef HUMANIC_H
#define HUMANIC_H

// include robot.h
#include "robot.h"

// define humanic as a derived class of robot using public inheritance
class humanic : public Robot
{
  // declare public methods for humanic
  public:
    // declare a constructor that calls the base class constructor
    humanic(int newType, int newStrength, int newHitpoints, string newName);

    // override the getType function
    string getType() override;

    // override the getDamage function
    int getDamage() override; 
};

#endif