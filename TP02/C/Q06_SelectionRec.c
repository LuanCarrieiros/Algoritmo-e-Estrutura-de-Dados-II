#include "../include/common.h"
#include "../include/personagem.h"
#include "../include/linked_list.h"
#include "../include/utils.h"
#include "../include/sorting_algos.h" // Para selectionsort

#include <stdio.h>
#include <stdlib.h> // Para exit
#include <string.h> // Para strlen

// ========================================= MAIN AUX QUESTAO 6 ========================================= //
void questaoSelecaoRecursiva()
{
    int size = 0;
    ListPersonagem List = createList("/tmp/characters.csv");
    Personagem *selecao = getFragmentsOfCharacter(&List, &size);

    Timer timer = newTimer();
    Log log = newLog();

    timer.Start(&timer);
    selectionsort(selecao, size, 0, &log);
    timer.Stop(&timer);

    showFragmentsOfCharacter(selecao, size);

    char log_filename[STR_SIZE];
    snprintf(log_filename, STR_SIZE, "logs/816676_selecao.txt"); // Caminho para o log
    log.RegistroOrdenacao(log_filename, timer, log);

    // Libera a memória alocada para o array de personagens 'selecao'
    // As listas internas (alternative_names, alternative_actors) de cada Personagem
    // também precisam ser liberadas se foram alocadas dinamicamente dentro de read().
    // E free_List() libera o ponteiro List* e os elementos internos.
    for (int i = 0; i < size; i++) {
        if (selecao[i].alternative_names != NULL) {
            free_List(selecao[i].alternative_names); // Chamar free_List para liberar a List* e seus elementos
            selecao[i].alternative_names = NULL; // Evitar double free
        }
        if (selecao[i].alternative_actors != NULL) {
            free_List(selecao[i].alternative_actors);
            selecao[i].alternative_actors = NULL;
        }
    }
    free(selecao); // Libera o array de structs Personagem
    freeCell(&List); // Libera a lista encadeada original (com seus nós sentinelas, etc.)
}

// ========================================= MAIN ========================================= //
int main (int argc, char const *argv[])
{
    questaoSelecaoRecursiva();
    return 0;
}