#include "case.h"
#include "list"

class Roue
{
private:
    /* data */
    int nbCases;// Pas sur de l utiliser
    std::list<case> roue;

public:
    Roue tournerRoue();
    int getNbCases();
    std::list<case> getCases();
};
Roue::Roue(std::list<case> roue){
    this->roue = roue;
}
