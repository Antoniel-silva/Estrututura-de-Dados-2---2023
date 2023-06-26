#include <iostream>

using namespace std;


// Grupo: Antoniel William e Lucas Co�lho

struct No {
    int dado;
    No* esquerda;
    No* direita;

    explicit No(int valor) {
        dado = valor;
        esquerda = nullptr;
        direita = nullptr;
    }
};

void rotacaoDireita(No*& p) {
    No* q = p->esquerda;
    No* temp = q->direita;
    q->direita = p;
    p->esquerda = temp;
    p = q;
}

void rotacaoEsquerda(No*& p) {
    No* q = p->direita;
    No* temp = q->esquerda;
    q->esquerda = p;
    p->direita = temp;
    p = q;
}

void rotacaoEsquerdaDireita(No*& p) {
    rotacaoEsquerda(p->esquerda);
    rotacaoDireita(p);
}

void rotacaoDireitaEsquerda(No*& p) {
    rotacaoDireita(p->direita);
    rotacaoEsquerda(p);
}

void percursoEmOrdem(No* raiz) {
    if (raiz != nullptr) {
        percursoEmOrdem(raiz->esquerda);
        cout << raiz->dado << " ";
        percursoEmOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = nullptr;

    // Constru��o da �rvore
    raiz = new No(1);
    raiz->esquerda = new No(2);
    raiz->direita = new No(3);
    raiz->esquerda->esquerda = new No(4);
    raiz->esquerda->direita = new No(5);

    // Realizar rota��es
    rotacaoDireita(raiz);
    rotacaoEsquerda(raiz->direita);
    rotacaoEsquerdaDireita(raiz->esquerda);

    // Imprimir a �rvore em ordem
    cout << "Percurso em ordem da �rvore: ";
    percursoEmOrdem(raiz);
    cout << endl;

����return�0;
}
