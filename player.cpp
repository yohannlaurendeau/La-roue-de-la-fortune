#include <string>
#include "player.h"

using namespace std;

Player::Player(char * nickname,int idPlayer) {
		this->idPlayer = idPlayer;
		this->gains = 0;
		this->nickname = nickname;
}

void Player::addGains(int gain) {
	gains += gain;
}
int Player::getGains()const {
	return gains;
}
/* void Player::getDevinerEnigmeR()const{
	return
} */

void Player::setGains() {
	gains = 0;
}

char * Player::GetNickname() {
	return nickname;
}


//std::list<string>consonne ={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
//std::list<string>voyelle ={'a','e','i','o','u','y'};


/*string Player::DevinerLettre(){
    int total = consonne.size();
    string lettre = consonne[rand()%total + 1];
    string enigme = getEnigmeL();
    char dejaDeviner[enigme.size()];

    size_t found = enigme.find(lettre);
    if (found != string::npos){
        dejaDeviner[found] = lettre;
        enigme.erase(enigme.begin()+found - 1);
        DevinerLettre();
    }
}
*/
