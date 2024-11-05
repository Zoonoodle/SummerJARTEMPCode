using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Motor3;
extern motor Motor7;
extern motor Motor13;

extern motor Motor18;
extern motor Motor14;
extern motor Motor2;


extern motor intake1;
extern motor intake2;
extern motor_group intakeMotors;

extern optical visionSensor;
extern digital_out mogoMech;
extern digital_out doinker;

extern int blueMin;
extern int blueMax;
extern int redMin;
extern int redMax;
extern int allianceMin;
extern int allianceMax;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );