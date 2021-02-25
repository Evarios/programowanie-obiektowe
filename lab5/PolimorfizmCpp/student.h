#ifndef STUDENT
#define STUDENT
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include "osoba.h"
using namespace std;

class Student: public Osoba{
    private:
        vector<pair<string, int>> * oceny{nullptr};
    public:
        Student(){}
        Student(Student &);
        Student(Student &&);
        ~Student();
        void addGrade(string, int);
        void readGrade(string);
        void readAllGrades();
        void przedstaw();

};


#endif