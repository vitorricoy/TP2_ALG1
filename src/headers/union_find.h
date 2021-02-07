class UnionFind {
    public:
        UnionFind(int n);
        int encontrarConjunto(int valor);
        void unirConjunto(int valor1, int valor2);
    private:
        vector<int> id;
        vector<int> tam;
};