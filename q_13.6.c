#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;

struct no {
    struct no* esq;
    struct no* dir;
};

struct arvore {
    struct no* raiz;
    bool (*eb)(struct no*);  // Ponteiro para a função eb
};

bool eb_rec(struct no* no) {
    if (no == NULL) {  // Se o nó é nulo, a árvore é estritamente binária
        return true;
    }
    if (no->esq == NULL && no->dir == NULL) {  // Se o nó é uma folha, a árvore é estritamente binária
        return true;
    }
    if (no->esq != NULL && no->dir != NULL) {  // Se o nó tem dois filhos, verifique se ambos são estritamente binários
        return eb_rec(no->esq) && eb_rec(no->dir);
    }
    return false;  // Se o nó não tem dois filhos, a árvore não é estritamente binária
}

bool eb(struct no* raiz) {
    return eb_rec(raiz);
}

int main() {
    // Criação da árvore
    struct no* no1 = malloc(sizeof(struct no));
    struct no* no2 = malloc(sizeof(struct no));
    struct no* no3 = malloc(sizeof(struct no));
    struct no* no4 = malloc(sizeof(struct no));
    struct no* no5 = malloc(sizeof(struct no));
    no1->esq = no2;
    no1->dir = no3;
    no2->esq = no4;
    no2->dir = NULL;
    no3->esq = no5;
    no3->dir = NULL;
    no4->esq = NULL;
    no4->dir = NULL;
    no5->esq = NULL;
    no5->dir = NULL;
    struct arvore arv;
    arv.raiz = no1;
    arv.eb = eb;
    // Teste da função eb
    bool result = arv.eb(arv.raiz);
    if (result) {
        printf("A arvore eh estritamente binaria\n");
    } else {
        printf("A arvore nao eh estritamente binaria\n");
    }
    // Liberação da memória alocada
    free(no1);
    free(no2);
    free(no3);
    free(no4);
    free(no5);
    return 0;
}