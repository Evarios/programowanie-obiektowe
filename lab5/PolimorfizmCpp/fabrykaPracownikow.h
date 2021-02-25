#ifndef FABRYKAPRACOWNIKOW
#define FABRYKAPRACOWNIKOW
#include "fabrykaOsob.h"
#include "pracownik.h"

class FabrykaPracownikow : public FabrykaOsob{
public:
    Pracownik * utworz();
};

#endif