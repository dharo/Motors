#include <stdio.h>
#include <pigpio.h>

int main(){
	gpioInitialize();

	if(gpioInitialize() < 0){
		//initialization failed
		gpioTerminate();
		return 0;
	}
	else{
		printf("Hello this is a test!\n");
		printf("GPIO has been initialized\n");
	}

	gpioTerminate();
	return 0;
}
