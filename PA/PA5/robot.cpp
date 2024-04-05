// robot.cpp
#include "robot.h"
#include <cstdlib>
#include <iostream>
using namespace std;

// default constructor
Robot::Robot() {
  strength = 0;
  hitpoints = 0;
  name = "";
  moved = false;
}

// parameterized constructor
Robot::Robot(int newType, int newStrength, int newHit, string newName) {
  strength = newStrength;
  hitpoints = newHit;
  name = newName;
  moved = false;
}

// accessor functions
int Robot::getStrength() {
  return strength;
}

int Robot::getHitpoints() {
  return hitpoints;
}

string Robot::getName() {
  return name;
}

bool Robot::hasMoved() {
  return moved;
}

// mutator functions
void Robot::setStrength(int newStrength) {
  strength = newStrength;
}

void Robot::setHitpoints(int newHit) {
  hitpoints = newHit;
}

void Robot::setName(string newName) {
  name = newName;
}

void Robot::setMoved(bool flag) {
  moved = flag;
}

// virtual function to get type
string Robot::getType() {
  return "unknown";
}

// virtual function to get damage
int Robot::getDamage() {
  // All robots inflict damage which is a
  // random number up to their strength
  int damage = (rand() % strength) + 1;
  cout << getType() << " attacks for " << damage << " points!" << endl;
  return damage;
}
