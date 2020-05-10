#include "case.h"
#include "list"

class Roue {

private:
    /* data */
    int nbCases;        
    Case listCases[12];

public:
    Roue(int nbcases);
    const char * tournerRoue();
    int getNbCases();
    Case* getCases();
    void setCases(Case listCases[]);
};