/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alucard
 */
public class VetorOrdenado {
    private int array[];
    private int nElementos;
    
    VetorOrdenado(int tamanho){
          this.array = new int[tamanho];
          this.nElementos = 0;
          for (int i=0;i<array.length;i++){
            array[i] = 0;
        }
    }
    public void ordenar(){ //buble sort
        int aux = 0;
        //boolean control;
        
        for (int i = 0; i < array.length; i++)
            {
                for (int j = 0; j < array.length; j++)
                {
                    if (array[i] < array[j])
                    {
                        aux = array[i];
                        array[i] = array[j];
                        array[j] = aux;
                    }
                }
            }
    }
    public void selectSort(){//ordem crescente
        int min=0,aux=0,i,j;
        for(i = 0;i<array.length-1;i++){
            
            for(j=i+1;j<array.length;j++)
                if(array[j]< array[min])
                    min = j;
                
                aux = array[i];
                array[i] = array[min];
                array[min] = aux;
        }
    }
    public void insertIn(int elemento){
        if(nElementos < array.length){
        this.array[nElementos] = elemento;
        nElementos++; 
        }else{System.out.println("Não pode inserir mais,apenas subistituir um elemento!");}
    }
    
    public void display(){
        for(int i = 0;i<array.length;i++){
            System.out.println(array[i]);
        }
    }
    //sobre o findBinary se ele retornar o indice == tamanho do array e pq ele n pode achar;
    public int findBinary(int searchKey){
        int intervaloBaixo = 0,intervaloAlto = array.length-1;
        int posAtual;
        
        while(true){
            posAtual = (intervaloBaixo+intervaloAlto)/2;
            if(array[posAtual] == searchKey){
                return posAtual;
            }else if(intervaloBaixo > intervaloAlto){
                return array.length; // n pode achar
            }else{
                if(array[posAtual] < searchKey){
                    intervaloBaixo = posAtual + 1; //está na metade superior
                }else{
                    intervaloAlto = posAtual - 1; //está na metade inferior
                }
            }
        }
        
    }
}

