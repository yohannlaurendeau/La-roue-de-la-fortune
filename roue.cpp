#include "roue.h"
#include "case.h"
#include <list>
#include <iostream> //rand()
#include "roue.h"


using namespace std;



int Roue::getNbCases(){
    return nbCases;
}


const char * Roue::tournerRoue(){
    int myCase = rand()%getNbCases();
    return listCases[myCase].getName();
}

Case * Roue::getCases(){
    return listCases;
}

void Roue::setCases(Case listcases[]){
    for (int i = 0; i < 12; i++) {
        listCases[i] = listcases[i];
    }
    
}