#include "enigmeR.h"
#include "player.h"
#include "string"
#include "iostream"
#include <list>

using namespace std;

int const nbDeTextes(4);
std::list<string> texte;
texte.insert("Pas de Bol");
texte.insert("C'est zero en c");

void EnigmeR::devinette(texte){
    if(Player.getDeviner == texte){
        return true;
    }
        else
        {
            return false;
        }

}
int EnigmeR::getNbTextes(){
    return texte.size();
}

void EnigmeR::getEnigme(){
    return 1 + (rand()%getNbTextes());
}
