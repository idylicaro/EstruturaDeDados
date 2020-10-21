

#include "Collections.h"

 void listDisplay(List *list){
    Node *aux = list->first->next;
    if (aux){
        printf("-----LIST-----\n");
        while (aux != NULL){
            printf("| %i |",aux->item.id);
            aux = aux->next;
        }
    printf("\n");
    }else{
        printf("Empty List");
    }
}

void createList(List *list){
    Node *aux = malloc(sizeof(Node));
    list->first = aux;
    list->last = list->first;
    list->first->next = NULL;
}

void insertInFirst(List *list, Item item){ // insert in first position
    Node *aux = malloc(sizeof(Node));
    aux->item = item;
                                    /*list->first (unusable node)*/
    aux->next = list->first->next;
    list->first->next = aux;

    if(aux->next == NULL)
    {
        list->last = aux;
    }
}