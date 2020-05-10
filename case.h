class Case {
private:
    /* data */
    const char * name;
    const char * effect;        //Le type d'effets aue va produire une case(ajout d'argent,banqueroute, voyage etc....)

public:
    /*constructor*/

    Case();

    /* functions */
    const char * getName();
    const char * getEffect();
    void setValues(const char * effect, const char * name);
};