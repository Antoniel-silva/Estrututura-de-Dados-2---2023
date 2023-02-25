#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	int info;
    struct arv *esq;
	struct arv *dir;
}Arv;

Arv *arvore(int x,Arv *d,Arv *e){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	return novo;
	
}



void imprime(no *n){
    if (raiz==NULL){
        count<<"\n <VAZIO>";
    }
    else{
        if (n!=NULL){
            count<<"<"<<n->info;
            imprime(n->esq);
            imprime(n->dir);
            count<<">";
        }
        else {
            cout<<"<>";
        }
        
    }
}


void emnivel (Arv A) {
    if( A==NULL ) return;
    Fila F = fila(MAx);
    enfileira(A,F);
    while( !vaziaf (F) ) {
        Arv A = desenfileira(F);
        printf(fmt, A->item);
        if( A->esq != NULL ) enfileira(a->esq, F);
        if( A->dir != NULL ) enfileira(A->dir, F)
    }
}


Arv arv(Arv e, Item x, Arv d) {
    Arv n = malloc(sizeof(Struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;
    return n;
}

main(){

	
}


