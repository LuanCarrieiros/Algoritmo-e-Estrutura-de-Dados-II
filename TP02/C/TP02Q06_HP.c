// TP02Q06_HP.c
// Adaptação da Q06 (Selection Sort Recursivo) para o universo Harry Potter

#include "LibHP.h" // Ajuste o caminho se necessário
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// --- Algoritmo de Ordenação: Selection Sort Recursivo para Personagem ---
// Usa o ponteiro de função CompareToStr da struct ListaHP.

void SelectionSortRecursivoHP_Q06(int i, int j, int menor_idx, LogHP* log, ListaHP* lista) {
    if (i >= lista->size - 1) { // Condição de parada da recursão principal
        return;
    }

    if (j < lista->size) { // Loop interno recursivo para encontrar o menor
        // Usando o método de comparação da lista, que por sua vez usa atributo_ordenacao
        if (lista->CompareToStr(lista->array[menor_idx], lista->array[j], log) > 0) { 
            // CompareToStr retorna > 0 se o primeiro argumento é "maior" que o segundo.
            // Queremos encontrar o "menor", então se array[menor_idx] > array[j], atualizamos menor_idx.
            menor_idx = j;
        }
        SelectionSortRecursivoHP_Q06(i, j + 1, menor_idx, log, lista);
    } else { // Fim do loop interno, encontramos o menor para a posição 'i'
        if (menor_idx != i) { // Só troca se o menor não for ele mesmo
            swapHP(&lista->array[i], &lista->array[menor_idx], log);
        }
        // Chamada para a próxima iteração "principal" do selection sort
        if (i + 1 < lista->size ) { // Ajuste para evitar i + 2 ir out of bounds se i+1 == size-1
             SelectionSortRecursivoHP_Q06(i + 1, (i + 1) + 1, i + 1, log, lista);
        }
    }
}

void SelectionSortHP_Q06(LogHP* log, ListaHP* lista) {
    if (lista->size > 1) { // Só ordena se houver mais de um elemento
        SelectionSortRecursivoHP_Q06(0, 1, 0, log, lista);
    }
}

int main() {
    TimerHP timer = newTimerHP();
    LogHP log = newLogHP();

    ListaHP BD_Personagens = newListaHP(HP_MAX_CHARACTERS);
    BD_Personagens.ImportDataBase(HP_FILE_PATH, &BD_Personagens);

    ListaHP listaDeTrabalho = newListaHP(500); 
    char id_input[HP_MAX_LINE_SIZE];

    while (readStringHP(stdin, id_input) != NULL && strcmp(id_input, "FIM") != 0) {
        Personagem p_encontrado = BD_Personagens.GetPorID(id_input, &BD_Personagens);
        if (strlen(p_encontrado.id) > 0) {
            listaDeTrabalho.Inserir(p_encontrado, &listaDeTrabalho);
            // Configura o atributo de ordenação para 'name' para o personagem recém-inserido
            if (listaDeTrabalho.size > 0) {
                 listaDeTrabalho.setAtributoOrdenacao(&listaDeTrabalho, listaDeTrabalho.size - 1, "name");
            }
        }
    }

    timer.Start(&timer);
    SelectionSortHP_Q06(&log, &listaDeTrabalho);
    timer.Stop(&timer);

    listaDeTrabalho.Mostrar(&listaDeTrabalho);

    log.RegistroOrdenacao("logs/816676_selecaoRecursiva.txt", timer, log); // Sua matrícula

    BD_Personagens.Close(&BD_Personagens);
    listaDeTrabalho.Close(&listaDeTrabalho);

    return 0;
}