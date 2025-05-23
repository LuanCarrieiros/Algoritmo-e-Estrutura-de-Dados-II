#ifndef LIST_H
#define LIST_H

#include <stddef.h> // Para size_t
#include "../include/common.h" // Para String

// ------------------------------ STRUCT LIST ----------------------------- //
typedef struct List
{
    String *element;
    int size;
} List;

// ---------------------------- MÉTODOS DA LISTA --------------------------- //
void init_list(size_t size, List* list);
void add_listEnd(String element, List* list, size_t size);
void display_List(List* list);
void free_List (List* list);

#endif