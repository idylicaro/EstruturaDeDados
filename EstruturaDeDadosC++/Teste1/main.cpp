#include <iostream>
using namespace std;
#include<locale.h>
#include<stdlib.h>

#include "Lista_Encadeada.h"

// ------------------------------------------------------------------------
int enterChoice(TLista &lista) {
    system("cls");
    Imprime(lista);
    int menuChoice;
    cout << "\nMenu :" << endl
         << "1 - Insere no Inicio \n"
         << "2 - Insere na Posicao \n"
         << "3 - Insere no Final \n"
         << "4 - Remove do Inicio \n"
         << "5 - Remove do Final \n"
         << "6 - Pesquisa e Remove \n"
         << "7 - Imprime \n"
         << "8 - Fim do programa \n"
         << " Opcao : ";
    cin >> menuChoice;
    return menuChoice;
}

void setDados(TInfo &item) {
    cout << "\nInforme o Codigo : ";
    cin >> item.Chave;
}

void setPosicao(int &pos) {
    cout << "\nInforme a Posicao : ";
    cin >> pos;
}


int main() {
    setlocale(LC_ALL, "");
    TLista lista;   //tudo que era l mudar para Lista
    TInfo item;
    int p;
    criaLista(lista);


    short int opcao;
    while ((opcao = enterChoice(lista)) != 8) {
        switch (opcao) {
            case 1 :
                setDados(item);
                InsereInicio(lista, item);
                break;
            case 2 :
                setDados(item);
                setPosicao(p);
                InserePosicao(lista, p, item);
                break;
            case 3 :
                setDados(item);
                InsereFinal(lista, item);
                break;
            case 4 :
                RemoveInicio(lista);
                break;
            case 5 :
                RemoveFinal(lista);
                break;
            case 6 :
                setDados(item);
                // PesquisaRemove (l, item . Chave );
                break;
            case 7 :
                Imprime(lista);
                break;
            default :
                cerr << " Opcao incorreta \n";
                break;
        }
    }
    return 0;
}

