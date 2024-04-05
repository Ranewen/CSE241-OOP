// roomba.cpp
#include "roomba.h"
#include <iostream>
using namespace std;

// constructor that calls base class constructor
roomba::roomba(int newType, int newStrength, int newHit, string newName) : Robot(newType, newStrength, newHit, newName) {
  // nothing to do here
}

// override the getType function
string roomba::getType() {
  return "roomba";
}

// override the getDamage function
int roomba::getDamage() {
  // call the base class getDamage function twice
  int damage = Robot::getDamage() + Robot::getDamage();
  
  // print the total damage
  cout << "Total damage: " << damage << endl;
  
  return damage;
}
