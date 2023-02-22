#ifndef FUR_LIST_H
#define FUR_LIST_H

#include <stdlib.h>

typedef struct LIST_STRUCT
{
    void **items;
    size_t size;
    size_t items_size;

} list_T;

list_T *init_list(size_t items_size);

void list_push(list_T *list, void *item);

#endif