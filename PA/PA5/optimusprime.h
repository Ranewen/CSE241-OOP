// optimusprime.h
#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include "humanic.h"

// derived class for optimusprime robots
class optimusprime : public humanic {
  public:
    // constructor that calls base class constructor
    optimusprime(int newType, int newStrength, int newHit, string newName);
    
    // override the getType function
    string getType();
    
    // override the getDamage function
    int getDamage();
};

#endif