#ifndef LOGGER
#define LOGGER
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Logger{
    private:
        bool debug;
    public:
        Logger();
        Logger(bool debug);
        void log(string s);        
};
#endif