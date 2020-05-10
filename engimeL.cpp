#include "enigmeL.h"
#include <list>
#include <vector>
#include <string>

using namespace std;


void EnigmeL::makeEnigme(const char * enigmes[]) {
    for (int i = 0; i < nbEnigmes; i++) {
        texteL[i] = enigmes[i];
    } 
}


int EnigmeL::getNbTextesL(){
    return texteL.size();
}

int EnigmeL::genererEnigmeL(){
    return (rand()%getNbTextesL());
}

const char EnigmeL::getEnigmeL(){
    return texteL[genererEnigmeL()];
}
