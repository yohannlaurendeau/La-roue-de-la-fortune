#include "roue.h"
#include "case.h"
#include <list>
#include <time.h>   // pour rand
using namespace std;


std::list<case> roue;

roue.insert(new Case(0,"100","argent"));
roue.insert(new Case(1,"Banqueroute","ruine"));
roue.insert(new Case(2,"0","argent"));
roue.insert(new Case(3,"passe","passe"));


int Roue::getNbCases(){
    return roue.size();
}


Roue::tournerRoue(){
    return 1 +(rand()%getNbCases());
}

string Roue::getCases(){
    return roue;
}
