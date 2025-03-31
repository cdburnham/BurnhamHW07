/*
 * By: Cameron Burnham
 * File Name: GPIO60_low.cpp
 * Purpose: This script sets the GPIO60 pin to low.
 * Invokation: ./GPIO60_low
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

	// set the pin value to 0 for low...

	filestream.open((path+"/"+"value").c_str(), std::fstream::out);
	filestream << "0" << endl;
	filestream.close();
	
	return 0;

}
