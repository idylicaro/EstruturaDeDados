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
public class TesteMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        FilaClass fila = new FilaClass(5);
        fila.insert(1);
        fila.insert(2);
        fila.insert(3);
        fila.insert(4);
        fila.insert(5);
        fila.remove();
        
        System.out.println(fila.viewFront());
    }
    
}
