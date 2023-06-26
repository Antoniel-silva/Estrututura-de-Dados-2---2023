#include <iostream>

using namespace std;


// Grupo: Antoniel William e Lucas Coêlho

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

    // Construção da árvore
    raiz = new No(1);
    raiz->esquerda = new No(2);
    raiz->direita = new No(3);
    raiz->esquerda->esquerda = new No(4);
    raiz->esquerda->direita = new No(5);

    // Realizar rotações
    rotacaoDireita(raiz);
    rotacaoEsquerda(raiz->direita);
    rotacaoEsquerdaDireita(raiz->esquerda);

    // Imprimir a árvore em ordem
    cout << "Percurso em ordem da árvore: ";
    percursoEmOrdem(raiz);
    cout << endl;

    return 0;
}
