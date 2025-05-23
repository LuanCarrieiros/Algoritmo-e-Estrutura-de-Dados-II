#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include "../include/common.h"      // Para StringArray, Log
#include "../include/linked_list.h" // Para ListPersonagem

bool binarySearch (StringArray armazenamentoIDs, String searched, int left, int right, ListPersonagem *List, Log *log);

#endif