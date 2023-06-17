#include <iostream>
using namespace std;

struct No {
    float dado;
    struct No* prox;
};

struct Pilha {
    No* topo;
};

Pilha* init() {
    Pilha* p = new Pilha();
    p->topo = NULL;
    return p;
}

int isEmpty(Pilha* p) {
    return (p->topo == NULL);
}

int count(Pilha* p) {
    int i = 0;
    No* no = p->topo;
    while (no != NULL) {
        i++;
        no = no->prox;
    }
    return i;
}

void print(Pilha* p) {
    No* no = p->topo;
    cout << "--------------" << endl;
    cout << "Qtde de elementos: " << count(p) << endl;
    cout << "--------------" << endl;
    while (no != NULL) {
        cout << no->dado << endl;
        no = no->prox;
    }
    cout << "--------------" << endl;
}

void push(Pilha* p, float v) {
    No* no = new No();
    no->dado = v;
    no->prox = p->topo;
    p->topo = no;
}

float pop(Pilha* p) {
    float ret;
    int podeDesempilhar = (!isEmpty(p));
    if (podeDesempilhar) {
        No* no = p->topo;
        ret = no->dado;
        p->topo = p->topo->prox;
        free(no);
    } else {
        ret = -1;
    }
    return ret;
}

void freePilha(Pilha* p) {
    No* no = p->topo;
    while (no != NULL) {
        No* aux = no->prox;
        free(no);
        no = aux;
    }
    free(p);
}

int main() {
    Pilha* parPilha = init();
    Pilha* imparPilha = init();
    float numeroAnterior = 0;

    cout << "Digite 30 numeros em ordem crescente:" << endl;

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