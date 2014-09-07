/* ========================================
 *
 * Copyright Peerbhai Robotics LLC, 2014
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Peerbhai Robotics LLC.
 *
 * ========================================
*/
#include <project.h>
#include <string.h>
#include "MotorGlobals.h"

motorDividers g_stateMap[101];
volatile motorParameters g_motorStateCurrent;
volatile motorParameters g_motorStateTarget;

CY_ISR(ISR_updateClocks)
{
    // ISR Code here
    TIMER_ThreadTimer_ReadStatusRegister();  //Required to clear the interrupt.
    motorDividers DividersLeft = g_stateMap[g_motorStateCurrent.motorLeftSpeed];
    motorDividers DividersRight = g_stateMap[g_motorStateCurrent.motorRightSpeed];
    int motorLeftUpdated = 0; // Set this to one if we update, so we don't update twice.
    int motorRightUpdated = 0;

    pinLeftDir_Write(g_motorStateCurrent.motorLeftDir);
    pinRightDir_Write(g_motorStateCurrent.motorRightDir);

    // Set the clocks to the whatever I believe the current state to be.
    PWM_LEFT_WriteCompare((DividersLeft.pwmPeriodCounter + 1) / 2);
    PWM_LEFT_WritePeriod(DividersLeft.pwmPeriodCounter + 1);
    CLOCK_LEFT_SetDivider(DividersLeft.clockDivider);
    
    PWM_RIGHT_WriteCompare((DividersRight.pwmPeriodCounter + 1) / 2);
    PWM_RIGHT_WritePeriod(DividersRight.pwmPeriodCounter + 1);
    CLOCK_RIGHT_SetDivider(DividersRight.clockDivider);
    
    //Update the current to be closer to the target.
    if ( g_motorStateTarget.motorLeftDir != g_motorStateCurrent.motorLeftDir )
    {
        // We need to either slow down the current or reverse it.
        motorLeftUpdated = 1;
        if (g_motorStateCurrent.motorLeftSpeed <= 1 )
        {
            // reverse it
            g_motorStateCurrent.motorLeftDir = g_motorStateTarget.motorLeftDir;
        }
        else
        {
            // Slow it down
            g_motorStateCurrent.motorLeftSpeed--;
        }
    }

    if ( g_motorStateTarget.motorRightDir != g_motorStateCurrent.motorRightDir )
    {
        motorRightUpdated = 1;
        // We need to either slow down the current or reverse it.
        if (g_motorStateCurrent.motorRightSpeed <= 1 )
        {
            // reverse it
            g_motorStateCurrent.motorRightDir = g_motorStateTarget.motorRightDir;
        }
        else
        {
            // Slow it down
            g_motorStateCurrent.motorRightSpeed--;
        }
    }
    
    // Update speeds.
    if ( ( g_motorStateCurrent.motorLeftSpeed != g_motorStateTarget.motorLeftSpeed ) && 
        !(motorLeftUpdated) )
    {
        if ( g_motorStateCurrent.motorLeftSpeed > g_motorStateTarget.motorLeftSpeed )
            g_motorStateCurrent.motorLeftSpeed--;
        else
            g_motorStateCurrent.motorLeftSpeed++;
    }

    if ( (g_motorStateCurrent.motorRightSpeed != g_motorStateTarget.motorRightSpeed) &&
       !(motorRightUpdated)  )
    {
        if ( g_motorStateCurrent.motorRightSpeed > g_motorStateTarget.motorRightSpeed )
            g_motorStateCurrent.motorRightSpeed--;
        else
            g_motorStateCurrent.motorRightSpeed++;
    }
        
}

