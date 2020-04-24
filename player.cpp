#include <string>
#include "player.h"

void Player::addGains(int gains){
	this.gains = gains;
}
int Player::getGains()const{
	return gains;
}
string Player::getDeviner()const{
	return deviner;
}