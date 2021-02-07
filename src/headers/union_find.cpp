#include <algorithm>
#include <vector>
#include "union_find.h"

using namespace std;

// Constrói o union find
UnionFind::UnionFind(int n) {
    // Inicializa os vetores
    tam = vector<int>(n);
    pai = vector<int>(n);
    for(int I=0; I<n; I++) {
        // Todo vértice começa como id de seu 
        // próprio conjunto de tamanho um
        tam[I] = 1;
        pai[I] = I;
    }
}

// Encontra qual conjunto do union-find o vértice pertence
int UnionFind::encontrarConjunto(int vertice) {
    // Se o vértice é o seu próprio pai, chegamos no vértice-pai do conjunto
    // Se ele não é o própio pai, ainda não encontramos o id do conjunto
    if(vertice != pai[vertice]) {
        // Guarda o id do pai do conjunto como o pai do vértice
        pai[vertice] = encontrarConjunto(pai[vertice]);
    }
    // Retorna o id do conjunto
    return pai[vertice];
}

// Determina que dois vértices pertencem ao mesmo conjunto
void UnionFind::unirConjunto(int vertice1, int vertice2) {
    // Salva o valor do id do conjunto de cada um dos vertices
    vertice1 = encontrarConjunto(vertice1);
    vertice2 = encontrarConjunto(vertice2);
    // Se eles pertencem ao mesmo conjunto, já estão unidos
	if(vertice1 == vertice2) return;
    // Determina que o vertice1 é o vértice que possui um numero 
    // maior de vertices em seu conjunto
	if(tam[vertice1] < tam[vertice2]) {
        swap(vertice1, vertice2);
    }
    // Atualiza o tamanho do conjunto de vertice1, adicionando os 
    // vertices do conjunto de vertice2 a ele
	tam[vertice1] += tam[vertice2];
    // Determina que o vertice2 pertence ao conjunto de vertice1
	pai[vertice2] = vertice1;
}
