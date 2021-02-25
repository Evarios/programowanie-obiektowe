#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "logger.h"
using namespace std;

Logger::Logger(){
    this->debug = true;
}


Logger::Logger(bool debug){
    this->debug = debug;
}

void Logger::log(string s){
    auto time = chrono::system_clock::now();
    time_t time1 = chrono::system_clock::to_time_t(time);
    if(this->debug){
    cout << ctime(&time1) <<" "<< s <<std::endl;
    } 
}

