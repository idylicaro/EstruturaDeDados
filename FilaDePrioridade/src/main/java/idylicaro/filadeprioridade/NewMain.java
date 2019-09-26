/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package idylicaro.filadeprioridade;

/**
 * @author Idyl Icaro
 * @date   26/09/2019
 */
public class NewMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        FilaPrioridade fila = new FilaPrioridade(5);
        fila.insert(50);
        fila.insert(3);
        fila.insert(1);
        fila.removeMin();
        System.out.println(fila.viewMin());
    }

}
