package com.company;

public class TNodo {
    TNodo pai;

    public TNodo(TInfo item,TNodo pai) {
        this.pai = pai;
        this.item = new TInfo(item.chave,item.nome);
        this.esq = null;
        this.dir = null;
    }

    TInfo item;
    TNodo esq; //esquerda
    TNodo dir; //direita
}
