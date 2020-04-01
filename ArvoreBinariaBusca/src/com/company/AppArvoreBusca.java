package com.company;

public class AppArvoreBusca {

    public static void main(String[] args) {
        Elemento item = new Elemento();
        Arvore raiz = new Arvore(new Elemento(8));
        raiz.inserir(new Elemento(5));
        raiz.inserir(new Elemento(1));
        raiz.inserir(new Elemento(7));
        raiz.inserir(new Elemento(15));
        raiz.inserir(new Elemento(12));
        raiz.inserir(new Elemento(18));

        System.out.println("PRE ORDEM");
        raiz.displayPreOrdem();
        System.out.println("");
        System.out.println("IN ORDEM");
        raiz.displayInOrdem();
        System.out.println("");
        System.out.println("POS ORDEM");
        raiz.displayPosOrdem();
        System.out.println("");

        item.setValor(18);
        raiz = raiz.remover(item);

        System.out.println("Nova arvore");
        raiz.displayInOrdem();
    }
}
