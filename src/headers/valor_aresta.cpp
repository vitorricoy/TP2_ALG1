#include "valor_aresta.h"

ValorAresta::ValorAresta(int endpoint1, int endpoint2, int custo, int atratividade) {
    this->endpoint1 = endpoint1;
    this->endpoint2 = endpoint2;
    this->custo = custo;
    this->atratividade = atratividade;
}

bool ValorAresta::operator <(const ValorAresta& comp) {
    if(this->custo < comp.custo) {
        return true;
    }
    if(this->custo == comp.custo && this->atratividade > comp.atratividade) {
        return true;
    }
    return false;
}