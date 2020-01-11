typedef struct NodoLista *Apontador;

typedef struct {
    int Chave;
    /*outros componentes*/
} TInfo;

struct NodoLista {
    TInfo Item;
    struct NodoLista *Proximo;
};

typedef struct {
    struct NodoLista *Primeiro;
    struct NodoLista *Ultimo;
} TLista;

bool vazia(TLista lista);

void criaLista(TLista &Lista) {
    Apontador p = (Apontador) malloc(sizeof(struct NodoLista));
    Lista.Primeiro = p;
    Lista.Ultimo = Lista.Primeiro;
    Lista.Primeiro->Proximo = NULL;
}

void InsereInicio(TLista &Lista, TInfo Item) {
    Apontador p = (Apontador) malloc(sizeof(struct NodoLista));
    p->Item = Item;
    p->Proximo = Lista.Primeiro->Proximo;

    Lista.Primeiro->Proximo = p;

    if (p->Proximo == NULL) {
        Lista.Ultimo = p;
    }
}

void RemoveInicio(TLista lista) {
    if (vazia(lista)) {
        cout << "Não tem nada na lista!" << endl;
    } else {
        Apontador p = lista.Primeiro->Proximo; //aux que recebe o primeiro no
        cout << "Item Removido:" << p->Item.Chave << endl;
        lista.Primeiro->Proximo = p->Proximo;   //o prox do elemento p vira o primeiro no

        if (lista.Primeiro->Proximo == NULL)
            lista.Ultimo = lista.Primeiro;

        free(p);
    }

}

void InsereFinal(TLista &lista, TInfo Item) {
    Apontador p = (Apontador) malloc(sizeof(struct NodoLista));
    p->Item = Item;
    p->Proximo = NULL;

    if (vazia(lista)) {
        lista.Primeiro->Proximo = p;
        lista.Ultimo->Proximo = p;
    }
    lista.Ultimo->Proximo = p;
    lista.Ultimo = p;
}

bool vazia(TLista lista) {
    return (lista.Primeiro->Proximo == NULL) ? true : false;
}

void Imprime(TLista lista) {
    Apontador p = lista.Primeiro->Proximo;
    if (p) {
        while (p != NULL) {
            cout << p->Item.Chave << " ";
            p = p->Proximo;
        }
    } else {
        cout << "Lista vazia" << endl;
    }
    cout << endl;

}

void InserePosicao(TLista lista, int pos, TInfo item) {
    int tmL = 0;
    Apontador contador = lista.Primeiro; // para ver quantos nos tem
    while (contador->Proximo != NULL) {
        contador = contador->Proximo;
        tmL++;
    }
    if (pos < tmL) {
        if (pos == 0) {
            InsereInicio(lista, item);
        } else {
            int i = 1;
            Apontador aux = lista.Primeiro->Proximo;
            Apontador p = lista.Primeiro;

            while (aux->Proximo != NULL || i < pos) {
                p = aux;
                aux = aux->Proximo;
                i++;
            }
            if (tmL == pos) {
                InsereFinal(lista, item);
            } else {
                Apontador novo = (Apontador) malloc(sizeof(struct NodoLista));
                novo->Item = item;
                novo->Proximo = aux;
                p->Proximo = novo;
            }
        }
    } else {
        cout << "Essa Posicao  e invalida" << endl;
    }
}

void RemoveFinal(TLista lista) {

    if (!vazia(lista)) {
        Apontador aux = lista.Primeiro->Proximo;
        Apontador p = lista.Primeiro;

        while (aux->Proximo != NULL) {
            p = aux;
            aux = aux->Proximo;
        }
        p->Proximo = NULL;
        lista.Ultimo = p;

        if (lista.Primeiro->Proximo == NULL) {
            lista.Ultimo = lista.Primeiro;
        }

        free(aux);
    }
}


