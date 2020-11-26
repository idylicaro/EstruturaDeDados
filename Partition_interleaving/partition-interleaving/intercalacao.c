#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <string.h>
#include "intercalacao.h"
#include "nomes.h"
#include "cliente.h"
#include <limits.h>

typedef struct vetor{
    TCliente *cli;
    FILE *f;
}TVet;

/*
 * Definicao de tipo para no de arvore de vencedores
 */
typedef struct No {
    TCliente *vencedor;
    struct No *endVencedor;
    FILE *f;
    struct No *pai;
    struct No *dir;
    struct No *esq;
} TNo;

void intercalacao_basico(char *nome_arquivo_saida, int num_p, Nomes *nome_particoes) {

    int fim = 0; //variavel que controla fim do procedimento
    FILE *out; //declara ponteiro para arquivo

    //abre arquivo de saida para escrita
    if ((out = fopen(nome_arquivo_saida, "wb")) == NULL) {
        printf("Erro ao abrir arquivo de sa?da\n");
    } else {
        //cria vetor de parti??es
        TVet v[num_p];

        //abre arquivos das particoes, colocando variavel de arquivo no campo f do vetor
        //e primeiro cliente do arquivo no campo cli do vetor
        for (int i=0; i < num_p; i++) {
            v[i].f = fopen(nome_particoes->nome, "rb");
            if (v[i].f != NULL) {
                TCliente *c = le_cliente(v[i].f);
                if (c == NULL) {
                    //arquivo estava vazio
                    //coloca HIGH VALUE nessa posi??o do vetor
                    v[i].cli = cliente(INT_MAX, "");
                }
                else {
                    //conseguiu ler cliente, coloca na posi??o atual do vetor
                    v[i].cli = c;
                }
            }
            else {
                fim = 1;
            }
            nome_particoes = nome_particoes->prox;
        }

        while (!(fim)) { //conseguiu abrir todos os arquivos
            int menor = INT_MAX;
            int pos_menor;
            //encontra o cliente com menor chave no vetor
            for(int i = 0; i < num_p; i++){
                if(v[i].cli->cod_cliente < menor){
                    menor = v[i].cli->cod_cliente;
                    pos_menor = i;
                }
            }
            if (menor == INT_MAX) {
                fim = 1; //terminou processamento
            }
            else {
                //salva cliente no arquivo de sa?da
                salva_cliente(v[pos_menor].cli, out);
                //atualiza posi??o pos_menor do vetor com pr?ximo cliente do arquivo
                TCliente *c = le_cliente(v[pos_menor].f);
                if (c == NULL) {
                    //arquivo estava vazio
                    //coloca HIGH VALUE nessa posi??o do vetor
                    v[pos_menor].cli = cliente(INT_MAX, "");
                }
                else {
                    v[pos_menor].cli = c;
                }

            }
        }

        //fecha arquivos das parti??es de entrada
        for(int i = 0; i < num_p; i++){
            fclose(v[i].f);
        }
        //fecha arquivo de sa?da
        fclose(out);
    }
}

void intercalacao_arv_vencedores(char *nome_arquivo_saida, int num_p, Nomes *nome_particoes){
    //TODO: Implementar essa função
}



void intercalacao_otima(char *nome_arquivo_saida, int num_p, Nomes *nome_particoes, int f) {
    FILE *out;
    FILE **p = malloc(3 * sizeof(FILE));  // need ** because in array element need to be FILE pointer / p is vector of partitions
    int idLastPartition = NULL;
    char *lastPartitionName;

    if ((out = fopen(nome_arquivo_saida, "wb")) == NULL) {
        printf("Erro ao abrir arquivo de sa?da\n");
    }else{
        do{
            Nomes nomesInUse = *nome_particoes;
            int count_partitions_in_use = 0;
            for (int i = 0; i < (f - 1); i++) {
                p[i] = fopen(nome_particoes->nome, "rw");
                count_partitions_in_use++;
                if (nome_particoes->prox == NULL) {
                    lastPartitionName = nome_particoes->nome;
                    break;
                }
                *nome_particoes = *nome_particoes->prox;
            }

            char auxNomes_name[20];

            if((num_p - count_partitions_in_use) == 0){
                strcpy(auxNomes_name , nome_arquivo_saida);
            }else{ // ai cria partição px+1.dat
                idLastPartition = catchPartitionId(lastPartitionName);
                auxNomes_name[0] = 'p';
                char auxId[10] = "";
                itoa(idLastPartition + 1,auxId,10);
                strcat(auxNomes_name, auxId) ;
                strcat(auxNomes_name, ".dat");
            }

            inverte_nomes(nome_particoes);
            nome_particoes = cria_nomes(auxNomes_name,nome_particoes);
            inverte_nomes(nome_particoes);

            intercalacao_basico(auxNomes_name,count_partitions_in_use,&nomesInUse);
            nome_arquivo_saida = auxNomes_name;
            num_p -= count_partitions_in_use;
            // Todo: usar a intercalacao_basico() com esse ultimo nome da partição

        }while (num_p > 1);
    }// Fim do primeiro else

}

int countPartitions(FILE **p, int sizeP){
    int count = 0;
    TCliente *aux;
    for (int i = 0; i < sizeP; ++i) {
        if((aux = le_cliente(p[i])) != NULL){
            count++;
        }
        rewind(p[i]);
    }
    return count;
}
int catchPartitionId(const char *name){
    char aux[20] = "";
    int i =1, j =0;
    while (name[i] != '.'){
        aux[j] = name[i];
        i++;j++;
    }
    return strtol(aux, NULL, 10);
}