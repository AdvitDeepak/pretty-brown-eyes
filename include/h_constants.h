/* This file contains all constants used in the program.
 * Sensor/motor pins
 * Map/barrier distances
 * Coordinates of dropoff
*/

// First, we define our sensor pins

#define DCM_LF 1
#define DCM_LB 2
#define DCM_RF 3
#define DCM_RB 4

#define SVM_LC 5
#define SVM_RC 6

#define ULS_L1_T 7
#define ULS_L1_E 8

#define ULS_B1_T 9
#define ULS_B1_E 10

#define ULS_F1_T 11
#define ULS_F1_E 12
#define ULS_F2_T 13
#define ULS_F2_E 14

#define ULS_R1_T 15
#define ULS_R1_E 16
#define ULS_R2_T 17
#define ULS_R2_E 18

#define GYRS_M 19

// Next, our thresh constants for navigating thru barriers

#define SENSING_THRESH 5
#define DIST_FIRST_BARRIER 15
#define DIST_BTWN_BARRIERS 10
#define WIDTH_OF_BARRIER 5

#define LENGTH_STRAIGHT_AWAY 13
#define WIDTH_STRAIGHT_AWAY 45

// Finally, our thresh constants for object pickup/retreival

#define LENGTH_PICKUP_ZONE 10
#define WIDTH_PICKUP_ZONE 20
#define DROPOFF_ZONE_DIST_X 5
#define DROPOFF_ZONE_DIST_Y 5
