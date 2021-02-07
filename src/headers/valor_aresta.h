class ValorAresta {
    public:
        ValorAresta(int endpoint1, int endpoint2, int custo, int atratividade);
        bool operator <(const ValorAresta& comp);
        int getEndpoint1();
        int getEndpoint2();
        int getCusto();
        int getAtratividade();
    private:
        int endpoint1;
        int endpoint2;
        int custo;
        int atratividade;
};