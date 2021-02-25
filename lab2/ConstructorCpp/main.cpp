#include "ElektrowniaWeglowa.h"
#include <iostream>
using namespace std;

void foo(ElektrowniaWeglowa elektrownia){
    cout << elektrownia.addCoalToStore(200);
    cout << elektrownia.readCoalInStore()<<endl;
    cout << elektrownia.readWorkersNumber()<<endl;
}
void bar(const ElektrowniaWeglowa &elektrownia){
    cout <<"In BAR" <<endl;
    //brakuje metody w klasie posiadającej parametr const, nie można dodać nic więcej
}
void baz(ElektrowniaWeglowa & elektrownia){
    cout << elektrownia.readCoalInStore()<<endl;
    cout <<
     elektrownia.readWorkersNumber()<<endl;
}

void qux(ElektrowniaWeglowa && elektrownia){
    cout << elektrownia.readCoalInStore()<<endl;
    cout << elektrownia.readWorkersNumber()<<endl;
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
    foo(elektrownia);
    bar(elektrownia);
    baz(elektrownia);
    cout << "czas ";
    elektrownia.currTime(); //polecenia wykonują się tak szybko, że czs
    //qux(elektrownia); odwołanie do r-wartości nie może być powiązane z l-wartością
    foo(move(elektrownia));
    bar(move(elektrownia));
    //baz(move(elektrownia)); "cannot bind non-const lvalue reference of type 'ElektrowniaWeglowa&' to an rvalue of type 'std::remove_reference<ElektrowniaWeglowa&>::type' {aka 'ElektrowniaWeglowa'}"
    qux(move(elektrownia));
    foo(500);
    bar(500);
    //baz(500); "cannot bind non-const lvalue reference of type 'ElektrowniaWeglowa&' to an rvalue of type 'ElektrowniaWeglowa
    //qux(500); segmentation fault przy próbuie odczytania pól klasy
    //elektrownia.log("test"); nie można odpalić funkcji log, ponieważ domyslne dziedziczenie jest prywatne, i można odpalić funkcję log jedynie z wnętrza klasy
    return 0;
    // w javie nie da się zrobić podwójnego dziedziczenia, zastępuje to element interface
}