// robot.h
#ifndef ROBOT_H
#define ROBOT_H

#include <string>
using namespace std;

// base class for all types of robots
class Robot {
  private:
    int strength; // the maximum damage a robot can inflict
    int hitpoints; // the health of a robot
    string name; // the name of a robot
    bool moved; // a flag to indicate if a robot has moved in a step
  public:
    // default constructor
    Robot();
    
    // parameterized constructor
    Robot(int newType, int newStrength, int newHit, string newName);
    
    // accessor functions
    int getStrength();
    int getHitpoints();
    string getName();
    bool hasMoved();
    
    // mutator functions
    void setStrength(int newStrength);
    void setHitpoints(int newHit);
    void setName(string newName);
    void setMoved(bool flag);
    
    // virtual function to get type
    virtual string getType();
    
    // virtual function to get damage
    virtual int getDamage();
};

#endif