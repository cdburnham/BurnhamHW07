#include "myGpio.h"
#include <sstream>
#include <unistd.h> // For usleep

#define GPIO_PATH "/sys/class/gpio"

MYGPIO::MYGPIO(int number) {
    this->number = number;
    ostringstream s;
    s << "gpio" << number;
    name = s.str();
    path = string(GPIO_PATH) + "/" + name;

    fstream exportFile;
    exportFile.open(GPIO_PATH "/export", fstream::out);
    exportFile << number;
    exportFile.close();
}

int MYGPIO::getNumber(){
    return number;
}

void MYGPIO::setDirection(int dir){
    string direction = (dir == 1) ? "out" : "in";
    write(path, "direction", direction);
}

string MYGPIO::getDirection(){
    return read(path, "direction");
}

void MYGPIO::setValue(int val){
    write(path, "value", val);
}

int MYGPIO::getValue(){
    string valueString = read(path, "value");
    return (valueString == "1") ? 1 : 0;
}

void MYGPIO::toggleOutput(){
    int current = getValue();
    setValue(current == 1 ? 0 : 1);
}

void MYGPIO::toggleOutputNumberOfTimes(int n, int delay){
    for(int i = 0; i < n; ++i){
        toggleOutput();
        usleep(delay * 1000); // Added delay in milliseconds
    }
}

void MYGPIO::write(string path, string filename, string value){
    fstream fs;
    fs.open((path + "/" + filename).c_str(), fstream::out);
    if(fs.is_open()){
        fs << value;
        fs.close();
    }
}

void MYGPIO::write(string path, string filename, int value){
    fstream fs;
    fs.open((path + "/" + filename).c_str(), fstream::out);
    if(fs.is_open()){
        fs << value;
        fs.close();
    }
}

string MYGPIO::read(string path, string filename){
    fstream fs;
    fs.open((path + "/" + filename).c_str(), fstream::in);
    string value;
    if(fs.is_open()){
        fs >> value;
        fs.close();
    }
    return value;
}

MYGPIO::~MYGPIO(){
    fstream unexportFile;
    unexportFile.open((path + "/unexport").c_str(), fstream::out);
    unexportFile << number;
    unexportFile.close();
}
