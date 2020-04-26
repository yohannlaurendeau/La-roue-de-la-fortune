class Case
{
private:
    /* data */
    int pos;  // la position de la case dans la roue
    string name;
    string effect;        //Le type d'effets aue va produire une case(ajout d'argent,banqueroute, voyage etc....)

public:
    /* functions */
    string getName();
    int getPos();
    string getEffect();
};