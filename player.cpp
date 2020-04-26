#include <string>
#include "player.h"

using namespace std;

void Player::addGains(int gain){
	gains += gain;
}
int Player::getGains()const{
	return gains;
}
string Player::getDeviner()const{
	return deviner;
}