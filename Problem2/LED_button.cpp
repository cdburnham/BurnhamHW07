#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define BUTTON_PATH "sys/class/gpio/gpio46"
#define LED_PATH "sys/class/gpio/gpio60"

int readButton(){

	fstream fs;
	string path(BUTTON_PATH);
	string pathName = path + "/value";
	fs.open((pathName).c_str(), std::fstream::in);
	char value;
       	fs >> value;
	fs.close();
	return (value == '1') ? 1 : 0;

}

void setLED(int value){

	fstream fs;
	string path(LED_PATH);
	fs.open((path+"/value").c_str(), std::fstream::out);
	cout << value << endl;
	fs.close();

}

int main(int argc, char* argv[]){

	while(1){
		
		int status = readButton();
		if(status==1){
			setLED(1);
		} else {
			setLED(0);
		}
	
	}

	return 0;

}
