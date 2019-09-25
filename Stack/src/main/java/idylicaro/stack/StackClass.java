/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package idylicaro.stack;

/**
 *
 * @author Allucard.SE
 */
public class StackClass {
    private final int maxSize;
    private int array[];
    private int topStack; // topo da pilha
    
    public StackClass(int size){
        this.maxSize = size;
        array = new int[maxSize];
        topStack = -1;  //sem items
    }
    
    public void insertStack(int elemento){ //elemento para por na pilha
        if(topStack < maxSize-1){
        this.array[++topStack] = elemento;
        }else{
            System.out.println("Pilha cheia demais ,retire algum item :)");
        }
    }
    
    public int remove(){  //ele vai apenas voltar uma posição na topStack ,
                            // ai quando inserir vai sobrescrever o valor; 
        if(topStack != -1){
            return this.array[topStack--];   //vai mostrar o valor retirado
        }else{
            System.out.println("Nao tem oque remover :(");
        }
        return 0;
    }
    
    public int viewTopStack(){
        return this.array[topStack];  // retorna o valor do topo da pilha
    }
    
    public boolean isFull(){
        return (topStack == maxSize-1);
    }
    public boolean isEmpty(){
        return (topStack == -1);
    }
}
