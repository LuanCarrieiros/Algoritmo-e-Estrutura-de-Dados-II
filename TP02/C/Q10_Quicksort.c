#include "../include/common.h"
#include "../include/personagem.h"
#include "../include/linked_list.h"
#include "../include/utils.h"
#include "../include/sorting_algos.h" // Para quicksort

#include <stdio.h>
#include <stdlib.h> // Para exit
#include <string.h> // Para strlen

// ========================================= MAIN AUX QUESTAO 10 ========================================= //
void questaoQuickSort()
{
    int size = 0;
    ListPersonagem List = createList("./tmp/characters.csv");
    Personagem *personagens = getFragmentsOfCharacter(&List, &size);
    Timer timer = newTimer();
    Log log = newLog();

    timer.Start(&timer);
    quicksort(personagens, 0, size - 1, &log);
    timer.Stop(&timer);

    showFragmentsOfCharacter(personagens, size);

    char log_filename[STR_SIZE];
    snprintf(log_filename, STR_SIZE, "logs/816676_quicksort.txt"); // Caminho para o log
    log.RegistroOrdenacao(log_filename, timer, log);

    // Libera a memória alocada para o array 'personagens'
    for (int i = 0; i < size; i++) {
        if (personagens[i].alternative_names != NULL) {
            free_List(personagens[i].alternative_names);
            personagens[i].alternative_names = NULL;
        }
        if (personagens[i].alternative_actors != NULL) {
            free_List(personagens[i].alternative_actors);
            personagens[i].alternative_actors = NULL;
        }
    }
    free(personagens);
    freeCell(&List);
}

// ========================================= MAIN ========================================= //
int main (int /*argc*/, char const * /*argv*/[])
{
    questaoQuickSort();
    return 0;
}