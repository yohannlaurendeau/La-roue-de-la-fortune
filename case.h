class Case
{
private:
    /* data */
    int pos;  // la position de la case dans la roue
    std::string name;
    std::string effect;        //Le type d'effets aue va produire une case(ajout d'argent,banqueroute, voyage etc....)

public:
    /* functions */
    std::string getName();
    int getPos();
    std::string getEffect();
};