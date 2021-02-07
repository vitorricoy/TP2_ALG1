#include <iostream>
#include <vector>
#include <algorithm>
#include "headers/valor_aresta.h"
#include "headers/union_find.h"

using namespace std;

vector<ValorAresta> kruskal(int n, vector<ValorAresta> arestas) {
	UnionFind unionFind(n);
    vector<ValorAresta> retorno;
	sort(arestas.begin(), arestas.end());
	for(ValorAresta aresta : arestas) {
		int endpoint1 = aresta.getEndpoint1();
        int endpoint2 = aresta.getEndpoint2();
		if(unionFind.encontrarConjunto(endpoint1) != unionFind.encontrarConjunto(endpoint2)) {
			unionFind.unirConjunto(endpoint1, endpoint2);
			// aresta faz parte da AGM
            retorno.push_back(aresta);
		}
	}
    return retorno;
}


int main() {
    int n, t;
    cin >> n >> t;
    vector<int> atratividade(n);
    for(int I=0; I<n; I++) {
        cin >> atratividade[I];
    }
    vector<ValorAresta> arestas;
    for(int I=0; I<t; I++) {
        int endpoint1, endpoint2, custo;
        cin >> endpoint1 >> endpoint2 >> custo;
        int atratividadeTrecho = atratividade[endpoint1]+atratividade[endpoint2];
        arestas.push_back(ValorAresta(endpoint1, endpoint2, custo, atratividadeTrecho));
    }
    vector<ValorAresta> mst = kruskal(n, arestas);
    int custoMST = 0, atratividadeMST = 0;
    vector<int> grauVerticeMST(n);
    for(ValorAresta aresta : mst) {
        custoMST += aresta.getCusto();
        atratividadeMST += aresta.getAtratividade();
        grauVerticeMST[aresta.getEndpoint1()]++;
        grauVerticeMST[aresta.getEndpoint2()]++;
    }
    cout << custoMST << " " << atratividadeMST << endl;
    for(int grau : grauVerticeMST) {
        cout << grau << " ";
    }
    cout << endl;
    for(ValorAresta aresta : mst) {
        cout << aresta.getEndpoint1() << " " << aresta.getEndpoint2() << " " << aresta.getCusto() << endl;
    }
    return 0;
}