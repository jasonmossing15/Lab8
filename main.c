#include <msp430.h> 
#include "RobotSensors.h"
#include "MotorMovement.h"

int leftSensorValue;
int centerSensorValue;
int rightSensorValue;
int twoInLeft = 0x260;
int twoInRight = 0x260;
int fourInCenter = 0x358;

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    initializePWM();
    initializeADC10();

    for(;;){
    leftSensorValue = getLeftSensorValue();
    centerSensorValue = getCenterSensorValue();
    rightSensorValue = getRightSensorValue();
    if(leftSensorValue > twoInLeft){
    	veerRight();
    }
    else if(centerSensorValue > fourInCenter){
    	smallRightTurn();
    }
    else{
    	veerLeft();
    }
    }
	return 0;
}

#pragma vector = ADC10_VECTOR
__interrupt void ADC10_ISR(void){
	__bic_SR_register_on_exit(CPUOFF);
}
