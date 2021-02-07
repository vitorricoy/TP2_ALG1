#include "valor_aresta.h"

// Construtor
ValorAresta::ValorAresta(int endpoint1, int endpoint2, int custo, int atratividade) {
    this->endpoint1 = endpoint1;
    this->endpoint2 = endpoint2;
    this->custo = custo;
    this->atratividade = atratividade;
}

// Comparador entre duas arestas
bool ValorAresta::operator <(const ValorAresta& comp) {
    // Se a aresta tem um custo menor ela é menor
    if(this->custo < comp.custo) {
        return true;
    }
    // Se as arestas tem um custo igual, a aresta de maior atratividade é menor
    if(this->custo == comp.custo && this->atratividade > comp.atratividade) {
        return true;
    }
    return false;
}

// Obtem o primeiro endpoint da aresta
int ValorAresta::getEndpoint1() {
    return this->endpoint1;
}

// Obtem o segundo endpoint da aresta
int ValorAresta::getEndpoint2() {
    return this->endpoint2;
}

// Obtem o custo da aresta
int ValorAresta::getCusto() {
    return this->custo;
}

// Obtem a atratividade da aresta
int ValorAresta::getAtratividade() {
    return this->atratividade;
}
