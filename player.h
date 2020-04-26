class Player{
public:
	Player(int gains, std::string nickname,int idPlayer,std::string deviner);
	int getGains() const;
	void addGains(int gains);
	std::string getDeviner() const;

private:
	int gains;
	std::string nickname;
	int idPlayer;
	std::string deviner;
};
