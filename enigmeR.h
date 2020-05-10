class enigmeR {
    private:
        std::string enigme;
    public:
        void getEnigme();
        void genererEnigme();

};

enigmeR::enigmeR(std::string enigme){
    this->enigme = enigme;
}
