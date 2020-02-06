package com.company;

public class TArvore {
    TNodo T;

    public TArvore() {
        T = null;
    }
    public void insere(TInfo item){
        T = insere(T,item,null);
    }
    public TNodo insere(TNodo T,TInfo item,TNodo pai){
        if(T == null){
            //se for o primeiro nodo , ele vai por o pai sendo que o pai sempre e passado como null
            T = new TNodo(item, pai);
        }else{
            pai = T;
            if(item.chave < T.item.chave){
                T.esq = insere(T.esq,item,pai);
            }else if(item.chave > T.item.chave){
                T.dir = insere(T.dir,item,pai);
            }
        }
        return T;
    }
}
