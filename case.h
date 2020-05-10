class Case
{
private:
    /* data */
    int pos;  // la position de la case dans la roue
    const char * name;
    const char * effect;        //Le type d'effets aue va produire une case(ajout d'argent,banqueroute, voyage etc....)

public:
    /*constructor*/
    Case(int pos, const char * name, const char * effect);
    /* functions */
    const char * getName();
    int getPos();
    const char * getEffect();
};
Case::Case(int pos, const char * name, const char * effect){
    this->pos = pos;
    this->name = name;
    this->effect = effect;
}