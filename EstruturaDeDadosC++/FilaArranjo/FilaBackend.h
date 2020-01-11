#include <iostream>
using namespace std;

const int Tmax = 10;
typedef int Apontador;
typedef struct {
    int Chave;
/*outros componentes*/
} TInfo;
typedef struct {
    TInfo Item[Tmax];
    Apontador Primeiro;
    Apontador Ultimo;
    int Total;
} TFila;
bool full(TFila fila){
    if(fila.Total == Tmax)
        return true;
    return false;
}
bool Empty(TFila fila){
    if(fila.Total == 0)
        return true;
    return false;
}
void InsereNofim(TFila &fila,TInfo item) { // esquerda -> direita
    if (full(fila)) {
        cout << "Fila Cheia" << endl;
    } else{
        if(Empty(fila)){
            fila.Primeiro = 0;
            fila.Ultimo = fila.Primeiro;
            fila.Item[fila.Primeiro] = item;
            fila.Total++;
        }else {
            fila.Item[++fila.Ultimo] = item;
            fila.Total++;
        }
    }
}
void RemoveInicio(TFila &fila){
    if(Empty(fila)){
        cout << "fila vazia"<<endl;
    }else{
        int i;
        for (i = 0; i < fila.Ultimo; ++i) {
          fila.Item[i] = fila.Item[i+1];
        }
        fila.Ultimo--;
        fila.Total--;
    }
}
void display(TFila fila){
    if(Empty(fila)){
        cout << "fila vazia"<<endl;
    }else{
        for (int i = 0; i < fila.Total ; ++i) {
            cout << fila.Item[i].Chave<<" ";
        }
        cout <<endl;
    }
}

