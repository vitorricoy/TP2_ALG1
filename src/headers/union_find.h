#include <vector>

using namespace std;

class UnionFind {
    public:
        // Constrói o union find
        UnionFind(int n);
        // Encontra qual conjunto do union-find o vértice pertence
        int encontrarConjunto(int vertice);
        // Determina que dois vértices pertencem ao mesmo conjunto
        void unirConjunto(int vertice1, int vertice2);
    private:
        // Guarda o identificador do pai do conjuntos de cada vértice
        vector<int> pai;
        // Guarda o tamanho do conjunto de cada vértice-pai
        vector<int> tam;
};