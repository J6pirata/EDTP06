#include <iostream>
using namespace std;

#define MAX 10

struct Pilha {
    int qtde;
    float elementos[MAX];
};

Pilha* init() {
    Pilha* p = new Pilha();
    p->qtde = 0;
    return p;
}

int isEmpty(Pilha* p) {
    return (p->qtde == 0);
}

int count(Pilha* p) {
    return (p->qtde);
}

void freePilha(Pilha* p) {
    free(p);
}

int push(Pilha* p, float v) {
    int podeEmpilhar = (p->qtde < MAX);
    if (podeEmpilhar) {
        p->elementos[p->qtde++] = v;
    }
    return podeEmpilhar;
}

float pop(Pilha* p) {
    float v;
    int podeDesempilhar = (!isEmpty(p));
    if (podeDesempilhar) {
        v = p->elementos[p->qtde - 1];
        p->qtde--;
    } else {
        v = -1;
    }
    return v;
}

void print(Pilha* p) {
    cout << "Qtde de elementos: " << count(p) << endl;
    cout << "-----------------------" << endl;
    for (int i = p->qtde - 1; i >= 0; --i) {
        cout << p->elementos[i] << endl;
    }
    cout << "-----------------------" << endl;
}

int main() {
    Pilha* parPilha = init();
    Pilha* imparPilha = init();
    float numeroAnterior = 0;

    cout << "Digite 30 numeros inteiros em ordem crescente:" << endl;

    for (int i = 0; i < 30; i++) {
        float numero;
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> numero;

        if (numero > numeroAnterior) {
            if ((numero) % 2 == 0) {
                push(parPilha, numero);
            } else {
                push(imparPilha, numero);
            }
            numeroAnterior = numero;
        } else {
            cout << "Numero digitado nao eh maior do que o anterior. Tente novamente." << endl;
            i--;
        }
    }

    cout << endl << "Valores desempilhados em ordem decrescente: " << endl;
    while (!isEmpty(parPilha)) {
        cout << pop(parPilha) << endl;
    }
    while (!isEmpty(imparPilha)) {
        cout << pop(imparPilha) << endl;
    }

    freePilha(parPilha);
    freePilha(imparPilha);

    return 0;
}