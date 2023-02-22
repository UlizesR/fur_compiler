#include "include/list.h"

list_T* init_list(size_t items_size)
{
    list_T* list = calloc(1, sizeof(struct LIST_STRUCT));
    list->size = 0;
    list->items_size = items_size;
    list->items = 0;

    return list;
} 

void list_push(list_T* list, void* item)
{
    list->size += 1;
    if (!list->items)
        list->items = calloc(1, list->items_size);
    else
        list->items = realloc(list->items, list->items_size * list->size);

    list->items[list->size - 1] = item;
}