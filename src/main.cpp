#include <iostream>
#include <vector>
#include <algorithm>
#include "headers/valor_aresta.h"
#include "headers/union_find.h"

using namespace std;

// Algoritmo de Kruskal
vector<ValorAresta> kruskal(int n, vector<ValorAresta> arestas) {
    // Inicializa o union find
	UnionFind unionFind(n);
    // Vetor com o resultado do algoritmo
    vector<ValorAresta> retorno;
    // Ordena as arestas pelo menor custo e maior atratividade, nessa ordem
	sort(arestas.begin(), arestas.end());
    // Para cada aresta no vetor ordenado de arestas
	for(ValorAresta aresta : arestas) {
        // Obtem os endpoints
		int endpoint1 = aresta.getEndpoint1();
        int endpoint2 = aresta.getEndpoint2();
        // Se os endpoints não estão no mesmo conjunto (a aresta não cria um ciclo)
		if(unionFind.encontrarConjunto(endpoint1) != unionFind.encontrarConjunto(endpoint2)) {
            // Determina que os vértices dos endpoints estão no mesmo conjunto
			unionFind.unirConjunto(endpoint1, endpoint2);
			// Insere a aresta no retorno do algoritmo
            retorno.push_back(aresta);
		}
	}
    return retorno;
}


int main() {
    // Lê o número de vértices e de arestas
    int n, t;
    cin >> n >> t;
    // Lê os valores de atratividade de cada vértice
    vector<int> atratividade(n);
    for(int I=0; I<n; I++) {
        cin >> atratividade[I];
    }

    vector<ValorAresta> arestas;
    for(int I=0; I<t; I++) {
        // Lê os endpoints e custo de cada aresta
        int endpoint1, endpoint2, custo;
        cin >> endpoint1 >> endpoint2 >> custo;
        // Calcula a atratividade ganha ao adicionar essa aresta
        int atratividadeTrecho = atratividade[endpoint1]+atratividade[endpoint2];
        arestas.push_back(ValorAresta(endpoint1, endpoint2, custo, atratividadeTrecho));
    }
    // Executa o algoritmo de Kruskal
    vector<ValorAresta> mst = kruskal(n, arestas);
    
    // Percorre a MST salvando o custo total, atratividade total 
    // e o grau de cada vértice
    int custoMST = 0, atratividadeMST = 0;
    vector<int> grauVerticeMST(n);
    for(ValorAresta aresta : mst) {
        custoMST += aresta.getCusto();
        atratividadeMST += aresta.getAtratividade();
        grauVerticeMST[aresta.getEndpoint1()]++;
        grauVerticeMST[aresta.getEndpoint2()]++;
    }
    // Imprime o custo e atratividade total da MST
    cout << custoMST << " " << atratividadeMST << endl;
    // Imprime o grau de cada vértice na MST
    for(int grau : grauVerticeMST) {
        cout << grau << " ";
    }
    cout << endl;
    // Imprime as arestas escolhidas para a MST
    for(ValorAresta aresta : mst) {
        cout << aresta.getEndpoint1() << " " << aresta.getEndpoint2() << " " << aresta.getCusto() << endl;
    }
    return 0;
}