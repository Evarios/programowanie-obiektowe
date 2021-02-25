#ifndef PRACOWNIK
#define PRACOWNIK

#include <iostream>
#include <string>
#include <vector>
#include "osoba.h"

using namespace std;

class Pracownik: public Osoba{
private:
    vector<string> * przedmioty{nullptr};
public:
    Pracownik(){};
    Pracownik(Pracownik &);
    Pracownik(Pracownik &&);
    ~Pracownik();
    void addPrzedmiot(string);
    void removePrzedmiot(string);
    void readPrzedmiots();
    bool teaches(string);
    void przedstaw();

};

#endif