#ifndef BINARYTREEINC_TREE_H
#define BINARYTREEINC_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *inicializa(void);
void imprime(TNoA *nodo, int tab);
TNoA *criaNo(char ch);
void preOrdem(TNoA* a);
void simetrica(TNoA* a);
void posOrdem(TNoA* a);

#endif //BINARYTREEINC_TREE_H
