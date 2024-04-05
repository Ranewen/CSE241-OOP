// bulldozer.cpp
#include "bulldozer.h"

// constructor that calls base class constructor
bulldozer::bulldozer(int newType, int newStrength, int newHit, string newName) : Robot(newType, newStrength, newHit, newName) {
  // nothing to do here
}

// override the getType function
string bulldozer::getType() {
  return "bulldozer";
}

// no need to override the getDamage function as it is the same as the base class
