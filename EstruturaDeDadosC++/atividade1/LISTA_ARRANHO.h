// ---- LISTA IMPREMENTADA POR MEIO DE ARRAJO --- -
const int Tmax = 10;
typedef int Apontador ;
typedef struct
{
    int Chave ;
    /* outros componentes */
} TInfo ;
typedef struct
{
    TInfo Item [ Tmax ];
    Apontador Primeiro ;
    Apontador Ultimo ;
} TLista ;
// ---------------------------------------------
void Cria ( TLista & Lista )
{
    Lista . Primeiro = 0;
    Lista . Ultimo = Lista . Primeiro ;
}
// ---------------------------------------------
bool Vazia ( TLista Lista )
{
    return Lista . Primeiro == Lista . Ultimo ? true : false ;
}
// ---------------------------------------------
bool Cheia ( TLista Lista )
{
    return Lista . Ultimo >= Tmax ? true : false ;
}
// ---------------------------------------------
void InsereInicio ( TLista & Lista, TInfo Item )
{
    if ( Cheia ( Lista ))
        cout << " Erro : A lista est´a cheia " << endl ;
    else
    {
        for (int aux = Lista.Ultimo ; aux >= Lista.Primeiro +1 ;aux --)
            Lista.Item [ aux ] = Lista.Item [ aux -1];
        Lista.Item [ Lista.Primeiro ] = Item ;
        Lista.Ultimo ++;
    }
}
// ---------------------------------------------
void Imprime ( TLista Lista )
{
    cout << " Itens na LISTA : " << endl ;
    if ( Vazia ( Lista ))
        cout << " Lista est´a vazia ." << endl ;
    else
    {
        for (int aux = Lista . Primeiro ; aux < Lista . Ultimo ; aux ++)
            cout << Lista . Item [ aux ]. Chave << " " ;
        cout << endl ;
    }
    cout << "\n PRIMEIRO = " << Lista . Primeiro << endl ;
    cout << " ULTIMO = " << Lista . Ultimo << endl ;
    cout << " TMAX = " << Tmax << endl ;
}
// ---------------------------------------------
void InserePosicao(TLista &Lista ,Apontador p,TInfo Item){
    //pelo motivo dde inserir n e alterar , vai ter que verificar se tem espaço pra inserir
    if(Cheia(Lista)){
        cout << "Impossivel no momento inserir algo nesta lista " <<endl;
    }else{
    for(int i = Lista.Ultimo; i>= p+1;i--){
        Lista.Item[i] = Lista.Item[i-1];
    }
    Lista.Item[p] = Item;
    Lista.Ultimo++;

}
}
void InsereFinal(TLista &Lista,TInfo Item){
    if(Cheia(Lista)){
         cout << "Impossivel no momento inserir algo nesta lista " <<endl;
    }else{
        Lista.Item[Lista.Ultimo] = Item;
        Lista.Ultimo++;
    }

}
void RemoveInicio(TLista & Lista){
    if(Lista.Ultimo > 0){
    for(int i = Lista.Primeiro ;i<=Lista.Ultimo;i++){
        Lista.Item[i] = Lista.Item[i+1];
    }
    Lista.Ultimo--;
}
}

void RemoveFinal(TLista & Lista){
    if(Lista.Ultimo > 0){
        Lista.Ultimo--;
    }
}
/*

RemoveInicio ( Lista ) ;
RemoveFinal ( Lista );
Pesquisa_Remove ( Lista , Item );
*/
