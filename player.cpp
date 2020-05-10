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
/* void Player::getDevinerEnigmeR()const{
	return
} */

void Player::setGains(){
	gains = 0;
}

char * Player::GetNickname(){
	return nickname;
}

//std::list<string>consonne =('B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z');


/*void Player::DevinerLettre(){
    random consonne

    if player.get gain = 200
        voyelle.random

}
*/
