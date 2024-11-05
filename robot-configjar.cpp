#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Motor3 = motor(PORT3, ratio6_1, true);
motor Motor7 = motor(PORT7, ratio6_1, true);
motor Motor13 = motor(PORT13, ratio6_1, false);

motor Motor18 = motor(PORT18, ratio6_1, false);
motor Motor14 = motor(PORT14, ratio6_1, false);
motor Motor2 = motor(PORT1, ratio6_1, true);


motor intake1 = motor(PORT21, ratio6_1, false);
motor intake2 = motor(PORT16, ratio6_1, true);
motor_group intakeMotors = motor_group(intake1, intake2);

optical visionSensor = optical(PORT11);
digital_out mogoMech(Brain.ThreeWirePort.B);
digital_out doinker(Brain.ThreeWirePort.E);

int blueMin = 170;
int blueMax = 225 ;
int redMin = 350;
int redMax = 20;
int allianceMin;
int allianceMax;
// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}