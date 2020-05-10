class Player{
public:
	Player(char * nickname,int idPlayer);
	int getGains() const;
	void setGains();
	void addGains(int gains);
	std::string getDeviner() const;
	char * GetNickname();

private:
	int gains;
	char * nickname;
	int idPlayer;
	std::string deviner;
};
