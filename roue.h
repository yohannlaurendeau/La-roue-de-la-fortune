#include "case.h"
#include "list"

class Roue
{
private:
    /* data */
    int nbCases;
    std::list<Case> cases; 

public:
    Case tournerRoue(){};
    int getNbCases(){};
    std::list<Case> getCases(){};
};