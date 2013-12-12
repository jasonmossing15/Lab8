#include <msp430.h> 
#include "RobotSensors.h"
#include "MotorMovement.h"

int twoInLeft = 0x273;
int fourInCenter = 0x380;

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    initializePWM();
    initializeADC10();

    for(;;){

    if(getLeftSensorValue() < twoInLeft){
    	veerLeft();
    	__delay_cycles(10000);
    }
    else{
    	veerRight();
    	__delay_cycles(10000);
    }
    if(getCenterSensorValue() > fourInCenter){
    	moveMotorsBackward();
    	__delay_cycles(20000);
    	turnRight();
    	__delay_cycles(300000);
    }
    }
	return 0;
}

#pragma vector = ADC10_VECTOR
__interrupt void ADC10_ISR(void){
	__bic_SR_register_on_exit(CPUOFF);
}
