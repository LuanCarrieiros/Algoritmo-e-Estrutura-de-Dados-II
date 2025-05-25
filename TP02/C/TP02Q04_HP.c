// TP02Q04_HP.c
// Adaptação da Q04:
// 1. Busca Binária EXATA no campo 'name'.
// 2. Se não encontrar, faz uma Busca Sequencial (strstr) no 'name' E em 'alternate_names_list'.

#include "LibHP.h" // Assumindo que LibHP.h está na mesma pasta ou o include path está configurado
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Comando de compilação sugerido (assumindo que LibHP.h e este .c estão na mesma pasta):
gcc TP02Q04_HP.c -o q04_hp_app -lm

Execução (após compilar):
./q04_hp_app < sua_entrada_q04.txt 
*/

// --- Algoritmo de Ordenação (Selection Sort por Nome) ---
// Mantido para ordenar a listaDeTrabalho pelo nome principal antes das buscas.
void SortByNomeHP_Q04(ListaHP* lista, LogHP* log) {
    int n = lista->size;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (log) log->comparacoes++;
            if (strcmp(lista->array[j].name, lista->array[min_idx].name) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swapHP(&lista->array[i], &lista->array[min_idx], log);
        }
    }
}

// --- ETAPA 1: Busca Binária Recursiva APENAS no Nome Principal (correspondência exata) ---
bool PesquisaBinariaApenasNoNomePrincipalRecursiva(const char* termo_pesquisa, int esquerda, int direita, LogHP* log, const ListaHP* lista) {
    if (esquerda > direita) {
        return false; // Elemento não encontrado
    }

    int meio = esquerda + (direita - esquerda) / 2;
    const Personagem* p_meio = &lista->array[meio];
    
    if (log) log->comparacoes++; // Contabiliza a comparação principal da iteração
    int comparacao_resultado = strcmp(p_meio->name, termo_pesquisa);

    if (comparacao_resultado == 0) {
        return true; // Nome principal encontrado (correspondência exata)
    } else if (comparacao_resultado < 0) {
        // O nome no meio do array é menor que o termo_pesquisa, busca na metade direita
        return PesquisaBinariaApenasNoNomePrincipalRecursiva(termo_pesquisa, meio + 1, direita, log, lista);
    } else {
        // O nome no meio do array é maior que o termo_pesquisa, busca na metade esquerda
        return PesquisaBinariaApenasNoNomePrincipalRecursiva(termo_pesquisa, esquerda, meio - 1, log, lista);
    }
}

bool PesquisaBinariaPrincipalHP(const char* nome_pesquisa, LogHP* log, const ListaHP* lista) {
    if (lista->size == 0) return false;
    return PesquisaBinariaApenasNoNomePrincipalRecursiva(nome_pesquisa, 0, lista->size - 1, log, lista);
}


// --- ETAPA 2: Busca Sequencial (strstr) no Nome Principal E na Lista de Nomes Alternativos ---
// Esta função será chamada SE a busca binária no nome principal falhar.
bool PesquisaSequencialNomeEAlternativosHP(const char* termo_pesquisa, LogHP* log, const ListaHP* lista) {
    for (int i = 0; i < lista->size; i++) {
        const Personagem* p_atual = &lista->array[i];

        // Verifica o nome principal com strstr
        if (log) log->comparacoes++; // Conta a verificação do nome principal
        if (p_atual->name[0] != '\0' && strstr(p_atual->name, termo_pesquisa) != NULL) {
            return true;
        }

        // Verifica a lista de nomes alternativos com strstr
        for (int k = 0; k < p_atual->alternate_names_actual_count; k++) {
            if (log) log->comparacoes++; // Conta cada verificação de nome alternativo
            if (p_atual->alternate_names_list[k][0] != '\0' && strstr(p_atual->alternate_names_list[k], termo_pesquisa) != NULL) {
                return true;
            }
        }
    }
    return false; // Não encontrado em nenhum nome principal nem alternativo na lista toda
}


int main() {
    TimerHP timer = newTimerHP();
    LogHP log = newLogHP();

    ListaHP BD_Personagens = newListaHP(HP_MAX_CHARACTERS);
    BD_Personagens.ImportDataBase(HP_FILE_PATH, &BD_Personagens);

    ListaHP listaDeTrabalho = newListaHP(500); 
    char id_input[HP_MAX_LINE_SIZE];
    char nome_para_pesquisar[HP_MAX_LINE_SIZE];

    // Fase 1: Ler IDs e popular a listaDeTrabalho
    while (readStringHP(stdin, id_input) != NULL && strcmp(id_input, "FIM") != 0) {
        Personagem p_encontrado = BD_Personagens.GetPorID(id_input, &BD_Personagens);
        if (strlen(p_encontrado.id) > 0) {
            listaDeTrabalho.Inserir(p_encontrado, &listaDeTrabalho);
        }
    }

    // Ordenar a listaDeTrabalho por nome principal para a Busca Binária
    SortByNomeHP_Q04(&listaDeTrabalho, &log);
    
    log.comparacoes = 0; 
    log.movimentacoes = 0;

    // Fase 2: Ler nomes para pesquisar
    timer.Start(&timer);
    while (readStringHP(stdin, nome_para_pesquisar) != NULL && strcmp(nome_para_pesquisar, "FIM") != 0) {
        bool encontrado = false;
        
        // 1. Tenta Busca Binária no nome principal (correspondência exata)
        encontrado = PesquisaBinariaPrincipalHP(nome_para_pesquisar, &log, &listaDeTrabalho);
        
        // 2. Se não encontrou no nome principal pela busca binária,
        //    tenta uma busca sequencial (strstr) no nome principal E nos nomes alternativos.
        //    Esta parte não é mais "busca binária", mas garante que nomes alternativos sejam checados.
        if (!encontrado) {
            // Para fins de log, as comparações da busca sequencial são adicionadas ao mesmo log.
            // Se quisesse separar, precisaria de outro log ou resetar antes.
            encontrado = PesquisaSequencialNomeEAlternativosHP(nome_para_pesquisar, &log, &listaDeTrabalho);
        }
        
        printf("%s\n", encontrado ? "SIM" : "NAO");
    }
    timer.Stop(&timer);

    log.RegistroPesquisa("logs/816676_binaria.txt", timer, log); // Sua matrícula

    BD_Personagens.Close(&BD_Personagens);
    listaDeTrabalho.Close(&listaDeTrabalho);

    return 0;
}