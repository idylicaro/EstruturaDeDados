//
// Created by Alucard on 26/11/2019.
//
#include <iostream>
using namespace std;

typedef int Apontador;
typedef struct Titem{
    int chave;
}Titem;
typedef struct Tpilha{
    Titem arrayPilha[10];
    Apontador p; //vai salvar o ultimo elemento;
}Tpilha;
bool fullPilha(Tpilha pilha){
    return (pilha.p == 0) ? true:false;
}
bool emptyPilha(Tpilha pilha){
    return (pilha.p == 10) ? true:false;
}
void empilhar(Tpilha &pilha,Titem item){
    if(fullPilha(pilha)){
        cout << "Pilha Cheia"<<endl;
    }else{
        pilha.arrayPilha[pilha.p-1] = item;
        pilha.p--;
    }
}
void desempilhar(Tpilha &pilha){
    if(emptyPilha(pilha)){
        cout << "Pilha Vazia"<<endl;
    }else{
        pilha.p++;
    }
}
void display(Tpilha pilha){
    if(emptyPilha(pilha)){
        cout << "Pilha Vazia"<<endl;
    }else{
        for (int i = pilha.p; i < 10 ; i++){
            cout <<pilha.arrayPilha[i].chave<<" | ";
        }
        cout <<endl;
    }
}
void inicializarPilha(Tpilha &pilha){
    for (int i = 0; i <10 ; i++) {
        pilha.arrayPilha[i].chave = 0;
    }
}
/*
void inverterPilha(Tpilha &pilha){
    Titem
}
*/