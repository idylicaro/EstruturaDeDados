/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package idylicaro.queue_fila;

/**
 *
 * @author Allucard.SE
 */
public class FilaClass {
    private int maxSize;
    private int array[];
    private int frente;
    private int fimFila;
    private int nItems;
    
    public FilaClass(int nMax){
        this.maxSize = nMax;
        array = new int[maxSize];
        this.frente = 0;
        this.fimFila = -1;
        this.nItems = 0;
    }
    
    public void insert(int elemento){
        if(fimFila == maxSize-1){
            fimFila = -1;
        }
        array[++fimFila] = elemento;
        nItems++;
    }
    public int remove(){
        int auxTemp = array[frente++];
        if(frente == maxSize)
            frente = 0;
        nItems--;
        return auxTemp;
    }
   
    public int viewFront(){
        return array[frente];
    }
    public boolean isEmpty(){
        return (nItems == 0);
    }
    public boolean isFull(){
        return (nItems == maxSize);
    }
    public int size(){
        return nItems;
    }

}
