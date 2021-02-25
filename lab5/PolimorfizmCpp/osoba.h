#ifndef OSOBA
#define OSOBA
#include <iostream>
#include <string>
using namespace std;

class Adres{
    protected:
        string *ulica{nullptr};
        string *nr_domu{nullptr};
        string *kod{nullptr};
        string *miasto{nullptr};      
    public:
        Adres();
        Adres(string, string, string, string);
        ~Adres();
        void readAddress();
};

class Osoba{
    private:
        string *imieINazwisko{nullptr};
        int *dzienUrodzenia{nullptr};
        int *miesiacUrodzenia{nullptr};
        int *rokUrodzenia{nullptr};
        Adres *adres{nullptr};
    public:
        Osoba();
        Osoba(Osoba &);
        Osoba(Osoba &&);
        virtual ~Osoba(){
        if(imieINazwisko != nullptr) delete imieINazwisko;
        if(dzienUrodzenia != nullptr) delete dzienUrodzenia;
        if(miesiacUrodzenia != nullptr) delete miesiacUrodzenia;
        if(rokUrodzenia != nullptr) delete rokUrodzenia;
        if(adres != nullptr) delete adres;  
        }       
        void setName(string);
        void readName();
        void setBirthDate(int, int, int);
        void readBirthDate();
        void setAddress(string, string, string, string);
        void readAddress();
        virtual void przedstaw(){
            cout<< "Imie i nazwisko: ";
            readName();
            cout<< "Data urodzenia: ";
            readBirthDate();
            cout<< "Miejsce zamieszkania: ";
            readAddress();
        }
};


#endif