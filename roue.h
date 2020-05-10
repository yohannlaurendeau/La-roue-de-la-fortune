#include "case.h"
#include "list"

class Roue
{
private:
    /* data */
    int nbCases;        // Pas sur de l utiliser
    std::list<Case> listCases;

public:
    Roue();
    int tournerRoue();
    int getNbCases();
    std::list<Case> getCases();
    void setCases();
};

Roue::Roue(){
    this->listCases = new list<Case>();
    this->nbCases = 0;
}
