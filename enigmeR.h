class enigmeR {
    private:
        std::string enigme;
    public:
        string getEnigme();
        int genererEnigme();
        int getNbTextes();


};

enigmeR::enigmeR(std::string enigme){
    this->enigme = enigme;
}
