#include <iostream>
#include <string>
#include "student.h"

Student::Student(Student &student)
:
oceny(nullptr)
{
    if(oceny!=nullptr){
        oceny = new vector<pair<string,int>>;
        *oceny = *student.oceny;
    }
}
Student::Student(Student &&student)
{
    oceny = move(student.oceny);
}
Student::~Student(){
    if(oceny!=nullptr) delete oceny;
}

void Student::addGrade(string nazwa, int ocena){
    if(ocena >=1 && ocena <=5){
        if(oceny == nullptr){
            oceny = new vector<pair<string, int>>;
        }
        oceny->push_back(make_pair(nazwa,ocena));
    }
}

void Student::readGrade(string s){
    for(int i = 0; i < oceny->size(); i++){
        if((*oceny)[i].first == s){
            cout << s << ": " << (*oceny)[i].second<<endl;
            return;
        }
    }
    cout <<"Brak oceny z takiego przedmiotu"<<endl;
    return;
}

void Student::readAllGrades(){
    if(oceny != nullptr){
        for(int i = 0; i < oceny->size(); i++){
            cout << (*oceny)[i].first << ": " << (*oceny)[i].second <<endl;
        }
        return;
    }
    return;
}

void Student::przedstaw(){
    Osoba::przedstaw();
    readAllGrades();
    return;
}
