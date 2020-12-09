#include <stdio.h>
#include "tree.h"

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->esq->esq = criaNo('D');
    raiz->esq->dir = criaNo('E');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('F');
    raiz->dir->dir = criaNo('G');

    imprime(raiz, 0);

    printf("\nPré-Ordem\n");
    preOrdem(raiz);

    printf("\nSimétrica\n");
    simetrica(raiz);

    printf("\nPós-Ordem\n");
    posOrdem(raiz);
};
