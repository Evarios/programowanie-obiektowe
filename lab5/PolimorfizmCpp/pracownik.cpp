#include <iostream>
#include <string>
#include <vector>
#include "pracownik.h"

using namespace std;

Pracownik::Pracownik(Pracownik &pracownik)
:
przedmioty(nullptr)
{
    if(przedmioty!=nullptr){
        przedmioty = new vector<string>;
        *przedmioty = *pracownik.przedmioty;
    }
}
Pracownik::Pracownik(Pracownik &&pracownik)
{
    przedmioty = move(pracownik.przedmioty);
}

Pracownik::~Pracownik(){
    if(przedmioty!=nullptr) delete przedmioty;
}

void Pracownik::addPrzedmiot(string przedmiot){
    if(przedmioty == nullptr){
        przedmioty = new vector<string>;
    }
    for(int i = 0; i < przedmioty->size(); i++){
        if(przedmiot == (*przedmioty)[i]){
            cout << "Ta osoba już prowadzi taki przedmiot" <<endl;
            return;
        }
    }
    przedmioty->push_back(przedmiot);
    return;
}

void Pracownik::removePrzedmiot(string przedmiot){
    if(przedmioty == nullptr){
        cout << "Ten pracownik nie prowdzi zadnego przedmiotu"<<endl;
        return;
    }
    for (int i = 0; i < przedmioty->size(); i++) {
        if((*przedmioty)[i] == przedmiot){
            przedmioty->erase(przedmioty->begin()+ i);
            return;
        }
    }
    cout<< "Ten pracownik nie prowadzi takiego przedmiotu"<<endl;
    return;
}
bool Pracownik::teaches(string przedmiot){
    if(przedmioty == nullptr){
        cout << "Ten pracownik nie prowdzi zadnego przedmiotu"<<endl;
        return false;
    }
    for (int i = 0; i < przedmioty->size(); i++) {
        if((*przedmioty)[i] == przedmiot){
            return true;
        }
    }
    return false;
}

void Pracownik::przedstaw(){
    Osoba::przedstaw();
    if(przedmioty == nullptr){
        cout << "Ten pracownik nie prowdzi zadnego przedmiotu"<<endl;
        return;
    }
    for (int i = 0; i < przedmioty->size(); i++) {
        cout << (*przedmioty)[i] <<endl;
    }
    return;
}

void Pracownik::readPrzedmiots(){
     if(przedmioty == nullptr){
        cout << "Ten pracownik nie prowdzi zadnego przedmiotu"<<endl;
        return;
    }
    for (int i = 0; i < przedmioty->size(); i++) {
        cout << (*przedmioty)[i] <<endl;
    }
    return;
}