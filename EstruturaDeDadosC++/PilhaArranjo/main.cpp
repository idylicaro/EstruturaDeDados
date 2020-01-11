#include <iostream>
#include "PilhaArranjo.h"
using namespace std;

void setItem(Titem &item);
int  menu();

int main() {
    Tpilha pilha;
    pilha.p = 10; //inicializando o a variavel que aponta para o ultimo elemento.
    Titem item;
    int op=-1; //opção
    op = menu();
    display(pilha);
    while(op!=0) {

        switch (op){
            case 1:
            setItem(item);
            empilhar(pilha,item);
            system("cls");
                break;
            case 2:
                desempilhar(pilha);
                system("cls");
                break;
            case 3:
                display(pilha);
                break;
            default:
                cout <<"Opção invalida"<<endl;
                op=-1;
        }
        system("cls");
        display(pilha);
        cout <<" \tP:" <<pilha.p<<endl;
        op = menu();
    }
    return 0;

}
void setItem(Titem &item){
    cout << "Digite a chave:"<<endl;
    cin >> item.chave;
    cin.ignore();
}
int  menu(){
    int op;
    cout << "Menu\n"
         <<"1-Empilhar\n"
         <<"2-desempilhar\n"
         <<"3-Imprimir pilha\n"
         <<"0-Sair"<<endl; cin>>op;
         cout <<endl;
    return op;
}