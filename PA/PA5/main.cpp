// main.cpp
#include <iostream>
#include "Robot.h"
#include "bulldozer.h"
#include "humanic.h"
#include "optimusprime.h"
#include "robocop.h"
#include "roomba.h"
using namespace std;

// function prototypes
void createRobots(Robot* robots[], int size); // create an array of robot pointers
void placeRobots(Robot* robots[], int size, Robot* grid[][10]); // place the robots randomly on a 10x10 grid
void simulate(Robot* robots[], int size, Robot* grid[][10]); // simulate the robot movements and fights until one survives
void fight(Robot* attacker, Robot* victim); // make two robots fight until one dies
void hitMessage(Robot* attacker, Robot* victim, int damage); // print the hit message
void deathMessage(Robot* robot); // print the death message

int main() {
  // create an array of 20 robot pointers
  Robot* robots[20];
  createRobots(robots, 20);

  // create a 10x10 grid of robot pointers initialized to NULL
  Robot* grid[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      grid[i][j] = NULL;
    }
  }

  // place the robots randomly on the grid
  placeRobots(robots, 20, grid);

  // simulate the robot movements and fights until one survives
  simulate(robots, 20, grid);

  return 0;
}

// function definitions

// create an array of robot pointers
void createRobots(Robot* robots[], int size) 
{
  // create five optimusprime robots with strength 100 and hitpoints 100
  for (int i = 0; i < 5; i++) 
  {
    string name = "optimusprime_" + to_string(i);
    robots[i] = new optimusprime(0, 100, 100, name);
  }
  // create five robocop robots with strength 30 and hitpoints 40
  for (int i = 5; i < 10; i++) {
    string name = "robocop_" + to_string(i - 5);
    robots[i] = new robocop(1, 30, 40, name);
  }
  // create five roomba robots with strength 3 and hitpoints 10
  for (int i = 10; i < 15; i++) {
    string name = "roomba_" + to_string(i - 10);
    robots[i] = new roomba(2, 3, 10, name);
  }
  // create five bulldozer robots with strength 50 and hitpoints 200
  for (int i = 15; i < 20; i++) {
    string name = "bulldozer_" + to_string(i - 15);
    robots[i] = new bulldozer(3, 50, 200, name);
  }
}

// place the robots randomly on the grid
void placeRobots(Robot* robots[], int size, Robot* grid[][10]) {
  // initialize the random seed
  srand(time(NULL));
  
  // loop through the robot array
  for (int i = 0; i < size; i++) {
    // generate random row and column indices
    int row = rand() % 10;
    int col = rand() % 10;
    
    // check if the grid cell is empty
    if (grid[row][col] == NULL) {
      // place the robot on the grid
      grid[row][col] = robots[i];
    }
    else {
      // decrement i to retry placing the robot
      i--;
    }
  }
}

// simulate the robot movements and fights until one survives
void simulate(Robot* robots[], int size, Robot* grid[][10]) {
  // initialize the random seed
  srand(time(NULL));
  
  // initialize a variable to count the number of alive robots
  int alive = size;
  
  // loop until only one robot is alive
  while (alive > 1) {
    // loop through the grid rows
    for (int i = 0; i < 10; i++) {
      // loop through the grid columns
      for (int j = 0; j < 10; j++) {
        // check if the grid cell has a robot
        if (grid[i][j] != NULL) {
          // get the robot pointer
          Robot* robot = grid[i][j];
          
          // check if the robot has not moved in this step
          if (!robot->hasMoved()) {
            // set the robot's moved flag to true
            robot->setMoved(true);
            
            // generate a random direction to move (0: up, 1: right, 2: down, 3: left)
            int dir = rand() % 4;
            
            // initialize new row and column indices
            int newRow = i;
            int newCol = j;
            
            // update the new row and column indices according to the direction
            switch (dir) {
              case 0:
                newRow--;
                break;
              case 1:
                newCol++;
                break;
              case 2:
                newRow++;
                break;
              case 3:
                newCol--;
                break;
            }
            
            // check if the new row and column indices are valid and within the grid bounds
            if (newRow >= 0 && newRow < 10 && newCol >= 0 && newCol < 10) {
              // check if the new grid cell is empty
              if (grid[newRow][newCol] == NULL) {
                // move the robot to the new grid cell
                grid[newRow][newCol] = robot;
                
                // set the old grid cell to NULL
                grid[i][j] = NULL;
              }
              else {
                // get the other robot pointer
                Robot* other = grid[newRow][newCol];
                
                // make the robots fight until one dies
                fight(robot, other);
                
                // check which robot is dead
                if (robot->getHitpoints() <= 0) {
                  // print the death message for robot
                  deathMessage(robot);
                  
                  // set the old grid cell to NULL
                  grid[i][j] = NULL;
                  
                  // decrement the number of alive robots
                  alive--;
                }
                else if (other->getHitpoints() <= 0) {
                  // print the death message for other
                  deathMessage(other);
                  
                  // move the robot to the new grid cell
                  grid[newRow][newCol] = robot;
                  
                  // set the old grid cell to NULL
                  grid[i][j] = NULL;
                  
                  // decrement the number of alive robots
                  alive--;
                }
              }
            }
          }
        }
      }
    }
    
    // reset the moved flag for all robots at the end of each step
    for (int i = 0; i < size; i++) {
      robots[i]->setMoved(false);
    }
    
    // print a newline to separate each step
    cout << endl;
  }
  
  // loop through the robot array to find the survivor
  for (int i = 0; i < size; i++) {
    // check if the robot is alive
    if (robots[i]->getHitpoints() > 0) {
      // print the survivor message
      cout << "The survivor is " << robots[i]->getName() << "!" << endl;
      break;
    }
}
}
    // make two robots fight until one dies
void fight(Robot* attacker, Robot* victim) {
  // loop until one of the robots dies
  while (attacker->getHitpoints() > 0 && victim->getHitpoints() > 0) {
    // get the damage inflicted by the attacker
    int damage = attacker->getDamage();
    
    // reduce the hitpoints of the victim by the damage
    victim->setHitpoints(victim->getHitpoints() - damage);
    
    // print the hit message
    hitMessage(attacker, victim, damage);
    
    // check if the victim is dead
    if (victim->getHitpoints() <= 0) {
      // return from the function
      return;
    }
    
    // swap the roles of attacker and victim
    Robot* temp = attacker;
    attacker = victim;
    victim = temp;
  }
}

// print the hit message
void hitMessage(Robot* attacker, Robot* victim, int damage) {
  // print the name and hitpoints of the attacker and the victim
  cout << attacker->getName() << "(" << attacker->getHitpoints() << ") hits "
       << victim->getName() << "(" << victim->getHitpoints() << ") with " << damage << endl;
  
  // print the new hitpoints of the victim
  cout << "The new hitpoints of " << victim->getName() << " is " << victim->getHitpoints() << endl;
}

// print the death message
void deathMessage(Robot* robot) {
  // print the name and type of the robot
  cout << robot->getName() << " (" << robot->getType() << ") is dead!" << endl;
}


  

