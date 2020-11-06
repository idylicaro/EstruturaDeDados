#include "cliente.h"
#include "transacao.h"

#include "criaMestre.h"
#include "leMestre.h"

#include "criaTransacoes.h"
#include "leTransacoes.h"

#include "balanceLine.h"

#include <locale.h>

int main(){
    // format UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");

    //**********************
    //Criando arquivo Mestre
    //**********************
    criaMestre();

    //**********************
    //Lendo o arquivo Mestre
    //**********************
    printf("\n===IMPRIMINDO O ARQUIVO MESTRE===");
    leMestre();

    //**********************
    //Criando arquivo Transações
    //**********************
    criaTransacoes();

    //**********************
    //Lendo o arquivo Transações
    //**********************
    printf("\n===IMPRIMINDO O ARQUIVO DE TRANSAÇÕES===");
    leTransacoes();


    FILE *fMestre, *fTransacoes, *fNovoMestre, *fErro; /* ponteiro para arquivos */

    fMestre = fopen("Mestre.dat","r");
    fTransacoes = fopen("Transacoes.dat","r");

    fNovoMestre = fopen("NovoMestre.dat","r w");
    fErro = fopen("Erro.dat","r w");

    if((fMestre == NULL) || (fTransacoes == NULL)) {
        printf("\n Erro ao abrir o arquivo");
        exit(1);
    }

    balanceLine(fMestre, fTransacoes, fNovoMestre, fErro);

    fclose(fMestre);
    fclose(fTransacoes);
    fclose(fNovoMestre);
    fclose(fErro);

    //TODO
    //IMPRIMIR O NOVO ARQUIVO MESTRE
    printf("\n===IMPRIMINDO O NOVO ARQUIVO MESTRE===");
    //rewind(fNovoMestre);
    leNovoMestre();
    //IMPRIMIR O ARQUIVO DE ERRO
    printf("\n===IMPRIMINDO O ARQUIVO DE ERRO===");
    leLogError();

    return 0;
}

