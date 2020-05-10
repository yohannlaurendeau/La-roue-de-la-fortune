#include "roue.h"
#include "case.h"
#include <list>
#include <iostream> //rand()


using namespace std;



int Roue::getNbCases(){
    return listCases.size();
}


int Roue::tournerRoue(){
    return 1 +(rand()%getNbCases());
}

std::list<Case> Roue::getCases(){
    return listCases;
}
