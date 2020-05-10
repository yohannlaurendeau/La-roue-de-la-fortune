class Case
{
private:
    /* data */
    const char * name;
    const char * effect;        //Le type d'effets aue va produire une case(ajout d'argent,banqueroute, voyage etc....)

public:
    /*constructor*/
    Case();
    Case(const char * name, const char * effect);
    /* functions */
    const char * getName();
    const char * getEffect();
};


Case::Case(const char * name, const char * effect){
    this->name = name;
    this->effect = effect;
}

Case::Case(){
    this->effect = "";
    this->name = "";
}