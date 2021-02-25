#include <iostream>
#include <string>
#include "osoba.h"
using namespace std;

Adres::Adres(){}
Adres::Adres(string ulica_s, string nr_domu_s, string kod_s, string miasto_s){
    ulica = new string;
    *ulica = ulica_s;
    nr_domu = new string;
    *nr_domu = nr_domu_s;
    kod = new string;
    *kod = kod_s;
    miasto = new string;
    *miasto = miasto_s;
}
Adres::~Adres(){
    if(ulica != nullptr) delete ulica;
    if(nr_domu != nullptr) delete nr_domu;
    if(kod != nullptr) delete kod;
    if(miasto != nullptr) delete miasto;
}

Osoba::Osoba(){}
Osoba::Osoba(Osoba &osoba)
:
imieINazwisko(nullptr),
dzienUrodzenia(nullptr),
miesiacUrodzenia(nullptr),
rokUrodzenia(nullptr),
adres(nullptr)
{
    if(osoba.imieINazwisko != nullptr){
        imieINazwisko = new string;
        *imieINazwisko = *osoba.imieINazwisko;
    }
    if(osoba.dzienUrodzenia != nullptr){
        dzienUrodzenia = new int;
        *dzienUrodzenia = *osoba.dzienUrodzenia;
    }
    if(osoba.miesiacUrodzenia != nullptr){
        miesiacUrodzenia = new int;
        *miesiacUrodzenia = *osoba.miesiacUrodzenia;
    }
    if(osoba.rokUrodzenia != nullptr){
        rokUrodzenia = new int;
        *rokUrodzenia = *osoba.rokUrodzenia;
    }    
    if(osoba.adres != nullptr){
        adres = new Adres;
        *adres = *osoba.adres;
    }
}
Osoba::Osoba(Osoba &&osoba)
{
    imieINazwisko = move(osoba.imieINazwisko);
    dzienUrodzenia = move(osoba.dzienUrodzenia);
    miesiacUrodzenia = move(osoba.miesiacUrodzenia);
    rokUrodzenia = move(osoba.rokUrodzenia);
    adres = move(osoba.adres);
}

/*Osoba::~Osoba(){
    if(imieINazwisko != nullptr) delete imieINazwisko;
    if(dzienUrodzenia != nullptr) delete dzienUrodzenia;
    if(miesiacUrodzenia != nullptr) delete miesiacUrodzenia;
    if(rokUrodzenia != nullptr) delete rokUrodzenia;
    if(adres != nullptr) delete adres;
}*/

void Osoba::setName(string name){
    imieINazwisko = new string;
    *imieINazwisko = name;
}
void Osoba::readName(){
    if(imieINazwisko != nullptr){
        cout << *imieINazwisko <<endl;
    }
}

void Osoba::setBirthDate(int d, int m, int y){
    if(d >= 1 && d <= 31){
        dzienUrodzenia = new int;
        *dzienUrodzenia = d;
    } else {
        cout << "nieprawidlowy zakres dnia urodzenia " <<endl;
    }

    if(m >= 1 && d <= 12){
        miesiacUrodzenia = new int;
        *miesiacUrodzenia = m;
    } else {
        cout << "nieprawidlowy zakres miesiaca urodzenia " <<endl;
    }

    if(y >= 1 && d <= 9999){
        rokUrodzenia = new int;
        *rokUrodzenia = y;
    } else {
        cout << "nieprawidlowy zakres roku urodzenia " <<endl;
    }
}

void Osoba::readBirthDate(){
    if(dzienUrodzenia != nullptr && miesiacUrodzenia != nullptr && rokUrodzenia != nullptr){
        cout << *dzienUrodzenia <<"-"<< *miesiacUrodzenia << "-" << *rokUrodzenia<<endl;
    }
}

void Osoba::setAddress(string ulica_s, string nr_domu_s, string kod_s, string miasto_s){
    adres = new Adres(ulica_s,nr_domu_s,kod_s,miasto_s);
}

void Adres::readAddress(){
    cout << *ulica << " " << *nr_domu<<endl;
    cout <<*kod << " " << *miasto <<endl;
}

void Osoba::readAddress(){
    if(adres!=nullptr){
        adres->readAddress();
    }
}

/*void Osoba::przedstaw(){
    cout<< "Imie i nazwisko: ";
    readName();
    cout<< "Data urodzenia: ";
    readBirthDate();
    cout<< "Miejsce zamieszkania: ";
    readAddress();
}*/
