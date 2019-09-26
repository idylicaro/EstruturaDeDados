/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package idylicaro.filadeprioridade;

/**
 *
 * @author IdylIcaro
 * Basicamente e uma fila , que ela e ordenada 
 * 
 */
public class FilaPrioridade {
    private int maxSize;
    private int array[];
    private int nItems;
    
    public FilaPrioridade(int nMAX){
        this.maxSize = nMAX;
        this.array = new int[maxSize];
        this.nItems = 0;
    }
    public void insert(int elemento){
        int j;
        if(nItems == 0){
            array[nItems++] = elemento;
        }else{
            for(j = nItems-1;j>=0;j--){  //começa no final
            if(elemento > array[j]){   //se o novo item for maior
                array[j+1] = array[j]; //joga o item do array[j] vai subindo posições em direção ao final da fila  
            }else{
                break;
            }                            
        } //end for
            array[j+1] = elemento;   //insere-o
            nItems++;
        } //end else 
    }
    public int removeMin(){
        return array[--nItems]; // remove o item minimo
    }
    public int viewMin(){
        return array[nItems-1];
    }
    public boolean isEmpty(){
        return (nItems == 0);
    }
    public boolean isFull(){
        return (nItems == maxSize);
    }
    
    
}   //end class
