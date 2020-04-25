#include <string>
#include "player.h"

void Player::addGains(int gain){
	gains += gain;
}
int Player::getGains()const{
	return gains;
}
string Player::getDeviner()const{
	return deviner;
}