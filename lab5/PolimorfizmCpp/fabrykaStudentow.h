#ifndef FABRYKASTUDENTOW
#define FABRYKASTUDENTOW
#include "fabrykaOsob.h"
#include "student.h"

class FabrykaStudentow : public FabrykaOsob{
public:
    Student * utworz();
};
#endif
