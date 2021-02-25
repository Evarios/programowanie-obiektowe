#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "osoba.h"
#include "student.h"
#include "pracownik.h"
#include "fabrykaStudentow.h"
#include "fabrykaOsob.h"
#include "fabrykaPracownikow.h"

using namespace std;

void foo(Osoba & os){
os.przedstaw();
}
void bar(Osoba * os){
os -> przedstaw();
}



int main(){
    Osoba osoba1;
    Student student1;
    Pracownik pracownik1;

    osoba1.setName("Jan Kowalski");
    osoba1.readName();
    osoba1.setBirthDate(11, 10, 1986);
    osoba1.readBirthDate();
    osoba1.setAddress("Piotrowo", "5","61-000", "Poznan");
    osoba1.readAddress();
    osoba1.przedstaw();
    student1.setName("Jan Brozdziak");
    student1.setBirthDate(25, 6, 1999);
    student1.setAddress("Przemyslawa", "17B","61-064", "Poznan");
    student1.addGrade("Podstawy Automatyki", 5);
    student1.addGrade("PTC", 4);
    student1.readAllGrades();
    student1.przedstaw();
    pracownik1.setName("Janusz Nowak");
    pracownik1.setBirthDate(14, 3, 1957);
    pracownik1.addPrzedmiot("test");
    pracownik1.addPrzedmiot("Informatyka");
    pracownik1.removePrzedmiot("test");
    pracownik1.setAddress("Szkolna", "17","60-000", "Poznan");
    pracownik1.przedstaw();
    cout <<endl<<endl<<endl << "KONIEC WPISYWANIA" <<endl<<endl<<endl;
    foo(osoba1);
    bar(&osoba1);
    foo(student1);
    bar(&student1);
    foo(pracownik1);
    bar(&pracownik1);
    //wnioski: obie funkcje traktują przyjmowaną wartość jako osobę, więc nie wyświetlają pól typowych dla studenta/pracownika
    // po dodaniu virtual wszystko działa super-  korzystamy z polimorfizmu, tylko trzeba było przenieść kod klasy do pliku .h
    Pracownik *p1 = new Pracownik;
    Osoba *o1 = static_cast<Osoba *>(p1);
    Osoba *o2 = static_cast<Pracownik *>(o1); 

    Osoba *o3 = new Osoba;
    Pracownik *p2 = static_cast<Pracownik *>(o3);

    
    Pracownik *p3 = new Pracownik;
    Osoba *o4 = dynamic_cast<Osoba *>(p3);
    //Pracownik *p4 = dynamic_cast<Osoba *>(o4); // niepoprawne, nie można rzutować podklasy na nadklasę

    Osoba *o5 = new Osoba;
    Pracownik *p5 = dynamic_cast<Pracownik *>(o5);
    if(p5 == nullptr) cout << "Blad rzutowania!" << endl;
    else p5 -> readPrzedmiots();

    FabrykaStudentow fabrykaStudentow;
    //FabrykaOsob fabrykaOsob; "obiekt klasy abstrakcyjnej jest niedozwolony";
    FabrykaPracownikow fabrykaPracownikow;

    fabrykaStudentow.utworz();
    fabrykaPracownikow.utworz();
    map<string, FabrykaOsob*> m;
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();
    vector<Osoba*> tablicaOsob;
    
    string currentCommand;

    while(true){
        cin >> currentCommand;
        if(currentCommand == "wyjscie"){
            break;
        }
        tablicaOsob.push_back(m[currentCommand]->utworz());
    }

    return 0;
}