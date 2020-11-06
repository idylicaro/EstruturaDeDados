#ifndef BALANCE_LINE_BALANCELINE_H
#define BALANCE_LINE_BALANCELINE_H

#include <stdio.h> /* define FILE */
#include <stdlib.h>
#include <string.h> /*strcmp*/
typedef int bool;
#define true 1
#define false 0

void balanceLine(FILE *fMestre, FILE *fTransacao, FILE *fNovoMestre, FILE *fErro){
    /* TODO:
     *  1- enquanto tiver transações fazer as comparaçoes e alterações. [V]
     *  2- Se chave do topo da pilha do arquivo mestre é menor do que a chave do topo do arquivo de transações:
     *       * incluir registro do arquivo mestre no arquivo de saída. [V]
     *       * avançar o indicador de topo da pilha do arquivo mestre para o próximo registro.[V]
     *  3- Se a chave do topo do arquivo de transações é menor que a chave do topo do arquivo mestre:
     *       * Se operação for inserção, incluir registro do arquivo de transações no arquivo de saída.[V]
     *       * Se operação for exclusão ou modificação, incluir registro do arquivo de transações no
     *           arquivo de erros.[V]
     *       * avançar o indicador de topo da pilha do arquivo de transações para o próximo registro.[V]
     *  4- Se a chave dos dois topos coincidirem:
     *      * o registro do arquivo principal sofre as atualizações (modificação ou exclusão )
     *          indicadas no registro do arquivo de transações e o resultado vai para o arquivo de saída.
     *      * se a operação for de inserção, atualizar arquivo de erros.
     *      * avançar os indicadores de topo de pilha de ambas as pilhas.
     * */

    bool needTChange = false, needMChange = true; //flags
    TTransacao *t;
    TCliente *c; // client Master file
    while ((t = leTransacao(fTransacao)) != NULL){
        needTChange = false;
        while (needTChange != true){
            if (needMChange)
                c = leCliente(fMestre);
            needMChange = false;

            if (c->codCliente < t->codCliente){
                salvaCliente(c,fNovoMestre);
                // activate flag
                needMChange = true;
            }else if(c->codCliente > t->codCliente){
                if(t->tipoTransacao == 'E' || t->tipoTransacao == 'M'){// E == excluir || M == Modificar
                    salvaTransacao(t, fErro);  //salva no log de error
                }else if (t->tipoTransacao == 'I'){
                    TCliente *cAux = Cliente(t->codCliente, t->valor01, t->valor02);
                    salvaCliente(cAux, fNovoMestre);
                    free(cAux);
                }
                // activate flag
                needTChange = true;
                continue;

            } else if(c->codCliente == t->codCliente){
                if(t->tipoTransacao == 'M'){
                    if ( strcmp(t->valor01,"Nome") != 0 ) { // t->valor01 != "nome"
                        strcpy(c->dataNascimento, t->valor02);
                    } else {
                        strcpy(c->nome, t->valor02);
                    }
                    salvaCliente(c, fNovoMestre);
                }else if (t->tipoTransacao == 'I'){
                    salvaTransacao(t, fErro);
                }
                // activate flag
                needTChange = true;
                needMChange = true;
                continue;
            }
        }// fim while
    }// fim while

    //apos as transições acabar ele meio que transfere o resto do arquivo.
    while ((c = leCliente(fMestre)) != NULL)
        salvaCliente(c,fNovoMestre);
    
}
#endif //BALANCE_LINE_BALANCELINE_H
