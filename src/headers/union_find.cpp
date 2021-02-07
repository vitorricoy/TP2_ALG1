#include <algorithm>
#include "union_find.h"

UnionFind::UnionFind(int n) {
    tam = vector<int>(n);
    id = vector<int>(n);
    for(int I=0; I<n; I++) {
        tam[I] = 1;
        id[I] = i;
    }
}

int UnionFind::encontrarConjunto(int valor) {
    if(valor == id[valor]) {
        id[a] = a;
    } else {
        id[a] = encontrarConjunto(id[a]);
    }
    return id[a];
}

void UnionFind::unirConjunto(int valor1, int valor2) {
    valor1 = encontrarConjunto(a);
    valor2 = encontrarConjunto(b);
	if(valor1 == valor2) return;
	if(tam[valor1] < tam[valor2]) {
        swap(valor1, valor2);
    }
	tam[valor1] += tam[valor2];
	id[valor2] = valor1;
}
