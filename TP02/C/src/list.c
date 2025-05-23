#include "../include/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------------------------- MÉTODOS DA LISTA --------------------------- //
void init_list(size_t size, List* list)
{
    if ( size > 0 ) // verificando que o tamanho é maior que 0
    {
        list->element = (String *) malloc (size * sizeof(String)); // alocando as linhas
        if (list->element == NULL) {
            fprintf(stderr, "Erro de alocação de memória para list->element na init_list.\n");
            exit(EXIT_FAILURE);
        }
        for( size_t index = 0; index < size; index++)
        {
            list->element[index] = (String) malloc (500 * sizeof(char)); // alocando as colunas
            if (list->element[index] == NULL) {
                fprintf(stderr, "Erro de alocação de memória para list->element[%zu] na init_list.\n", index);
                exit(EXIT_FAILURE);
            }
        }
    }
    list->size = 0; // inicializando o tamanho
}

/* INSERIR UM ELEMENTO NO FINAL DA LISTA
@param size = tamanho
@param List = Lista
@param Elemento = Item a ser adicionado
*/
void add_listEnd( String element, List* list, size_t max_size_limit) // Renomeei o parâmetro 'size' para evitar confusão com 'list->size'
{
    // Comparando size_t com size_t
    if(list->size >= max_size_limit) // VALIDANDO SE O TAMANHO É MENOR QUE O FINAL, PARA INSERIR NO FINAL
    {
        printf("Erro ao inserir! Funcao add_listEnd\n");
        exit(1);
    }

    strcpy(list->element[list->size], element); // copiando a string para a linha do array de strings
    list->size++;
}

/* Funcao para exibir os itens da lista
@param List
*/
void display_List(List* list)
{
    size_t index;
    // Comparando size_t com size_t
    for(index = 0; index < list->size; index++)
    {
        printf("%s ", list->element[index]);
    }
}

/* Funcao para desalocar a lista
@param List
*/
void free_List (List* list)
{
    if (list && list->element) {
        for (size_t i = 0; i < list->size; i++) { // Use size_t para 'i'
            free(list->element[i]);
        }
        free(list->element);
        list->element = NULL;
    }
    if (list) {
        // Se a List* foi alocada dinamicamente, ela também deve ser liberada aqui
        // free(list); // Descomente se a List* em si foi alocada com malloc (ex: em Personagem)
    }
    if (list) { // Apenas para ter certeza de resetar o size se a struct em si não for liberada
        list->size = 0;
    }
}