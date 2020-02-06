package com.company;

public class Main {

    public static void main(String[] args) {
	TArvore t1 = new TArvore();
	TInfo item = new TInfo();
    item.chave = 44;
    item.nome = "Higinio";
    t1.insere(item);
        item.chave = 20;
        item.nome = "icaro";
        t1.insere(item);
            item.chave = 19;
            item.nome = "Igor";
            t1.insere(item);
    }
}
