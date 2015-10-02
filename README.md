# Motors
Control of brushless motors/ESCs through GPIO on Raspberry Pi using PIGPIO and C interface

To control brushless motors through command line:
  First install Pigpio
  launch 'sudo pigpiod' <---this is a dameon that will recognize commands used to control GPIO
  Use command 'pigs' as referenced here: http://abyz.co.uk/rpi/pigpio/pigs.html
  
Brushless motors are controlled as servos, therefore the pigs command will be used like so:
(The number 4 is the PIN on the GPIO)

  pigs s 4 1000 <-----This initializes the ESC at its powered down state
  
  pigs s 4 1500 <-----This spins up the motor at 1500 PWM.
  
  pigs s 4 1000 <-----This is called again to turn the motors off.
  
To control the brushless motors through a program written in C:
  *Make sure you "killall pigpiod" if you attempted control from command line, this interfered
   when I compiled and ran the C version.
   
   Make sure the program is in the PIGPIO directory as you will need to include the header file.
   #include <piogpio.h>    <---if this is not included, your program will not compile/run
   
    Always perform gpioInitialise(); when starting program and gpioTerminate(); before exiting.
    
    Prepare the pins to be used as output for signal.
    gpioSetMode(thepin, PI_OUTPUT);     //the pin = pin connected to signal on ESC
                                        //PI_OUTPUT = constant variable for indicating the pin will be output
                                         
    gpioServo(thepin, 1000);            //This sends a power off signal to the ESC, this must be done before
                                        //the motors can be spinned up. This is due in part to how servos work
    Spin them up!
    gpioServo(thepin, 1500);            //This sends a PWM signal of 1500 to the ESC, from what I have read
                                        //this is halfway point. Pigpio will not allow anything >2500
    gpioServo(thepin, 1000);            //Spin them down before exiting program
    
    Remember to gpioTerminate();
   
   To compile(assuming your program is named prog),
   "gcc -o prog prog.c -lpigpio -lpthread -lrt"
   "sudo ./prog"
   
  
   
   
