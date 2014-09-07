/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#define MAX_CLOCK_DIVIDER 400
#define MIN_CLOCK_DIVIDER 4
#define CLOCK_SPEED_CHANGE_DELAY_US 2000

#define LEFT_MOTOR_BITMASK 1
#define RIGHT_MOTOR_BITMASK 2
#define MICRO_STEP_FACTOR 1
#define MAX_CLOCK_SPEED 24000000
#define MAX_FULL_STEP_FREQUENCY 23000 //23Khz step pulse rate at full-step.
#define MIN_FULL_STEP_FREQUENCY 230

typedef struct {
    int motorLeftSpeed; // between 0-100
    int motorRightSpeed;
    short motorLeftDir;  // either 0 or 1
    short motorRightDir; // 0 = forward, 1 = backwards
   } motorParameters;

typedef struct {
    uint16 clockDivider; // What to divide the clock
    uint8 pwmPeriodCounter; // what the period counter will be ( a divider )
    uint32 frequecy; // What's the frequency for this divider set?
} motorDividers;

typedef struct  {

    motorDividers motorLeft;
    motorDividers motorRight;
} motorState;
extern motorDividers g_stateMap[101]; 
extern volatile motorParameters g_motorStateCurrent;
extern volatile motorParameters g_motorStateTarget;

/* [] END OF FILE */
