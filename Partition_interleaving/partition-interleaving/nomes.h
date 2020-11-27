#ifndef PARTITION_INTERLEAVING_NOMES_H
#define PARTITION_INTERLEAVING_NOMES_H

#ifndef NOMES_H
#define NOMES_H

typedef struct Nomes {
    char *nome;
    struct Nomes *prox;
} Nomes;

// Imprime lista de nomes
void imprime_nomes(Nomes *nomes);

// Aloca copia de str
char *cria_str(char *str);

// Cria lista encadeada de nomes. Lembrar de chamar libera_nomes(nomes)
Nomes *cria_nomes(char *nome, Nomes *prox);

// Desaloca lista encadeada de nomes
void libera_nomes(Nomes *nomes);

// Retorna quantidade de nomes
int conta_nomes(Nomes *nomes);

// Inverte lista encadeada de nomes
Nomes* inverte_nomes(Nomes *nomes);

#endif

#endif //PARTITION_INTERLEAVING_NOMES_H
