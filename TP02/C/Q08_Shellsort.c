#include "../include/common.h"
#include "../include/personagem.h"
#include "../include/linked_list.h"
#include "../include/utils.h"
#include "../include/sorting_algos.h" // Para shellsort

#include <stdio.h>
#include <stdlib.h> // Para exit
#include <string.h> // Para strlen

// ======================================= MAIN AUX QUESTAO 8 ========================================== //
void questaoShellSort()
{
    int size = 0;

    ListPersonagem List = createList("./tmp/characters.csv");
    Personagem *shell = getFragmentsOfCharacter(&List, &size);

    Timer timer = newTimer();
    Log log = newLog();

    timer.Start(&timer);
    shellsort(shell, size, &log);
    timer.Stop(&timer);

    showFragmentsOfCharacter(shell, size);

    char log_filename[STR_SIZE];
    snprintf(log_filename, STR_SIZE, "logs/816676_shellsort.txt"); // Caminho para o log
    log.RegistroOrdenacao(log_filename, timer, log);

    // Libera a memória alocada para o array 'shell'
    for (int i = 0; i < size; i++) {
        if (shell[i].alternative_names != NULL) {
            free_List(shell[i].alternative_names);
            shell[i].alternative_names = NULL;
        }
        if (shell[i].alternative_actors != NULL) {
            free_List(shell[i].alternative_actors);
            shell[i].alternative_actors = NULL;
        }
    }
    free(shell);
    freeCell(&List);
}

// ========================================= MAIN ========================================= //
int main (int /*argc*/, char const * /*argv*/[])
{
    questaoShellSort();
    return 0;
}