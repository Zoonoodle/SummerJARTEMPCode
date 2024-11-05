#include "vex.h"

void default_constants(){
  //max voltage, kp, ki, kd, starti
  
  chassis.set_drive_constants(11,6.1 ,0.01, 45.3, 0);
  chassis.set_heading_constants(10, 0.7, 0.03 , 4.3, 0);
  chassis.set_turn_constants(11, 0.89, 0, 6.14, 15);
  chassis.set_swing_constants(6, 9, 0.001, 55, 0);
  // float drive_settle_error, float drive_settle_time, float drive_timeout) 
   chassis.set_drive_exit_conditions(3.1, 400, 4000);
    chassis.set_turn_exit_conditions(3, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 500);
  
  chassis.set_coordinates(47, -55, 0);
 
}

void slow_constants(){
  //max voltage, kp, ki, kd, starti
  
  chassis.set_drive_constants(10,6.1 ,0.01, 100, 0);
  chassis.set_heading_constants(10, 0.7, 0.03 , 4.3, 0);
  chassis.set_turn_constants(11, 0.89, 0, 6.14, 15);
  chassis.set_swing_constants(6, 9, 0.001, 55, 0);
  // float drive_settle_error, float drive_settle_time, float drive_timeout) 
   chassis.set_drive_exit_conditions(3.1, 400, 4000);
    chassis.set_turn_exit_conditions(3, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 500);
  
  chassis.set_coordinates(47, -55, 0);
 
}

void colorSort() {

}

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}