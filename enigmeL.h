class EnigmeL{
    public:
        EnigmeL(int nbenigme);
        int genererEnigmeL();
        const char getEnigmeL();
        int getNbTextesL();
        void makeEnigme(const char * enigmes[]);
        void changeTexteL();


    private:
        const char * enigme;
        const char * texteL[];
        int nbEnigmes;

};

EnigmeL::EnigmeL(int nbEnigme) {
    this->enigme = "";
    this->nbEnigmes = 0;
}
