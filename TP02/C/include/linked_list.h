#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../include/common.h"
#include "../include/personagem.h" // Porque as células armazenam Personagem

// ---------------------------------- STRUCT CELL PARA LIDAR COM LISTA ENCADEADA --------------------------- //

typedef struct Cell
{
    Personagem personagem;
    struct Cell *next;
} Cell;

typedef struct ListPersonagem
{
    Cell *first;
    Cell *last;
} ListPersonagem;

typedef struct CelulaDupla
{
    Personagem personagem;
    struct CelulaDupla *ant, *prox;
} CelulaDupla;

CelulaDupla *newCellDupla (Personagem p);
Cell *newCell (Personagem personagem);
Personagem getElementByID(String ID, ListPersonagem *List);
Cell* getElementByPos(int pos, ListPersonagem *List);
void start(Personagem personagem, ListPersonagem *List);
void addEnd(Personagem personagem, ListPersonagem *List);
int getSize(ListPersonagem *List);
void printCell_ID(ListPersonagem *List);
void freeCell(ListPersonagem *List);

#endif