class ValorAresta {
    public:
        // Construtor
        ValorAresta(int endpoint1, int endpoint2, int custo, int atratividade);
        // Comparador entre duas arestas
        bool operator <(const ValorAresta& comp);
        // Obtem o primeiro endpoint da aresta
        int getEndpoint1();
        // Obtem o segundo endpoint da aresta
        int getEndpoint2();
        // Obtem o custo da aresta
        int getCusto();
        // Obtem a atratividade da aresta
        int getAtratividade();
    private:
        int endpoint1;
        int endpoint2;
        int custo;
        int atratividade;
};