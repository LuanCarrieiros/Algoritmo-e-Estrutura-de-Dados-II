#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H

#include "../include/common.h"    // Para Log, StringArray
#include "../include/personagem.h" // Para Personagem

// ================================================ SWAP ================================================ //
void swap(Personagem personagens[], int i, int j);
void swap_static(StringArray array, int i, int j); // Renomeei para evitar conflito com 'personagens'

// Funções de desempate
int desempateEye (Personagem Pivo, Personagem aux);
int desempateHouse (Personagem Pivo, Personagem aux, Log* log);
int desempateHairColour (Personagem Pivo, Personagem aux, Log* log);

// ======================================= BUBBLESORT ======================================= //
void bubblesort(Personagem personagens[], int size, Log *log);

// ======================================= QUICKSORT ======================================= //
void quicksort(Personagem personagens[], int left, int right, Log *log);

// ======================================= SELECTION SORT ======================================= //
void selectionsort(Personagem personagens[], int size, int currentIndex, Log* log);

// ======================================= INSERCAO POR COR ======================================= //
void insercaoPorCor(Personagem personagens[], int n, int cor, int h, Log* Log);

// ========================================= SHELLSORT ========================================= //
void shellsort(Personagem personagens[], int n, Log* Log);

// ======================================= HEAPSORT ======================================= //
void buildHeap(Personagem personagens[], int root, int n, Log* log);
void heapsort(Personagem personagens[], int n, Log *log);

#endif