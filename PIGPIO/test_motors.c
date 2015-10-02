#include <stdio.h>
#include <pigpio.h>

int main(){
if(gpioInitialise() < 0){
	//initialization failed
	gpioTerminate();
	return 0;
}
else{
	printf("Hello this is a test!\n");
	printf("GPIO has been initialized\n");
	//set GPIO pins for output signal
	printf("Setting GPIO Modes\n");
	gpioSetMode(4, PI_OUTPUT);
	gpioSetMode(17, PI_OUTPUT);
	gpioSetMode(27, PI_OUTPUT);
	gpioSetMode(19, PI_OUTPUT);
	printf("GPIO MODES SET\n");
	//Initialize PWM signal at 0
	printf("Initializing Motors\n");
	gpioServo(4,1000);
	gpioServo(17,1000);
	gpioServo(19,1000);
	gpioServo(27,1000);
	//warn user motor start
	printf("Starting Motors in\n");
	printf("3\n");
	sleep(1);
	printf("2\n");
	sleep(1);
	printf("1\n");
	sleep(1);
	//spin up to 1300 PWM
	gpioServo(4,1700);
	gpioServo(17,1700);
	gpioServo(19,1700);
	gpioServo(27,1700);
	//do this for 10 secs
	sleep(10);
	//sping motors down
	gpioServo(4,1000);
	gpioServo(17,1000);
	gpioServo(19,1000);
	gpioServo(27,1000);
}
sleep(3);

gpioTerminate();
return 0;
}
