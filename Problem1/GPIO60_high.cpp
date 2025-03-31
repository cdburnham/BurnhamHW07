/*
 * By: Cameron Burnham
 * Name: GPIO60_high.cpp
 * Purpose: sets the GPIO60 pin (specifically P9.12) to high
 * Usage: ./GPIO60_high
 *
 * */


#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define PIN_CONFIG_PATH "/sys/class/gpio/gpio60"

int main(int argc, char* argv[]){

	if(argc!=1){
		cout << "No arguments required for this script.\nInvoke using simple executable." << endl;
	}

	// set the pin direction to output...

	fstream filestream;
	string path(PIN_CONFIG_PATH);
	filestream.open((path+"/direction").c_str(), std::fstream::out);
	filestream << "out" << endl;
	filestream.close();

	// set the pin value to 1 for high...

	filestream.open((path+"/"+"value").c_str(), std::fstream::out);
	filestream << "1" << endl;
	filestream.close();
	
	return 0;

}
