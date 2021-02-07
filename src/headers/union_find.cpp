#include <algorithm>
#include <vector>
#include "union_find.h"

using namespace std;

UnionFind::UnionFind(int n) {
    tam = vector<int>(n);
    id = vector<int>(n);
    for(int I=0; I<n; I++) {
        tam[I] = 1;
        id[I] = I;
    }
}

int UnionFind::encontrarConjunto(int valor) {
    if(valor == id[valor]) {
        id[valor] = valor;
    } else {
        id[valor] = encontrarConjunto(id[valor]);
    }
    return id[valor];
}

void UnionFind::unirConjunto(int valor1, int valor2) {
    valor1 = encontrarConjunto(valor1);
    valor2 = encontrarConjunto(valor2);
	if(valor1 == valor2) return;
	if(tam[valor1] < tam[valor2]) {
        swap(valor1, valor2);
    }
	tam[valor1] += tam[valor2];
	id[valor2] = valor1;
}
