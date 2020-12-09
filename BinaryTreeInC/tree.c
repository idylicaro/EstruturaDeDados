#include "tree.h"

TNoA *inicializa(void) {
    return NULL;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void preOrdem(TNoA* a) {
    if (a!= NULL){
        printf("%c\n",a->info);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void simetrica(TNoA* a) {
    if (a!= NULL){
        simetrica(a->esq);
        printf("%c\n",a->info);
        simetrica(a->dir);
    }
}

void posOrdem(TNoA* a) {
    if (a!= NULL){
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%c\n",a->info);
    }
}