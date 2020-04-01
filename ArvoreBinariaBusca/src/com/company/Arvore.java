package com.company;

public class Arvore {
    Elemento elemento;
    Arvore left;
    Arvore rigth;

    public Arvore(Elemento ele){
        this.elemento = ele;
        this.left = null;
        this.rigth = null;
    }

    public Arvore() {
        this.elemento = null;
        this.left = null;
        this.rigth = null;
    }
    // Metodos de controle
    public  boolean isEmpty(){
        return (this.elemento == null);
    }
    public void inserir(Elemento novo){
        if (isEmpty()){
            this.elemento = novo;
        }else {
            Arvore newArvore = new Arvore(novo);
            if(novo.getValor() < this.elemento.getValor()){
                if(this.left == null){
                    //se for um no folha recebe nova arvore
                    this.left = newArvore;
                }else {
                    this.left.inserir(novo);  // passei a responsabilidade para a sub-arvore esquerda
                }
            }else if(novo.getValor() > this.elemento.getValor()){
                if(this.rigth == null){
                    //se for um no folha recebe nova arvore
                    this.rigth = newArvore;
                }else{
                    this.rigth.inserir(novo);  // passei a responsabilidade para a sub-arvore direita
                }
            }
        }
    }
    public boolean busca(int valor){
        if (isEmpty()){
            return false;
        }
        if (this.elemento.getValor() == valor){
            return true;
        }else {
            if(valor < this.elemento.getValor()){ // Esquerda
                if (this.left == null){
                    return false;
                }else {
                    return this.left.busca(valor); //repassei a responsabilidade para a sub-arvore esquerda
                }
            }else if(valor > this.elemento.getValor()){ // Direita
                if (this.rigth == null){
                    return false;
                }else {
                    return this.rigth.busca(valor); //repassei a responsabilidade para a sub-arvore direita
                }
            }
        }
        return false;
    }
    public void displayPreOrdem(){
        if (!isEmpty()){
            System.out.print(this.elemento.getValor()+ " ");
            if(this.left != null){
                this.left.displayPreOrdem();
            }
            if (this.rigth != null){
                this.rigth.displayPreOrdem();
            }
        }
    }
    public void displayInOrdem(){
        if(!isEmpty()){
            if (this.left != null){
                this.left.displayInOrdem();
            }
            System.out.print(this.elemento.getValor()+" ");
            if(this.rigth != null){
                this.rigth.displayInOrdem();
            }
        }
    }
    public void  displayPosOrdem(){
        if(!isEmpty()){
            if(this.rigth != null){
                this.rigth.displayPosOrdem();
            }
            if (this.left != null){
                this.left.displayPosOrdem();
            }
            System.out.print(this.elemento.getValor()+" ");
        }
    }
    /*
    *Importante perceber o estilo de remoção exige um cuidado, pois no java quem trabalha pra limpar a memoria é o garbage
     */
    public Arvore remover(Elemento elem){
        if(this.elemento.getValor() == elem.getValor()){
            //o elemento está em um nó folha
            if(this.left == null && this.rigth == null){
                return null;
            }else {
                if(this.left != null && this.rigth == null){
                    //quando se tem filhos a esquerda e não tem filhos a direita
                    return this.left;
                }else if(this.rigth != null && this.left == null){
                    //quando se tem filhos a direita e não tem filhos a esquerda
                    return this.rigth;
                }
                else{
                    // Tem filho dos dois lados(left and rigth)
                    // adotando a estrategia do maior dentre os menores (remoção substituindo a esquerda)
                    // e
                    Arvore aux = this.left;
                    while (aux.rigth != null){
                        aux = aux.rigth;
                    }
                    // trocando os elementos da arvore
                    this.elemento = aux.getElemento(); //  o elemento atual , recebe o maior dentre os menores
                    aux.setElemento(elem);             //  coloco no nó folha o elemento (elem) que eu queria remover
                    this.left = left.remover(elem);
                }
            }
        }else if(elem.getValor() < this.elemento.getValor()){
            // delegar a responsabilidade para a sub-arvore esquerda
            this.left = this.left.remover(elem);
        }else if(elem.getValor() > this.elemento.getValor()){
            // delegar a responsabilidade para a sub-arvore direita
            this.rigth = this.rigth.remover(elem);
        }
        //retorna a propria arvore sem modificar nada
        return this;
    }

    //Sets and gets
    public Elemento getElemento() {
        return elemento;
    }

    public void setElemento(Elemento elemento) {
        this.elemento = elemento;
    }

    public Arvore getLeft() {
        return left;
    }

    public void setLeft(Arvore left) {
        this.left = left;
    }

    public Arvore getRigth() {
        return rigth;
    }

    public void setRigth(Arvore rigth) {
        this.rigth = rigth;
    }
}
