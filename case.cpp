#include "string"
#include "case.h"
#include "player.h"

using namespace std;

Case c1(0,"100","argent");
Case c2(0,"Banqueroute","ruine");

 string Case::getName(){
     return name;
 }

 int Case::getPos(){
     return pos;
 }

 string Case::getEffect(){
     return effect;
 }

 void Case::appliqueEffet(string effet){
    if Case.getEffect()=="argent"{
        Player.addGains(std::stoi(name) )//stoi String to Integer
    }
    else if Case.getEffect()=="ruine"{
        Player.setGain == 0;
    }
 }