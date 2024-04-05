// robocop.cpp
#include "robocop.h"

// constructor that calls base class constructor
robocop::robocop(int newType, int newStrength, int newHit, string newName) : humanic(newType, newStrength, newHit, newName) {
  // nothing to do here
}

// override the getType function
string robocop::getType() {
  return "robocop";
}

// no need to override the getDamage function as it is the same as the base class
