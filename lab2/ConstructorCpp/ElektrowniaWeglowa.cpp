#include "ElektrowniaWeglowa.h"
#include "logger.h"
#include <iostream> 
using namespace std;

ElektrowniaWeglowa::ElektrowniaWeglowa()
:
Logger(true),
maxCoalAmmount(nullptr),
coalAmmountInStore(nullptr),
efficiency(nullptr),
workersNumber(nullptr),
power(nullptr){
    log("Test");
    reset();
}

ElektrowniaWeglowa::ElektrowniaWeglowa(ElektrowniaWeglowa & elektorwnia)
:
maxCoalAmmount(nullptr),
coalAmmountInStore(nullptr),
efficiency(nullptr),
workersNumber(nullptr),
power(nullptr),
Logger(true)
{
    reset();
    if(elektorwnia.maxCoalAmmount != nullptr){
        maxCoalAmmount = new int;
        *maxCoalAmmount = *(elektorwnia.maxCoalAmmount);
    }
    if(elektorwnia.coalAmmountInStore != nullptr){
        coalAmmountInStore = new int;
        *coalAmmountInStore = *(elektorwnia.coalAmmountInStore);
    }
    if(elektorwnia.efficiency != nullptr){
        efficiency = new float;
        *efficiency = *(elektorwnia.efficiency);
    }
    if(elektorwnia.workersNumber != nullptr){
        workersNumber = new int;
        *workersNumber = *(elektorwnia.workersNumber);
    }
    if(elektorwnia.power != nullptr){
        power = new int;
        *power = *(elektorwnia.power);
    }
}

ElektrowniaWeglowa::ElektrowniaWeglowa(ElektrowniaWeglowa && elektrownia)
:
Logger(true)
{
    reset();
    maxCoalAmmount = move(elektrownia.maxCoalAmmount);
    coalAmmountInStore = move(elektrownia.coalAmmountInStore);
    efficiency = move(elektrownia.efficiency);
    workersNumber = move(elektrownia.workersNumber);
    power = move(elektrownia.power);
}

ElektrowniaWeglowa::ElektrowniaWeglowa(int maxCoal)
:
Logger(true),
maxCoalAmmount(nullptr),
coalAmmountInStore(nullptr),
efficiency(nullptr),
workersNumber(nullptr),
power(nullptr)
{
    reset();
    maxCoalAmmount = new int;
    *maxCoalAmmount = maxCoal;
}

ElektrowniaWeglowa::~ElektrowniaWeglowa(){
    if(maxCoalAmmount != nullptr)
        delete maxCoalAmmount;
    if(coalAmmountInStore != nullptr)
        delete coalAmmountInStore;
    if(efficiency != nullptr)
        delete efficiency;
    if(maxCoalAmmount != nullptr)
        delete workersNumber;
    if(power != nullptr)
        delete power;
}

void ElektrowniaWeglowa::setMaxCoalAmmount(int ammount){
    start();
    if (maxCoalAmmount == nullptr) {
        maxCoalAmmount = new int;
        *maxCoalAmmount = ammount;
    }
    else{
        cout<<"Zmienna zostala juz ustawiona" << endl;
    }
    stop();
    return;
}

int ElektrowniaWeglowa::readMaxCoalAmmount() {
    start();
    if(maxCoalAmmount != nullptr){
        return *maxCoalAmmount;
    }
    stop();
    return 0;
}

int ElektrowniaWeglowa::addCoalToStore(int ammount){
    start();
    if (coalAmmountInStore == nullptr) {
        coalAmmountInStore = new int;
        *coalAmmountInStore = ammount;
    }
    else{
        *coalAmmountInStore += ammount;
    }
    stop();
    return *coalAmmountInStore;
}

int ElektrowniaWeglowa::burnCoal() {
    start();
    if(*coalAmmountInStore >= *maxCoalAmmount) {
        *coalAmmountInStore -= *maxCoalAmmount;
        return *coalAmmountInStore;
    }
    else{
        cout << "Brak wystarczajacej ilosci wegla w magazynie" << endl;
        return *coalAmmountInStore;
    }
    stop();
    return *coalAmmountInStore;
}

int ElektrowniaWeglowa::readCoalInStore(){
    start();
    if(coalAmmountInStore != nullptr){
        return *coalAmmountInStore;
    }
    else{
        return 0;
    }
    stop();
}

void ElektrowniaWeglowa::setEfficiency(float efficiencyNumber) {
    start();
    efficiency = new float;
    *efficiency = efficiencyNumber;
    return;
    stop();
}

float ElektrowniaWeglowa::readEfficiency() {
    start();
    if(efficiency != nullptr){
        stop();
        return *efficiency;
    }
    else{
        stop();
        return 0;
    }
    
}


void ElektrowniaWeglowa::setWorkersNumber(int number) {
    start();
    workersNumber = new int;
    *workersNumber = number;
    stop();
    return;
}
int ElektrowniaWeglowa::retireWorkers(int number) {
    start();
    if(*workersNumber - number >= 0) {
        *workersNumber -= number;
        stop();
        return *workersNumber;
    }
    else {
        
        cout << "Nie mozna zwolnic tylu pracownikow" << endl;
        stop();
        return *workersNumber;
    }
}

int ElektrowniaWeglowa::readWorkersNumber() {
    start();
    if(workersNumber != nullptr){
        stop();
        return *workersNumber;
    }
    else{
        stop();
        return 0;
    }
}


void ElektrowniaWeglowa::setPower(int number) {
    start();
    power = new int;
    *power = number;
    stop();
}

int ElektrowniaWeglowa::readPower() {
    if(power != nullptr){
        stop();
        return *power;
    }
    else{
        stop();
        return 0;
    }
}