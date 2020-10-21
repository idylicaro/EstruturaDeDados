#include <stdio.h>
#include "Collections.h"

int main() {
    List list;
    Item item;
    item.id = 1;
    createList(&list);
    insertInFirst(&list, item);
    insertInFirst(&list, item);
    listDisplay(&list);
    return 0;
}
