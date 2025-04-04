#include "myGpio.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

	MYGPIO button(46);
	MYGPIO led(60);

	button.setDirection(0);
	string test = led.getDirection();
	
	while(1){
		int buttonVal = button.getValue();
	}
	

	return 0;

}
