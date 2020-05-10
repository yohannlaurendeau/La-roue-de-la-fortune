#include "string"
#include "case.h"
#include "player.h"

using namespace std;


Case::Case() {
    this->effect = "";
    this->name = "";
}

const char * Case::getName(){
     return name;
}

const char * Case::getEffect(){
     return effect;
}

void Case::setValues(const char * name, const char * effect) {
    this->effect = effect;
    this->name = name;
}