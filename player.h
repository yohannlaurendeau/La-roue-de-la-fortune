class Player{
public:
	Player(int gains, string nickname,int idPlayer,string deviner);
	int getGains() const;
	void addGains(int gains);
	void getDeviner() const;

private:
	int gains;
	string nickname;
	int idPlayer;
	string deviner;
};
