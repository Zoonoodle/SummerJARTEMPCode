#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1               motor         1               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
TANK_ONE_ROTATION,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(Motor3, Motor7, Motor13),

//Right Motors:
motor_group(Motor18, Motor14, Motor2),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT4,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
2.75,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.8,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
PORT5,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-1,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int color_sorting_task() {
  while (true) {
    allianceMin = blueMin;  
    allianceMax = blueMax;  

    visionSensor.setLightPower(50, pct);
    visionSensor.setLight(ledState::on);

  
   if (visionSensor.hue() >= allianceMin && visionSensor.hue() <= allianceMax  && visionSensor.isNearObject()) {
          wait(5, msec);
          intakeMotors.stop();
          wait(200, msec);
          intakeMotors.spin(forward, 100, pct);
    }
    



    wait(20, msec); 
  }
  return 0;  
}

int current_auton_selection = 2;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "Drive Test");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "Drive Test");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Turn Test");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Swing Test");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Full Test");
        break;
      case 5:
        Brain.Screen.printAt(50, 50, "Odom Test");
        break;
      case 6:
        Brain.Screen.printAt(50, 50, "Tank Odom Test");
        break;
      case 7:
        Brain.Screen.printAt(50, 50, "Holonomic Odom Test");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  task color_sort_task(color_sorting_task);
  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      

      
      visionSensor.setLight(ledState::on);

  
      default_constants();
      chassis.drive_max_voltage = 10;
         chassis.drive_max_voltage = 10;
      chassis.drive_distance(-39);
      chassis.turn_to_angle(37.5);
      mogoMech = true;
      chassis.drive_max_voltage = 5;
      chassis.drive_distance(-13.5);
      
      wait(50, msec);
      mogoMech = false;
      chassis.drive_max_voltage = 7;
      wait(650, msec);
      intakeMotors.spin(forward, 100, pct);
      
      chassis.turn_to_angle(-10);
      
      chassis.drive_distance(15);
      

      // Check the color and control the intake motors
      // if (visionSensor.hue() >= aianceMin && visionSensor.hue() <= allianceMax && visionSensor.isNearObject()) {
      //     intake1.setVelocity(100, pct);
      //     intake2.setVelocity(75, pct);
      //     intakeMotors.spinFor(forward, 0.05, sec);
      //     intakeMotors.spinFor(reverse, 0.12, sec);
      // }

      wait(580, msec);
      mogoMech = true;
      wait(50, msec);
      chassis.turn_to_angle(270);
      chassis.drive_max_voltage = 5;
      intakeMotors.stop();
      chassis.drive_distance(-22);
      mogoMech = false;
      wait(500 , msec);
      chassis.drive_max_voltage = 11;

      chassis.turn_to_angle(48);
      
      chassis.drive_distance(20);
      intakeMotors.spin(forward, 100, pct);
      // if (visionSensor.hue() >= allianceMin && visionSensor.hue() <= allianceMax && visionSensor.isNearObject()) {
      //     intake1.setVelocity(100, pct);
      //     intake2.setVelocity(75, pct);
      //     intakeMotors.spinFor(forward, 0.05, sec);
      //     intakeMotors.spinFor(reverse, 0.12, sec);
      // }
      
      chassis.drive_max_voltage = 4;
      chassis.drive_distance(15);
      wait(200, msec);
      chassis.drive_distance(-5);
      intakeMotors.spin(forward, 100, pct);
      chassis.drive_distance(15);

      
      chassis.drive_max_voltage =10;
      chassis.drive_distance(-10);
      chassis.turn_to_angle(180);
      
      
      chassis.drive_max_voltage = 6;
      chassis.drive_distance(15);
     
      intakeMotors.stop();
      mogoMech = true;


      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      drive_test();
      break;
    case 2:
      odom_constants();
      odom.set_position(0,0,0);

      odom.update_position(10, 10, 0);
      
            break;
    case 3:
      swing_test();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    controller Controller1 = controller(primary);
    allianceMin = blueMin;
      allianceMax = blueMax;
      
      Brain.Screen.printAt(50, 50, "Detected Hue: %d", visionSensor.hue());
      visionSensor.setLightPower(50, pct);
      visionSensor.setLight(ledState::on);
      bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;
      
     
        // if(visionSensor.hue() >= allianceMin && visionSensor.hue() <= allianceMax && visionSensor.isNearObject()) {

        //   wait(50, msec);
        //   intakeMotors.stop();
        //   wait(175, msec);
          
        // }
        if (visionSensor.hue() >= allianceMin && visionSensor.hue() <= allianceMax  && visionSensor.isNearObject()) {
          wait(20, msec);
          intakeMotors.stop();
          wait(200, msec);
    }

    // if( visionSensor.hue() >= 0 && visionSensor.hue() <= allianceMax && visionSensor.isNearObject()) {
    //       wait(20, msec);
    //       intakeMotors.stop();
    //       wait(200, msec);
    // }
          
        
            
          
          
      
      
      if(Controller1.ButtonX.pressing()) {
         mogoMech = true;
               
          
      }
      if(Controller1.ButtonA.pressing()) {
        mogoMech = false;
      }
        if(Controller1.ButtonL2.pressing()) {
         doinker = true;
               
          
      }
      if(Controller1.ButtonL1.pressing()) {
        doinker = false;
      }
 

      
      
    

    


   
    
      if (Controller1.ButtonR2.pressing()) {
       intake1.setVelocity(100, pct);
       intake2.setVelocity(100, pct);
        intakeMotors.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR1.pressing()) {
        intake1.setVelocity(100, pct);
        intake2.setVelocity(100, pct);
        intakeMotors.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else {
        intakeMotors.stop();
      }

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_arcade();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
