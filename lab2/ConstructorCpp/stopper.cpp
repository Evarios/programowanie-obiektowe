#include "stopper.h"
#include <ctime>
#include <iostream>
using namespace std;

void Stopper::start(){
    start_t = time(0);
}
void Stopper::stop(){
    stop_t = time(0);
    //cout<< difftime(stop_t, start_t)<<endl; // wykonuje sie tak szybko, że wypisuje 0.
    sumTime += difftime(stop_t, start_t);
}

void Stopper::currTime(){
    cout<< sumTime <<endl;
}

void Stopper::reset(){
    start_t = 0;
    stop_t = 0;
    sumTime=0;
}