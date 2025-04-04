/*
 * This is the main application file for the GPIO class implementation.
 * It serves to test the functions using an LED connected to GPIO60 and a button connected to GPIO46.
 *
 * Invoke with ./myGpioApp
 *
 * */

#include "myGpio.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){

	MYGPIO button(46);
	MYGPIO led(60);

	button.setDirection(0);
	led.setDirection(1);


	while(1){
		led.setValue(1);
		usleep(300000);
		value = led.getValue();
		std::cout << value << std::endl;
		button_value = button.getValue();
		std::cout << button_value << std::endl;
	}
	

	return 0;

}
