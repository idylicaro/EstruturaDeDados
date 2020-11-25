#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "cliente.h"
#include "lista_clientes.h"
#include "nomes.h"
#include "intercalacao.h"

#define NOME_ARQUIVO_SAIDA "saida.dat"

Nomes *nomes = NULL;

#define TRUE 1
#define FALSE 0
void UnitTest(int expected, int actual, const char* testName){
    if(expected == actual){
        printf("\n>> %s -> PASSED \n", testName);
    }else{
        printf("\n>> %s -> FAILED [expected: %d | actual: %d]\n",testName,expected,actual);
    }
}

int inverte_nomes_test(){
    nomes = cria_nomes(cria_str("p1.dat"), cria_nomes(cria_str("p2.dat"), NULL));
    char *first = nomes->nome;
    inverte_nomes(nomes);
    while (nomes->prox != NULL)
        nomes = nomes->prox;
    return first == nomes->nome ? TRUE:FALSE;
}
int count_partitions_in_File_Array(){
    int f = 4,result;
    nomes = cria_nomes(cria_str("p1.dat"), cria_nomes(cria_str("p2.dat"), NULL));
    FILE **p = malloc(3 * sizeof(FILE));
    for(int i =0; i < (f-1);i++){
        if(nomes == NULL){
            break;
        }
        p[i] = fopen(nomes->nome, "rw");
        nomes = nomes->prox;
    }
    result = (countPartitions(p,f) == 2)? TRUE:FALSE;
    for(int i =0; i < (f-1);i++){
        fclose(p[i]);
    }
    return result;
}
void runUnitTests(){
    printf("========= UNIT TESTS ========\n");
    UnitTest(TRUE,inverte_nomes_test(),"Ensures the behavior of the function that inverts the list of names");
    UnitTest(TRUE,count_partitions_in_File_Array(),"Ensure count_partitions returns correct value");
    printf("\n================================================================================================\n\n");
}

void teste01(){
    printf("=============================================================================\n");
    printf("Teste 1 Intercalacao Basico. Arquivo p1.dat vazio deve criar saida.dat vazio.\n");
    printf("=============================================================================\n");
    ListaClientes *entrada, *saida;

    nomes = cria_nomes(cria_str("p1.dat"), NULL);

    entrada = cria_clientes(0);
    salva_clientes("p1.dat", entrada);
    libera_clientes(entrada);

    intercalacao_basico(NOME_ARQUIVO_SAIDA, 1, nomes);
    saida = le_clientes(NOME_ARQUIVO_SAIDA);
    libera_clientes(saida);

    FILE* out = fopen(NOME_ARQUIVO_SAIDA,"rb");
    TCliente* c;
    while ((c = le_cliente(out)) != NULL)
        imprime_cliente(c);
    free(c);
}


void teste02(){
    printf("============================================\n");
    printf("Teste 2 Intercalacao Basico. Duas particoes.\n");
    printf("============================================\n");
    ListaClientes *entrada, *saida;

    nomes = cria_nomes(cria_str("p1.dat"), cria_nomes(cria_str("p2.dat"), NULL));

    entrada = cria_clientes(2,
                            cliente(1, "Joao"),
                            cliente(5, "Maria"));
    salva_clientes("p1.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(4,
                            cliente(3, "Marcos"),
                            cliente(6, "Ana"),
                            cliente(7, "Bia"),
                            cliente(10, "Joaquim"));
    salva_clientes("p2.dat", entrada);
    libera_clientes(entrada);

    intercalacao_basico(NOME_ARQUIVO_SAIDA, 2, nomes);

    saida = le_clientes(NOME_ARQUIVO_SAIDA);
    libera_clientes(saida);

    FILE* out = fopen(NOME_ARQUIVO_SAIDA,"rb");
    TCliente* c;
    while ((c = le_cliente(out)) != NULL)
        imprime_cliente(c);
    free(c);
}

