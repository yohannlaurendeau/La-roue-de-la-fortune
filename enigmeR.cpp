#include "enigmeR.h"
#include "player.h"
#include "string"

int const nbDeTextes(3);
string texte[nbDeTextes];
texte[0] = "Pas De Bol";
texte[1] = "Soyez pas naif";
texte[2] = "Bonne chance";

void EnigmeR::devinette(texte){
    if(Player.getDeviner == texte){
        return true;
    }
        else
        {
            return false;
        }
        
}
