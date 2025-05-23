#include "../include/common.h"
#include "../include/personagem.h"
#include "../include/linked_list.h"
#include "../include/utils.h"
#include "../include/search_algos.h" // Para binarySearch
#include "../include/sorting_algos.h" // Para quicksort_static (se precisar ordenar o array de IDs)

#include <stdio.h>
#include <stdlib.h> // Para exit
#include <string.h> // Para strcmp

// ========================================= MAIN AUX QUESTAO 04 ========================================= //
void questaoPesquisaBinaria()
{
    int size = 0;
    char text[LINE_SIZE]; // Use LINE_SIZE para o buffer de leitura de entrada

    ListPersonagem List = createList("/tmp/characters.csv");
    StringArray personagensID = fillFieldWithIds(&size); // Este array precisa estar ordenado para binarySearch

    // IMPORTANTE: Para binarySearch funcionar corretamente com IDs, o array personagensID DEVE estar ordenado.
    // Se fillFieldWithIds não garante a ordem, você precisa ordenar aqui.
    // O desempate na sua função binarySearch sugere que 'searched' pode ser um nome ou ID.
    // Se a busca principal é por ID, o array deve estar ordenado por ID.
    // Se for por nome, o array deve estar ordenado por nome (e o fillFieldWithIds deveria preencher com nomes).

    // Assumindo que 'personagensID' contém IDs e que a ordenação original por ID não estava explícita,
    // se você precisar ordenar, aqui seria o lugar (Ex: usando quicksort_static para StringArray):
    // quicksort_static(personagensID, 0, size - 1, /* passar log se necessário */);
    // Mas note que sua função quicksort está para Personagem[], não StringArray.
    // Para uma busca binária de IDs, o array de IDs precisa ser ordenado por ID.

    // No seu binarySearch, você usa getElementByID para pegar a personagem,
    // mas também compara o nome da personagem (e alternativos) com 'searched'.
    // Isso indica que o 'searched' pode ser um nome e a função 'binarySearch' está tentando
    // uma abordagem híbrida (encontrar o ID e depois verificar nomes associados).
    // Para que a busca binária seja eficaz, o array `personagensID` teria que estar ordenado por NOME
    // se a intenção é buscar nomes através dele.

    Timer timer = newTimer();
    Log log = newLog();

    timer.Start(&timer);

    // Lendo as entradas de busca
    if (scanf(" %[^\r\n]%*c", text) != 1) { // Garante que a leitura da primeira linha é bem-sucedida
        fprintf(stderr, "Erro na leitura da primeira linha de entrada.\n");
        // Tratar erro ou sair
        // free recursos antes de sair
        exit(EXIT_FAILURE);
    }

    while(!equals(text, "FIM"))
    {
        bool found = binarySearch(personagensID, text, 0, size - 1, &List, &log);
        (found) ? printf("SIM\n") : printf("NAO\n");

        if (scanf(" %[^\r\n]%*c", text) != 1) { // Lendo a próxima linha
            // Se for EOF ou erro, sair do loop
            if (feof(stdin) || ferror(stdin)) {
                break;
            }
        }
    }
    timer.Stop(&timer);

    char log_filename[STR_SIZE];
    snprintf(log_filename, STR_SIZE, "logs/816676_binaria.txt"); // Caminho para o log
    log.RegistroPesquisa(log_filename, timer, log);

    // Libera a memória alocada para personagensID
    for (int k = 0; k < size; k++) {
        free(personagensID[k]);
    }
    free(personagensID);
    freeCell(&List); // Libera a lista de personagens (incluindo as Listas internas de Personagem)
}

// ========================================= MAIN ========================================= //
int main (int argc, char const *argv[])
{
    questaoPesquisaBinaria();
    return 0;
}