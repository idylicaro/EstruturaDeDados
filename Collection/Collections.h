#ifndef COLLECTION_COLLECTIONS_H
#define COLLECTION_COLLECTIONS_H

#include <stdio.h>
#include<stdlib.h>
typedef struct Item{ //values
    int id;
}Item;

typedef struct NodeList{
    Item item;
    struct NodeList *next;
}Node;

typedef struct List {
    Node *first;
    Node *last;
}List;

/*
 * this algorithm uses an unusable node (that is, first), as it will avoid several checks.
 * */

void listDisplay(List *list);
void createList(List *list);
void insertInFirst(List *list, Item item);

#endif //COLLECTION_COLLECTIONS_H
