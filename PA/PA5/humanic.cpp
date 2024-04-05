#include "humanic.h" 
#include <cstdlib> 
#include <iostream> 
using namespace std;

// constructor that calls base class constructor 
humanic::humanic(int newType, int newStrength, int newHitpoints, string newName) : Robot(newType, newStrength, newHitpoints, newName) { // use member initializer list to pass newType to base class constructor
  // nothing to do here
}

// override the getType function
string humanic::getType() 
{ 
 return "humanic"; 
}    

// Override the getDamage function 
int humanic::getDamage()
{ 
 // Call the base class function to get the basic damage 
 int damage = Robot::getDamage(); 
 // Humanic robots have a 10% chance of inflicting a tactical nuke attack which is an additional 50 damage points 
 if (rand() % 10 == 0) 
 { 
 cout << "Tactical nuke attack!" << endl; 
 damage += 50; 
 } 
 return damage; 
}