int teste03(){
    printf("============================================\n");
    printf("Teste 3 Intercalacao Basico. Onze particoes.\n");
    printf("============================================\n");
    ListaClientes *entrada, *saida;


    nomes = cria_nomes(cria_str("p1.dat"),
                       cria_nomes(cria_str("p2.dat"),
                                  cria_nomes(cria_str("p3.dat"),
                                             cria_nomes(cria_str("p4.dat"),
                                                        cria_nomes(cria_str("p5.dat"),
                                                                   cria_nomes(cria_str("p6.dat"),
                                                                              cria_nomes(cria_str("p7.dat"),
                                                                                         cria_nomes(cria_str("p8.dat"),
                                                                                                    cria_nomes(cria_str("p9.dat"),
                                                                                                               cria_nomes(cria_str("p10.dat"),
                                                                                                                          cria_nomes(cria_str("p11.dat"),
                                                                                                                                     NULL)))))))))));

    entrada = cria_clientes(5,
                            cliente(1, "Joao"),
                            cliente(3, "Matheus"),
                            cliente(5, "Maria"),
                            cliente(20, "Mariana"),
                            cliente(87, "Jonas"));

    salva_clientes("p1.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(6,
                            cliente(0, "Julia"),
                            cliente(2, "Marcos"),
                            cliente(7, "Bruna"),
                            cliente(8, "Vanessa"),
                            cliente(9, "Ana Maria"),
                            cliente(81, "Bianca"));

    salva_clientes("p2.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(7,
                            cliente(10, "Mirtes"),
                            cliente(22, "Lucila"),
                            cliente(23, "Clarissa"),
                            cliente(35, "Marceu"),
                            cliente(47, "Martim"),
                            cliente(48, "Tatiana"),
                            cliente(60, "Hugo"));

    salva_clientes("p3.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(2,
                            cliente(85, "Leonardo"),
                            cliente(90, "Catarina"));

    salva_clientes("p4.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(3,
                            cliente(11, "Leonel"),
                            cliente(15, "Alice"),
                            cliente(100, "Juca"));

    salva_clientes("p5.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(6,
                            cliente(19, "Juliana"),
                            cliente(25, "Maria"),
                            cliente(40, "Mafalda"),
                            cliente(41, "Epaminondas"),
                            cliente(46, "Celso"),
                            cliente(72, "Ana Clara"));

    salva_clientes("p6.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(3,
                            cliente(32, "Josias"),
                            cliente(73, "Jonas"),
                            cliente(102, "Alessandra"));

    salva_clientes("p7.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(3,
                            cliente(24, "Bruno"),
                            cliente(29, "Carlos"),
                            cliente(98, "Amanda"));

    salva_clientes("p8.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(1,
                            cliente(34, "Marcel")
    );

    salva_clientes("p9.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(4,
                            cliente(12, "Flavio"),
                            cliente(55, "Fernanda"),
                            cliente(59, "Priscila"),
                            cliente(63, "Jasmine")
    );

    salva_clientes("p10.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(2,
                            cliente(6, "Messias"),
                            cliente(52, "Daniel")
    );

    salva_clientes("p11.dat", entrada);
    libera_clientes(entrada);

    intercalacao_basico(NOME_ARQUIVO_SAIDA, 11, nomes);

    saida = le_clientes(NOME_ARQUIVO_SAIDA);
    libera_clientes(saida);

    FILE* out = fopen(NOME_ARQUIVO_SAIDA,"rb");
    TCliente* c;
    while ((c = le_cliente(out)) != NULL)
        imprime_cliente(c);
    free(c);
}

void teste04(){
    printf("============================================\n");
    printf("Teste 4 Intercalacao OTIMA. Duas particoes.\n");
    printf("============================================\n");
    ListaClientes *entrada, *saida;

    nomes = cria_nomes(cria_str("p1.dat"), cria_nomes(cria_str("p2.dat"), NULL));

    entrada = cria_clientes(2,
                            cliente(1, "Joao"),
                            cliente(5, "Maria"));
    salva_clientes("p1.dat", entrada);
    libera_clientes(entrada);

    entrada = cria_clientes(4,
                            cliente(3, "Marcos"),
                            cliente(6, "Ana"),
                            cliente(7, "Bia"),
                            cliente(10, "Joaquim"));
    salva_clientes("p2.dat", entrada);
    libera_clientes(entrada);

    intercalacao_otima(NOME_ARQUIVO_SAIDA, 2, nomes,4);

    saida = le_clientes(NOME_ARQUIVO_SAIDA);
    libera_clientes(saida);

    FILE* out = fopen(NOME_ARQUIVO_SAIDA,"rb");
    TCliente* c;
    while ((c = le_cliente(out)) != NULL)
        imprime_cliente(c);
    free(c);
}

int main(){
    //unit test run
    runUnitTests();

    //Teste 1 Intercalacao Basico. Arquivo p1.dat vazio deve criar saida.dat vazio.
    teste01();

    //Teste 2 Intercalacao Basico. Duas particoes.
    teste02();

    //Teste 3 Intercalacao Basico. Onze particoes.
    teste03();

    //Teste 4 Intercalacao OTIMA. Duas particoes.
    teste04();

    return 0;
}
