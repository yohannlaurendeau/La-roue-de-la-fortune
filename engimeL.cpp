#include "enigmeL.h"
#include <list>

std::list<string> texteL;
texteL.insert("La grande roue");
texteL.insert("J adore le c");

int EnigmeL::getNbTextesL(){
    return texteL.size();
}

int genererEnigmeL(){
    return (rand()%getNbTextesL());
}
string getEnigmeL(){
    return texteL[genererEnigmeL()];
}
