class Case
{
private:
    /* data */
    int pos;  // la position de la case dans la roue
    std::string name;
    std::string effect;        //Le type d'effets aue va produire une case(ajout d'argent,banqueroute, voyage etc....)

public:
    /*constructor*/
    Case();
    /* functions */
    std::string getName();
    int getPos();
    std::string getEffect();
};
Case::Case(int pos,std::string name,std::string effect){
    this->pos = pos;
    this->name = name;
    this->effect = effect;
}