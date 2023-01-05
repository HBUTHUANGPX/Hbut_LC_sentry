#include <webots/distance_sensor.h>
#include <webots/motor.h>
#include <webots/robot.h>
#define TIME_STEP 64
int main(int argc, char **argv) {
  wb_robot_init();
  int i;
  WbDeviceTag wheels[4];
  char wheels_names[4][8] = {"f_l_j", "f_r_j", "b_l_j", "b_r_j"};
  for (i = 0; i < 4; i++) {
    wheels[i] = wb_robot_get_device(wheels_names[i]);
    wb_motor_set_position(wheels[i], INFINITY);
  }
  while (wb_robot_step(TIME_STEP) != -1) {
    // init speeds
    double fl = 1.0;
    double fr = 1.0;
    double bl = 1.0;
    double br = 1.0;
    wb_motor_set_velocity(wheels[0], fl);
    wb_motor_set_velocity(wheels[1], fr);
    wb_motor_set_velocity(wheels[2], bl);
    wb_motor_set_velocity(wheels[3], br);
  }
  wb_robot_cleanup();
  return 0;  // EXIT_SUCCESS
}
