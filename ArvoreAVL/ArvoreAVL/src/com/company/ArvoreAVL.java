package com.company;

public class ArvoreAVL {
    Elemento    elemento;
    ArvoreAVL   left;
    ArvoreAVL   rigth;
    private int bal;     // balanceamento

    public ArvoreAVL(Elemento ele){
        this.elemento = ele;
        this.left = null;
        this.rigth = null;
        this.bal = 0;
    }

    public ArvoreAVL() {
        this.elemento = null;
        this.left = null;
        this.rigth = null;
        this.bal = 0;
    }
    // Metodos de controle
    public  boolean isEmpty(){
        return (this.elemento == null);
    }

    public ArvoreAVL inserir(Elemento novo){
        if (isEmpty()){
            this.elemento = novo;
        }else {
            ArvoreAVL newArvoreAVL = new ArvoreAVL(novo);
            if(novo.getValor() < this.elemento.getValor()){
                if(this.left == null){
                    //se for um no folha recebe nova arvore
                    this.left = newArvoreAVL;
                }else {
                    this.left = this.left.inserir(novo);  // passei a responsabilidade para a sub-arvore esquerda
                }
            }else if(novo.getValor() > this.elemento.getValor()){
                if(this.rigth == null){
                    //se for um no folha recebe nova arvore
                    this.rigth = newArvoreAVL;
                }else{
                    this.rigth = this.rigth.inserir(novo);  // passei a responsabilidade para a sub-arvore direita
                }
            }
        }
        return this;
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
    /*
     *Importante perceber o estilo de remoção exige um cuidado, pois no java quem trabalha pra limpar a memoria é o garbage
     */
    public ArvoreAVL remover(Elemento elem){
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
                    ArvoreAVL aux = this.left;
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

    public int calcularAlture(){
        if(this.left == null && this.rigth == null){ // não tem filhos
            return 1;
        }else if(this.left !=null && this.rigth == null) {
            return 1 + this.left.calcularAlture();
        }else if(this.rigth !=null && this.left == null){
            return 1 + this.rigth.calcularAlture();
        }else{
            return 1 + Math.max(this.left.calcularAlture(), this.rigth.calcularAlture());
        }
    }

    public void calcularBalanceamento(){
        if((this.rigth == null) && (this.left == null)){
            this.bal = 0;
        }else if(this.left ==null && this.rigth != null){
            this.bal = this.rigth.calcularAlture() - 0;  //esquerda n tem altura
        }else if(this.left !=null && this.rigth == null){
            this.bal = 0 - this.left.calcularAlture();  //direita n tem altura
        }else{
            this.bal = this.rigth.calcularAlture() - this.left.calcularAlture();
        }
        if(this.rigth != null){
            this.rigth.calcularBalanceamento();
        }
        if(this.left != null){
            this.left.calcularBalanceamento();
        }
    }
    // Metodos de verificação de balanceamento e rotação
    public ArvoreAVL verificaBalanceamento(){
        if (this.bal >=2 ||this.bal<= -2){
            if(this.bal >= 2){
                if((this.bal * this.rigth.getBal()) > 0){ // verifica o sinais se vai ser ++ ou -+ ...
                    System.out.println("rotação Simples a direita");
                    return rotacaoSimplesDireita();
                }else{
                    System.out.println("rotação dupla a direita");
                    return rotacaoDuplaDireita();
                }
            }else{ //bal <= -2
                if((this.bal *this.left.getBal()) > 0){
                    System.out.println("rotação Simples a esquerda");
                    return rotacaoSimplesEsquerda();
                }else{
                    System.out.println("rotação dupla a esquerda");
                    return rotacaoDuplaEsquerda();
                }
            }
        }
        this.calcularBalanceamento();
        if(this.left != null){
            this.left = this.left.verificaBalanceamento();
        }
        if(this.rigth != null){
            this.rigth = this.rigth.verificaBalanceamento();
        }
        return this;
    }

    private ArvoreAVL rotacaoDuplaEsquerda() {
        ArvoreAVL arvore       = this;
        ArvoreAVL filhoLeft   = this.getLeft();
        ArvoreAVL filhoDoFilho = filhoLeft.getRigth();
        ArvoreAVL noInserido   = filhoDoFilho.getLeft();
        // parte 1 alinhar os nós

        filhoLeft.setRigth(noInserido);
        filhoDoFilho.setLeft(filhoLeft);
        this.setLeft(filhoDoFilho);

        //parte 2 torna o filho à esquerda a nova raiz
        ArvoreAVL novoFilhoEsquerda = this.getLeft();
        arvore.setLeft(null);
        novoFilhoEsquerda.setRigth(arvore);

        return novoFilhoEsquerda;
    }

    private ArvoreAVL rotacaoSimplesEsquerda() {
        ArvoreAVL filhoLeft;
        ArvoreAVL filhoDoFilho = null;

        filhoLeft = this.getLeft();
        if(this.left != null){
            if(this.left.getRigth() != null){
                filhoDoFilho = filhoLeft.getRigth();
            }
        }
        filhoLeft.setRigth(this);
        this.setLeft(filhoDoFilho);

        return filhoLeft;
    }

    private ArvoreAVL rotacaoDuplaDireita() {
        ArvoreAVL arvore       = this;
        ArvoreAVL filhoRigth   = this.getRigth();
        ArvoreAVL filhoDoFilho = filhoRigth.getLeft();
        ArvoreAVL noInserido   = filhoDoFilho.getRigth();
        // parte 1 alinhando os caras

        filhoRigth.setLeft(noInserido);
        filhoDoFilho.setRigth(filhoRigth);
        this.setRigth(filhoDoFilho);

        //parte 2 torna o filho à direita a nova raiz
        ArvoreAVL novoFilhoDireita = this.getRigth();
        arvore.setRigth(null);
        novoFilhoDireita.setLeft(arvore);

        return novoFilhoDireita;
    }

    private ArvoreAVL rotacaoSimplesDireita() {
        ArvoreAVL filhoRigth;
        ArvoreAVL filhoDoFilho = null;

        filhoRigth = this.getRigth();
        if(this.rigth != null){
            if(this.rigth.getLeft() != null){
                filhoDoFilho = filhoRigth.getLeft();
            }
        }
        filhoRigth.setLeft(this);
        this.setRigth(filhoDoFilho);

        return filhoRigth;
    }

    //Metodos de depuração
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
    public String printArvore(int level){
        String str = toString() + "\n";
        for(int i =0; i<level;i++){
            str += "\t";
        }
        if(this.left != null){
            str += "+-LEFT: "+this.left.printArvore(level + 1);
        }else{
            str += "+-LEFT: NULL";
        }
        str += "\n";
        for(int i =0; i<level;i++){
            str += "\t";
        }
        if(this.rigth!= null){
            str += "+-RIGTH: "+this.rigth.printArvore(level + 1);
        }else{
            str += "+-RIGTH: NULL";
        }
        str += "\n";
        return str;
    }
    public String toString(){
        return "["+this.elemento.getValor()+"] ("+this.bal+")";
    }

    //Sets and gets
    public Elemento getElemento() {
        return elemento;
    }

    public void setElemento(Elemento elemento) {
        this.elemento = elemento;
    }

    public ArvoreAVL getLeft() {
        return left;
    }

    public void setLeft(ArvoreAVL left) {
        this.left = left;
    }

    public ArvoreAVL getRigth() {
        return rigth;
    }

    public void setRigth(ArvoreAVL rigth) {
        this.rigth = rigth;
    }

    public int getBal() {
        return bal;
    }

    public void setBal(int bal) {
        this.bal = bal;
    }
}
