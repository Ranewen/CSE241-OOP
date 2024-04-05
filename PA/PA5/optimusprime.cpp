// optimusprime.cpp
#include "optimusprime.h"
#include <cstdlib>
#include <iostream>
using namespace std;

// constructor that calls base class constructor
optimusprime::optimusprime(int newType, int newStrength, int newHit, string newName) : humanic(newType, newStrength, newHit, newName) {
  // nothing to do here
}

// override the getType function
string optimusprime::getType() {
  return "optimusprime";
}

// override the getDamage function
int optimusprime::getDamage() {
  // call the base class getDamage function
  int damage = humanic::getDamage();
  
  // with a 15% chance, inflict a strong attack that doubles the normal damage
  if ((rand() % 100) < 15) {
    cout << "Strong attack!" << endl;
    damage *= 2;
  }
  
  return damage;
}