//---------------------------------------------------------------------------------------
// Function:
//  FindDividersForFrequency finds the two dividers to use for a specified motor step frequency.
//  This is determined by an equation:
//      Frequency * microStepSize = MAX_CLOCK / ( clockDivider * (pwmPeriodCounter + 1) )
//  So, clockdivider = MAX_CLOCK * (pwmPeriodCounter + 1)/Frequency * microStepSize
//  We're given the frequency, microStepSize, and MAX_CLOCK.  We need to find the 2 dividers.
//  We want to maximize the clock divider and minimize the period counter.
// Parameters:
//  stepFrequency -- the frequency I want, given.
//  microStepSize -- the number of microsteps to 1 full step.
// Returns:
//  a structure with the correct dividers figured out.
motorDividers FindDividersForFrequency( uint32 stepFrequency, uint8 microStepSize )
{   
    // Declare and init the return structure.
    motorDividers myDivider;
    myDivider.clockDivider = 1;
    myDivider.pwmPeriodCounter = 0;
    
    // We try a few different numbers as the pwmPeriodCounter, and try and get a clockdivider around 500
    // we will never be accurate using ints, but we can come close.

    do
    {
        myDivider.pwmPeriodCounter++;
        myDivider.clockDivider  = MAX_CLOCK_SPEED / ((myDivider.pwmPeriodCounter + 1) * stepFrequency * microStepSize);
    } while ( ( myDivider.clockDivider < 400 ) && (myDivider.pwmPeriodCounter <= 17) );
    myDivider.frequecy = stepFrequency;
    return (myDivider);
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
/* No longer used
//---------------------------------------------------------------------------------------
//Pointer based clock divider functions...
void PointerAccelerateMotor( uint16 (*Getdivider)(void), void (*SetDivider)(uint16, uint8), uint8 desiredSpeedPercent )
{
    uint16 existingDivider = Getdivider();
    uint16 targetDivider = 0;
    short nCount = 0;
    existingDivider++; // Per cypress API doc, the function returns the divider-1.

    // Figure out the correct divider value to set to.
    targetDivider = (MAX_CLOCK_DIVIDER + MIN_CLOCK_DIVIDER) - (MIN_CLOCK_DIVIDER * desiredSpeedPercent);
    if ( targetDivider > MAX_CLOCK_DIVIDER )
    {
        // Too slow -- set it to 1%
        targetDivider = MAX_CLOCK_DIVIDER;
    }
    if (existingDivider == targetDivider)
        return; // do nothing.

    // acclerate between the existing and target speed by changing a counter between the divider values.
    nCount = existingDivider;
    while( nCount != targetDivider )
    {
        if ( targetDivider > nCount )
            nCount++;
        else
            nCount--;
        uint32 delayTime;
        if (nCount > 25 )
        {
            delayTime = 5;
        }
        else
        {
            delayTime = 25;
        }
        CyDelay( delayTime );
        SetDivider(nCount-1, 1);
    }
}

//---------------------------------------------------------------------------------------
// Function:
//  Accelerates a motor to some speed.
// Parameters:
//  motorNumebr:  
//              1 -- left
//              2 -- right motors
//              3 -- both motors
//  motorSpeed -- a percent, between 1-100, indicating final speed.
// Returns:
//  0 -- OK
//  -1 -- E_SPEED_BOUNDS -- motor speed is out of bounds.
//  -10 -- E_MOTORCOUNT_BOUNDS -- motor number is out of bounds.
int AccelerateMotor( int motorNumber, int motorTargetSpeed )
{
    int internalMotorSpeed = 1;
    uint16 (*fptrLeftGet)(void);
    uint16 (*fptrRightGet)(void);
    void (*fptrLeftSet)(uint16, uint8);
    void (*fptrRightSet)(uint16, uint8);
    fptrLeftGet = &CLOCK_LEFT_GetDividerRegister; // create a pointer to the left motor get function
    fptrRightGet = &CLOCK_RIGHT_GetDividerRegister; // create a pointer to the right motor get function
    fptrLeftSet = &CLOCK_LEFT_SetFractionalDividerRegister;
    fptrRightSet = &CLOCK_RIGHT_SetFractionalDividerRegister;
    
    // Bounds check the parameters
    if ( (1 > motorTargetSpeed) || (100 < motorTargetSpeed) )
    {
        return (-1);
    }
    if ( (0 > motorNumber) || (2 < motorNumber) )
    {
        return (-2);
    }
    
    // Handle shutdown first
    if (0 < motorTargetSpeed)
    {
        internalMotorSpeed = motorTargetSpeed;
        switch (motorNumber)
        {
            case 1 :
                PointerAccelerateMotor( fptrLeftGet, fptrLeftSet, internalMotorSpeed);
                break;
            case 2 :
                PointerAccelerateMotor( fptrRightGet, fptrRightSet, internalMotorSpeed);
                break;
            case 3 :
                PointerAccelerateMotor( fptrLeftGet, fptrLeftSet, internalMotorSpeed);
                PointerAccelerateMotor( fptrRightGet, fptrRightSet, internalMotorSpeed);
                break;
            default :
                controlRegStep_Write(0); // Shutdown motors
                CLOCK_LEFT_SetDividerValue (MAX_CLOCK_DIVIDER); // Set to lowest speed
                CLOCK_RIGHT_SetDividerValue (MAX_CLOCK_DIVIDER); // Set to lowest speed
                break;
        }
    }
    else
    {
        switch (motorNumber)
        {
            int controlValue = 0;
            controlValue = controlRegStep_Read();
            case 1 :
                if ( controlValue >= 1 )
                {
                    controlValue--;
                }
                else
                {
                    controlValue = 0;
                }
                controlRegStep_Write(controlValue); // Shutdown left motor
                CLOCK_LEFT_SetDividerValue (MAX_CLOCK_DIVIDER); // Set to lowest speed
                break;
            case 2 :
                if ( controlValue >= 2 )
                {
                    controlValue--;
                }
                else
                {
                    controlValue = 0;
                }
                controlRegStep_Write(controlValue); // Shutdown left motor
                CLOCK_RIGHT_SetDividerValue (MAX_CLOCK_DIVIDER); // Set to lowest speed
                break;
            default :
                controlRegStep_Write(0); // Shutdown motors
                CLOCK_LEFT_SetDividerValue (MAX_CLOCK_DIVIDER); // Set to lowest speed
                CLOCK_RIGHT_SetDividerValue (MAX_CLOCK_DIVIDER); // Set to lowest speed
                break;
        }
    }
    
    // Get the pointers to the getdivider function and setdivider for the motor.
    // If both, we should consider interleaving the change in speed, not do one then the other
    return(0);
}

//---------------------------------------------------------------------------------------
void ProcessChange( motorParameters myMotors )
{
    int controlValue = controlRegStep_Read();

    // Process the left motor
    if ( myMotors.motorLeftSpeed <= 0 )
    {
        // Shut down the motor.
        controlValue = controlValue & RIGHT_MOTOR_BITMASK;
        controlRegStep_Write (controlValue);
    }
    else
    {
        controlValue|=LEFT_MOTOR_BITMASK;

        //power up the motor
        AccelerateMotor( 1, myMotors.motorLeftSpeed );
        pinLeftDir_Write( myMotors.motorLeftDir );
        controlRegStep_Write (controlValue);
    }
        
    // now process the right motor
    if ( myMotors.motorRightSpeed <= 0 )
    {
        // Shut down the motor.
        controlValue = controlValue & LEFT_MOTOR_BITMASK;
        controlRegStep_Write (controlValue);
    }
    else
    {
        controlValue|=RIGHT_MOTOR_BITMASK;

        //power up the motor
        AccelerateMotor( 2, myMotors.motorRightSpeed );
        pinRightDir_Write( myMotors.motorRightDir );
        controlRegStep_Write (controlValue);
    }
}
*/

//---------------------------------------------------------------------------------------
// Function:
//  reads the UART and fills a motor info struct based on it.
//  execting messages over the UART like this:
//  +001r010
//  which means: left motor, + dir, 1% speed, right motor, - dir, 10% speed
//  any other string will become a stop.
// Notes:
//  The UART has an 8 byte FIFO buffer.  i can define any size buffer I like, but then may need an ISR.
//  So, if I want more than 8 Bytes, I have to look at buffer managment.
// Parameters:
//  motorsInfo -- an out paramter that holds a struct that stores what we do.
// Returns:
//  1 -- S_NO_DATA
//  0 -- S_OK
//  -1 -- E_OVERFLOW
//  -10 -- E_MOTOR_SPEED_INVALID
//  -20 -- E_TIMEOUT
int ReadUartAndFillMotorStruct (motorParameters *motorsInfo)
{
    char uartReceivedbuffer[9]  = "";
    char returnToHost[] = "ready\0";
    uint32 uartRecvChar = '\0'; // don't use char, as it will silently fail.
    uint32 nCount = 0;
    uint32 nOuterCount = 0;
 
    // I'm expecting a string sarting with '+' and 8 totals chars in length.  So, loop until I get my +.
    do
    {
        // Tell host we're ready for data.
        usbUART115200bps_UartPutString(returnToHost);
        usbUART115200bps_UartPutCRLF(0);

        CyDelay(20); // wait 20ms for something to enter the buffer
        uartRecvChar = usbUART115200bps_UartGetChar();
        if ( uartRecvChar == '\0' )
        {
            // We have a null, clear the rx buffer.
            usbUART115200bps_SpiUartClearRxBuffer();
        }
        else
        {
            nCount = 0; // reset how long I have.
            // Echo back the character.
            usbUART115200bps_UartPutChar((char)uartRecvChar);
        }
        
        if ( 500 <= nCount )
        {
            usbUART115200bps_UartPutString("Timeout");
            usbUART115200bps_UartPutCRLF(0);
            return (-20);

        }
        
        nCount++;
        
    } while( (uartRecvChar != '+') && (uartRecvChar != '-') );
    uartReceivedbuffer[0] = (char)uartRecvChar;
    nCount = 1;
    
    // Get the remaining characters.
    
    while (nCount <= 7)
    {
        uartRecvChar = usbUART115200bps_UartGetChar();
        if (uartRecvChar == '\0')
            continue; // Do not do the rest of the loop
        usbUART115200bps_UartPutChar((char)uartRecvChar); // echo back the char
        uartReceivedbuffer[nCount] = uartRecvChar;
        if ( (uartRecvChar == '\n')|| (uartRecvChar == '\r') )
        {
            break;
        }
        nCount++;
    }
    uartReceivedbuffer[nCount] = '\0';
    // I now have a null terminated string of form "l+001r-001" ( left motor forward, 1% speed, right backwards 1% speed )
    // Copy, then parse the strings so I can run atoi to get integers...
    for ( nOuterCount = 0; nOuterCount < 2; nOuterCount++ )
    {
        // first time, 1-3, second time, 5-7
        uint32 nOffset = nOuterCount * 4;
        char stringSpeed[4] = "";
        for ( nCount = (1 + nOffset); nCount <= (3 + nOffset); nCount++ )
        {
            stringSpeed[nCount - nOffset - 1] = uartReceivedbuffer[nCount];
        }
        stringSpeed[3] = '\0';
        if ( 0 == nOuterCount )
        {
            motorsInfo->motorLeftSpeed = atoi(stringSpeed);
            if ( ( motorsInfo->motorLeftSpeed < 0 ) || ( motorsInfo->motorLeftSpeed > 100 ) )
                return (-10);
        }
        else
        {
            motorsInfo->motorRightSpeed = atoi(stringSpeed);
            if ( ( motorsInfo->motorRightSpeed < 0 ) || ( motorsInfo->motorRightSpeed > 100 ) )
                return (-10);
        }
    }

    // Parse the rest of the string received into the structure.

    if ( uartReceivedbuffer[0] == '+' )
    {
        motorsInfo->motorLeftDir = 0;
    }
    else
    {
        motorsInfo->motorLeftDir = 1;
    }
    if ( uartReceivedbuffer[4] == '+' )
    {
        motorsInfo->motorRightDir = 0;
    }
    else
    {
        motorsInfo->motorRightDir = 1;
    }
    usbUART115200bps_UartPutString("OK");
    usbUART115200bps_UartPutCRLF(0);
    CyDelay(2); // wait 2ms to transmit the buffer before clearing it.
    
    // Clear the buffers
    usbUART115200bps_SpiUartClearTxBuffer(); 
    usbUART115200bps_SpiUartClearRxBuffer();
    return (0);
}

//---------------------------------------------------------------------------------------
void initMotorParamsStruct(motorParameters *motorsInfo)
{
    motorsInfo->motorLeftDir = 0;
    motorsInfo->motorLeftSpeed = 0;
    motorsInfo->motorRightDir = 0;
    motorsInfo->motorRightSpeed = 0;
}

//---------------------------------------------------------------------------------------
void initSpeedMap()
{
    int nCount = 0;
    g_stateMap[nCount] = FindDividersForFrequency( MIN_FULL_STEP_FREQUENCY, MICRO_STEP_FACTOR);
    for ( nCount = 1; nCount<=100; nCount++ )
    {
        g_stateMap[nCount] = FindDividersForFrequency( MIN_FULL_STEP_FREQUENCY * nCount, MICRO_STEP_FACTOR);
        
    }
}

//---------------------------------------------------------------------------------------
void minimizeSpeed()
{
    g_motorStateTarget.motorLeftSpeed=1;
    g_motorStateTarget.motorRightSpeed=1;
    g_motorStateTarget.motorLeftDir=0;
    g_motorStateTarget.motorRightDir=0;
    
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    motorParameters motorTargetParams;
    initMotorParamsStruct(&motorTargetParams);
    initSpeedMap();
    minimizeSpeed();
    g_motorStateCurrent = g_motorStateTarget; // set the two states equal.
    
    // Start up all the udb systems, but don't enable the motors.
    controlRegStep_Write (3); // writes 0x00 to turn off the motors this cycle.
 
    usbUART115200bps_Start();
    CLOCK_LEFT_Start();
    CLOCK_RIGHT_Start();
    PWM_LEFT_Start();
    PWM_RIGHT_Start();
    CLOCK_ThreadClock_Start();
    TIMER_ThreadTimer_Start();
    ISR_UpdateSpeed_StartEx(ISR_updateClocks);
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */

    for(;;)
    {
        /* Place your application code here. */
        if ( 0 != ReadUartAndFillMotorStruct (&motorTargetParams) )
        {
            // Set the Target to 1% power and shutdown the PWM system.
            minimizeSpeed();
            controlRegStep_Write (0); // writes 0x00 to turn off the motors this cycle.
        }
        else
        {
            g_motorStateTarget = motorTargetParams;
            controlRegStep_Write (LEFT_MOTOR_BITMASK + RIGHT_MOTOR_BITMASK); // enable both motors.
        }
    }
}

/* [] END OF FILE */
