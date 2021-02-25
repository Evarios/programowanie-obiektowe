#include <iostream>
#include <string>

using namespace std;

class ElektrowniaWeglowa{

private:
    int maxCoalAmmount = -1;
    int coalAmmountInStore = 0;
    float efficiency;
    int workersNumber;
    int power; //własna własność, moc elektrowni w megawatach (MW)

public:
    void setMaxCoalAmmount(int);
    int readMaxCoalAmmount();
    int addCoalToStore(int);
    int burnCoal();
    int readCoalInStore();
    void setEfficiency(float);
    float readEfficiency();
    void setWorkersNumber(int);
    int retireWorkers(int);
    int readWorkersNumber();
    void setPower(int); //metoda do własnej własności
    int readPower(); //metoda do własnej własności
};

void ElektrowniaWeglowa::setMaxCoalAmmount(int ammount){
    if (maxCoalAmmount == -1) {
        maxCoalAmmount = ammount;
    }
    else{
        cout<<"Zmienna zostala juz ustawiona" << endl;
    }
    return;
}

int ElektrowniaWeglowa::readMaxCoalAmmount() {
    return maxCoalAmmount;
}

int ElektrowniaWeglowa::addCoalToStore(int ammount){
    coalAmmountInStore += ammount;
    return coalAmmountInStore;
}

int ElektrowniaWeglowa::burnCoal() {
    if(coalAmmountInStore >= maxCoalAmmount) {
        coalAmmountInStore -= maxCoalAmmount;
        return coalAmmountInStore;
    }
    else{
        cout << "Brak wystarczajacej ilosci wegla w magazynie" << endl;
        return coalAmmountInStore;
    }
    return coalAmmountInStore;
}

int ElektrowniaWeglowa::readCoalInStore(){
    return coalAmmountInStore;
}

void ElektrowniaWeglowa::setEfficiency(float efficiencyNumber) {
    efficiency = efficiencyNumber;
    return;
}

float ElektrowniaWeglowa::readEfficiency() {
    return efficiency;
}

void ElektrowniaWeglowa::setWorkersNumber(int number) {
    workersNumber = number;
    return;
}
int ElektrowniaWeglowa::retireWorkers(int number) {
    if(workersNumber - number >= 0) {
        workersNumber -= number;
        return workersNumber;
    }
    else {
        cout << "Nie mozna zwolnic tylu pracownikow" << endl;
        return workersNumber;
    }
}

int ElektrowniaWeglowa::readWorkersNumber() {
    return workersNumber;
}

void ElektrowniaWeglowa::setPower(int number) {
    power = number;
}

int ElektrowniaWeglowa::readPower() {
    return power;
}


int main() {
    ElektrowniaWeglowa elektrownia;
    elektrownia.setMaxCoalAmmount(20);
    cout << "max ilosc wegla: " << elektrownia.readMaxCoalAmmount()<<endl;
    elektrownia.addCoalToStore(1000);
    elektrownia.burnCoal();
    cout << "obecna ilosc wegla: " << elektrownia.readCoalInStore()<<endl;
    elektrownia.setEfficiency(0.7);
    cout << "obecna sprawnosc: " <<elektrownia.readEfficiency()<<"%"<<endl;
    elektrownia.setWorkersNumber(200);
    elektrownia.retireWorkers(50);
    cout << "obecna ilosc pracownikow: " << elektrownia.readWorkersNumber() <<endl;
    elektrownia.setPower(1500);
    cout << "Obecna moc: " << elektrownia.readPower() <<"MW" << endl;
    

    return 0;
}