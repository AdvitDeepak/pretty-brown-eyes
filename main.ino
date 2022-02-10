// TODO: USE https://github.com/patou01/HC-SR04/blob/master/examples/HC04_example/HC04_example.ino
// TODO: SHOULD USE THAT FOR ULTRASONIC SENSOR INSTEAD ^^

// TODO: https://github.com/adafruit/Adafruit_MPU6050/tree/master/examples
// TODO: SHOULD USE THAT FOR GYROSCOPIC SENSOR INSTEAD ^^

// TODO: https://github.com/ababikir/UCSD_PIB_SLAMBot/blob/master/SLAMbot_FINAL_Arduino_Code/SLAMbot_FINAL_Arduino_Code.ino
// TODO: SHOULD USE THAT FOR MAPPING ENVIRONMENT w/ ULS, GYRO ^^

// TODO: https://github.com/paramaggarwal/pingray/blob/master/pingray.ino
// TODO: CAN USE THIS FOR MAPPING ENVIRONMENT ^^

#include <Servo.h>
#include <Wire.h>

#include "include/h_constants.h"
#include "include/h_gyro_ultra.h"
#include "include/h_movement.h"

/* Our rover utilizes the following components:
 * - 4 DC motors, 2 drive left and 2 drive right
 * - 2 Servo Motors, 1 left claw and 1 right claw
 * - 6 Ultrasonic Sensors, 2 front, 2 left, 2 right
 * - 1 Gyroscopic Sensor, mounted in the middle
*/

Servo ServoL; Servo ServoR;

float pos[3] = {0, 0, 0}; // lr-disp (cm), fb-disp (cm), angle change (deg)
float xyg[7] = {0, 0, 0, 0, 0, 0, 0} // uls (1-6), angle (7)

// Initializes all sensor/motor pins
void setup()
{
  // First, initialize motor pins
  pinMode(DCM_LF, OUTPUT); pinMode(DCM_LB, OUTPUT);
  pinMode(DCM_RF, OUTPUT); pinMode(DCM_RB, OUTPUT);

  // Next, initialize servo pins
  ServoL.attach(SVM_LC);
  ServoR.attach(SVM_RC);

  // Next, initialize ultrasonic pins
  pinMode(ULS_L1_T, OUTPUT); pinMode(ULS_L1_E, INPUT);
  pinMode(ULS_L2_T, OUTPUT); pinMode(ULS_L2_E, INPUT);
  pinMode(ULS_F1_T, OUTPUT); pinMode(ULS_F1_E, INPUT);
  pinMode(ULS_F2_T, OUTPUT); pinMode(ULS_F2_E, INPUT);
  pinMode(ULS_R1_T, OUTPUT); pinMode(ULS_R1_E, INPUT);
  pinMode(ULS_R2_T, OUTPUT); pinMode(ULS_R2_E, INPUT);

  // Next, intiialize gyro pins
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(GYRS_M);    // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);

  // Lastly, begin serial
  Serial.begin(9600);

  // Then, start with disp/map initialization

  xyg = sense()
  pos[0] += xyg[3]; pos[1] += xyg[4];

  init_map()
  update_map(xyg)
}

bool movingForward; bool movingBackward;
bool turningLeft; bool turningRight;

bool detectedObj; bool retrievedObj;

// Main loop that is run after setup
void loop()
{

  if (pos[0] + SENSING_THRESH < DIST_FIRST_BARRIER)
  {
    // Means we are still in the straightaway
    if (!movingForward) { forward(); }
  }
  else if (pos[0] + SENSING_THRESH < LENGTH_STRAIGHT_AWAY)
  {
    // Means we are navigating through barriers
    // TODO: INSERT CODE FOR NAVIGATING BARRIERS
  }
  else if (pos[0] + SENSING_TRESH < LENGTH_STRAIGHT_AWAY + LENGTH_SEARCH)
  {
    // Means we are now in the search area
    if (!detectedObj)
    {
      // TODO: Continue moving/sensing until detectedObj
    }
    else if (!retrievedObj)
    {
      // TODO: Continue moving towards object/close claw until retrieved
    }
    else if (!atDropoff(pos))
    {
      // TODO: Continue moving towards dropoff zone until we're in the right place
    }
    else
    {
      // TODO: Release claw, move backwards, celebrate
      exit(0) // Exit program
    }
  }

  update_map()
}
