#include "enigmeR.h"
#include "player.h"
#include "string"
#include "iostream"
#include <list>

using namespace std;

std::list<string> texte;
texte.insert("Pas de Bol");
texte.insert("C'est zero en c");


int EnigmeR::getNbTextes(){
    return texte.size();
}

int EnigmeR::genererEnigme(){
    return (rand()%getNbTextes());
}

string EnigmeR::getEnigme(){
    return texte[genererEnigme()];// ON declare l'enigmeR avec cette methode pour generer une phrase aleatoire
}


