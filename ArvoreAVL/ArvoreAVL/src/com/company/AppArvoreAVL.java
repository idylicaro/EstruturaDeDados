package com.company;

import java.util.Scanner;

public class AppArvoreAVL {

    public static void main(String[] args) {
        Scanner teclado =  new Scanner(System.in);

        ArvoreAVL arvore = new ArvoreAVL(new Elemento(teclado.nextInt()));
        arvore.calcularBalanceamento();
        arvore.verificaBalanceamento();
        System.out.println(arvore.printArvore(0));

        while (true){
            arvore = arvore.inserir(new Elemento(teclado.nextInt()));
            arvore.calcularBalanceamento();
            arvore = arvore.verificaBalanceamento();
            arvore.calcularBalanceamento();
            System.out.println(arvore.printArvore(0));
        }
    }
    
}
