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
    printf("DEBUG: Iniciando questaoSelecaoRecursiva.\n");
    int size = 0;
    ListPersonagem List = createList("./tmp/characters.csv");
    // Adicionando a linha de depuração para verificar os ponteiros first e last da lista
    printf("DEBUG: ListPersonagem criada. first: %p, last: %p\n", (void*)List.first, (void*)List.last);
    printf("DEBUG: Chamando getFragmentsOfCharacter.\n");

    Personagem *selecao = getFragmentsOfCharacter(&List, &size);

    printf("DEBUG: getFragmentsOfCharacter retornou. Tamanho lido: %d\n", size);
    if (size == 0) {
        printf("AVISO: Nenhuma personagem foi lida para processamento. Encerrando questao.\n");
        // É importante liberar a memória mesmo que o array esteja vazio
        // free(selecao); // Se size é 0 e malloc retornou um ponteiro válido para 27*sizeof(Personagem), free() é seguro.
        // freeCell(&List);
        return; // Sai da função se não houver dados.
    }

    Timer timer = newTimer();
    Log log = newLog();

    timer.Start(&timer);
    selectionsort(selecao, size, 0, &log);
    timer.Stop(&timer);

    showFragmentsOfCharacter(selecao, size);
    printf("DEBUG: Personagens exibidas. Gerando log.\n");

    char log_filename[STR_SIZE];
    snprintf(log_filename, STR_SIZE, "logs/816676_selecao.txt");
    log.RegistroOrdenacao(log_filename, timer, log);
    printf("DEBUG: Log gerado. Liberando memoria.\n");

    // Libera a memória alocada para o array 'selecao'
    for (int i = 0; i < size; i++) {
        if (selecao[i].alternative_names != NULL) {
            free_List(selecao[i].alternative_names);
            selecao[i].alternative_names = NULL;
        }
        if (selecao[i].alternative_actors != NULL) {
            free_List(selecao[i].alternative_actors);
            selecao[i].alternative_actors = NULL;
        }
    }
    free(selecao);
    freeCell(&List);
    printf("DEBUG: Memoria liberada. Fim da questaoSelecaoRecursiva.\n");
}

// ========================================= MAIN ========================================= //
int main (int /*argc*/, char const * /*argv*/[])
{
    questaoSelecaoRecursiva();
    return 0;
}