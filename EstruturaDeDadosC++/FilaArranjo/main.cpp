#include <iostream>
#include "FilaBackend.h"
using namespace std;

void setItem(TInfo &item);
int  menu();

int main() {
    TFila fila;
    TInfo item;

    fila.Total = 0;
    fila.Primeiro = -1;
    fila.Ultimo = -1;

    int op=-1; //opção
    op = menu();

    while(op!=0) {

        switch (op){
            case 1:
                setItem(item);
                InsereNofim(fila,item);
                system("cls");
                break;
            case 2:
                RemoveInicio(fila);
                system("cls");
                break;
            case 3:
                display(fila);
                break;
            default:
                cout <<"Opção invalida"<<endl;
                op=-1;
        }
        system("cls");
        display(fila);
        op = menu();
    }

    return 0;
}
int  menu(){
    int op;
    cout << "Menu\n"
         <<"1-Inserir um elemento no fim\n"
         <<"2-Retirar o elemento do inicio\n"
         <<"3-Imprimir fila\n"
         <<"0-Sair"<<endl; cin>>op;
    cout <<endl;
    return op;
}
void setItem(TInfo &item){
    cout << "Digite a chave:"<<endl;
    cin >> item.Chave;
    cin.ignore();
}