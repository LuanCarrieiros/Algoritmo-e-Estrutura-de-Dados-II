#include "../include/linked_list.h"
#include "../include/common.h"
#include "../include/personagem.h" // Para usar Personagem e print
#include "../include/utils.h"     // Para equals

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CelulaDupla *newCellDupla (Personagem p)
{
    CelulaDupla *tmp = (CelulaDupla*) malloc (sizeof(CelulaDupla));
    if (tmp == NULL) {
        fprintf(stderr, "Erro de alocação de memória para newCellDupla.\n");
        exit(EXIT_FAILURE);
    }
    tmp->personagem = p;
    tmp->ant = NULL;
    tmp->prox = NULL;
    return tmp;
}

// criando uma nova celula do tipo personagem
Cell *newCell (Personagem personagem)
{
    Cell *newcell = (Cell *) malloc (sizeof(Cell)); // alocando a memória
    if (newcell == NULL) {
        fprintf(stderr, "Erro de alocação de memória para newCell.\n");
        exit(EXIT_FAILURE);
    }
    newcell->personagem = personagem;
    newcell->next = NULL;
    return ( newcell );
}

// Funcao para procurar um elemento na lista usando o ID
Personagem getElementByID(String ID, ListPersonagem *List)
{
    Cell *aux;
    // Percorre a lista a partir do segundo elemento (se o primeiro for sentinela)
    // Ou aux = List->first; se o first for o primeiro elemento real
    for( aux = List->first->next; aux != NULL; aux = aux->next)
    {
        if(strcmp(aux->personagem.id, ID) == 0)
        {
            return ( aux->personagem );
        }
    }

    // Se o elemento não for encontrado, retorne uma Personagem vazia ou com um ID conhecido como inválido
    Personagem personagem_vazia;
    // É uma boa prática inicializar a struct para evitar valores lixo
    memset(&personagem_vazia, 0, sizeof(Personagem)); // Zera todos os bytes
    strcpy(personagem_vazia.id, "NOT_FOUND"); // Marca como não encontrada
    return ( personagem_vazia );
}

Cell* getElementByPos(int pos, ListPersonagem *List) {

    Cell* aux = List->first; // Começa do sentinela
    for (int i = 0; i < pos; i++) {
        if (aux != NULL) { // Verifica se aux não é NULL antes de avançar
            aux = aux->next;
        } else {
            // Posição inválida, retorna NULL ou lida com erro
            return NULL;
        }
    }
    return aux;
}

void start(Personagem personagem, ListPersonagem *List)
{
    List->first = newCell(personagem); // O primeiro nó é geralmente um sentinela ou o primeiro elemento
    List->last = List->first;
}

void addEnd(Personagem personagem, ListPersonagem *List)
{
    List->last->next = newCell(personagem);
    List->last = List->last->next;
}

int getSize(ListPersonagem *List)
{
    int size = 0;
    Cell *aux;

    // Se o primeiro nó é um sentinela e os dados começam em first->next
    for(aux = List->first->next; aux != NULL; aux = aux->next)
    {
        size++;
    }
    // Se o primeiro nó contém dados
    // for(aux = List->first; aux != NULL; aux = aux->next) { size++; }

    return (size);
}

// Exibe os IDs de cada elemento da lista, com separador espaço
void printCell_ID(ListPersonagem *List)
{
    printf("[ ");
    Cell *aux;
    for( aux = List->first->next; aux != NULL; aux = aux->next) // Assumindo sentinela no first
    {
        printf("%s ", aux->personagem.id);
    }
    printf("] \n");
}

// Funcao para dar free
void freeCell(ListPersonagem *List)
{
    Cell *aux = List->first;
    Cell *next_node; // Use um nome diferente para evitar conflito com 'next' do struct

    while (aux != NULL)
    {
        next_node = aux->next; // Salva o próximo nó antes de liberar o atual
        // Lembre-se de liberar as Listas internas de Personagem se elas foram alocadas dinamicamente
        if (aux->personagem.alternative_names != NULL) {
            // É preciso liberar as strings dentro da List e a própria List
            free_List(aux->personagem.alternative_names);
            aux->personagem.alternative_names = NULL; // Evitar double free
        }
        if (aux->personagem.alternative_actors != NULL) {
            free_List(aux->personagem.alternative_actors);
            aux->personagem.alternative_actors = NULL;
        }
        free(aux);
        aux = next_node;
    }

    List->first = NULL;
    List->last = NULL;
}