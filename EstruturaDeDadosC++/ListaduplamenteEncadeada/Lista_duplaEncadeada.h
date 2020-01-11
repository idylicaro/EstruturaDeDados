typedef struct NodoLista *Apontador;

typedef struct
{
    int Chave;
    /*outros componentes*/
} TInfo;

struct NodoLista
{
    TInfo Item;
    struct NodoLista *Proximo;
    struct NodoLista *Anterior;
};

typedef struct
{
    struct NodoLista *Primeiro;
    struct NodoLista *Ultimo;
} TLista;
bool vazia(TLista lista);

void criaLista(TLista &Lista){
    Apontador p = (Apontador) malloc(sizeof(struct NodoLista));
    Lista.Primeiro = p;
    Lista.Ultimo = Lista.Primeiro;
    Lista.Primeiro->Proximo = NULL;
    Lista.Primeiro->Anterior = NULL;
}
void InsereInicio(TLista &Lista,TInfo Item){
    Apontador p = (Apontador) malloc(sizeof(struct NodoLista));
    p->Item = Item;
    p->Anterior = NULL;
    p->Proximo = Lista.Primeiro->Proximo;
    if(p->Proximo == NULL){
        Lista.Ultimo = p;
    }else{
    p->Proximo->Anterior = p;

    }
    Lista.Primeiro->Proximo = p;


}
void RemoveInicio(TLista lista){
    if(vazia(lista)){
        cout <<"Não tem nada na lista!"<<endl;
    }else{
        Apontador p = lista.Primeiro;
        if(p->Proximo == NULL){
            lista.Primeiro = NULL;
            lista.Ultimo = NULL;
        }else{
        Apontador aux = p->Proximo;
        aux->Anterior = NULL;
        lista.Primeiro = aux;
        free(p);
        }
    }

}
void InsereFinal(TLista &lista,TInfo Item){
    Apontador p = (Apontador)malloc(sizeof(struct NodoLista));
    Apontador aux;
    p->Item = Item;
    p->Proximo = NULL;
    aux = lista.Ultimo->Anterior->Proximo;
    aux->Proximo = p;
    p->Anterior = aux;
    lista.Ultimo = p;
}
bool vazia(TLista lista){
    return (lista.Primeiro->Proximo == NULL) ? true:false;
}
void Imprime(TLista lista){
    Apontador p = lista.Primeiro->Proximo;
    if(p){
    while(p!= NULL){
        cout<< p->Item.Chave <<" ";
        p = p->Proximo;
    }
    }else{
        cout<<"Lista vazia"<<endl;
    }
    cout<<endl;

}
void InserePosicao(TLista lista ,int pos,TInfo item){
    int i=0;
    Apontador p = (Apontador)malloc(sizeof(struct NodoLista));
    Apontador aux = lista.Primeiro->Proximo;
    p->Item = item;
    while(i<pos){
        aux=aux->Proximo;
        i++;
    }
    p->Proximo = aux->Proximo;
    p->Anterior = aux;
    aux->Proximo = p;
}
void RemoveFinal(TLista lista){
    if(vazia(lista)){
        cout <<"Não tem nada na lista!"<<endl;
    }else{
    if(lista.Ultimo->Anterior == NULL){
        RemoveInicio(lista);
    }else{
    Apontador p = lista.Ultimo->Anterior;
    Apontador aux = lista.Ultimo;
    p->Proximo = NULL;
    lista.Ultimo = p;
    free(aux);
    }
    }


}
