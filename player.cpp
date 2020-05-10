#include <string>
#include "player.h"

using namespace std;

Player::Player(char * nickname,int idPlayer){
		this->idPlayer = idPlayer;
		this->gains = 0;
		this->nickname = nickname;
}

void Player::addGains(int gain){
	gains += gain;
}
int Player::getGains()const{
	return gains;
}
string Player::getDeviner()const{
	return deviner;
}
void Player::setGains(){
	gains = 0;
}

char * Player::GetNickname(){
	return nickname;
}