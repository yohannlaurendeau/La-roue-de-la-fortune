#include "string"
#include "case.h"
#include "player.h"

using namespace std;


 const char * Case::getName(){
     return name;
 }

 int Case::getPos(){
     return pos;
 }

 const char * Case::getEffect(){
     return effect;
 }