#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <webots/Keyboard.hpp>
#include <stdio.h>

#define TIME_STEP 64
// All the webots classes are defined in the "webots" namespace
using namespace webots;
 
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();
  Keyboard kb;

  // initialise motors
  Motor *wheels[4];
  char wheels_names[4][8] = {"f_l_j", "f_r_j", "b_l_j", "b_r_j"};
  for (int i = 0; i < 4; i++) {
    wheels[i] = robot->getMotor(wheels_names[i]);
    wheels[i]->setPosition(INFINITY);
    wheels[i]->setVelocity(0);
  }
  printf("init successd ...\n");
  
  kb.enable(TIME_STEP);
  double leftSpeed = 0.0;
  double rightSpeed = 0.0;

   // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(TIME_STEP) != -1)
   {
    int key = kb.getKey();
    std::cout<<" key value= "<<key<<std::endl;
    if(key== 315)
    {
      leftSpeed = 3.0;
      rightSpeed = 3.0;
    }
    else if(key== 317)
    {
      leftSpeed = -3.0;
      rightSpeed = -3.0;
    }
    else if(key== 314)
    {
      leftSpeed = -3.0;
      rightSpeed = 3.0;
    }
    else if(key== 316)
    {
      leftSpeed = 3.0;
      rightSpeed = -3.0;
    }
    else  
    {
      leftSpeed = 0.0;
      rightSpeed = 0.0;
    }
     wheels[0]->setVelocity(leftSpeed);
     wheels[1]->setVelocity(rightSpeed);
     wheels[2]->setVelocity(leftSpeed);
     wheels[3]->setVelocity(rightSpeed);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}

