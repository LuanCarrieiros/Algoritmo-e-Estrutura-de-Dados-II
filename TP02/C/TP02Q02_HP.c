// TP02Q02_HP.c

#include "LibHP.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
 * TP02Q02_HP.c
 * 
 * Este programa lê IDs de personagens do Harry Potter da entrada padrão,
 * busca esses personagens em um banco de dados carregado de um arquivo CSV,
 * e exibe os detalhes dos personagens encontrados.
 * 
 * O banco de dados é inicializado com uma lista de personagens, e os IDs são
 * lidos até que a string "FIM" seja encontrada.
*/


int main() {
    // Inicializa a lista principal (Banco de Dados) para Personagens
    // HP_MAX_CHARACTERS é definido em LibHP.h
    ListaHP BD_Personagens = newListaHP(HP_MAX_CHARACTERS);
    
    // Carrega os personagens do CSV especificado em LibHP.h (HP_FILE_PATH)
    BD_Personagens.ImportDataBase(HP_FILE_PATH, &BD_Personagens);

    if (BD_Personagens.size == 0 && BD_Personagens.maxSize > 0) {
        fprintf(stderr, "AVISO: Nenhum personagem foi carregado do CSV '%s'.\n", HP_FILE_PATH);
        // Você pode decidir sair aqui se o BD for essencial e não puder ser carregado.
        // exit(EXIT_FAILURE); 
    }

    // Cria uma lista para os personagens que serão lidos da entrada padrão

    ListaHP listaDeTrabalho = newListaHP(404); 
    char id_input[HP_MAX_LINE_SIZE]; // Buffer para ler o ID (string UUID)

    // Loop para ler IDs da entrada padrão até encontrar "FIM"
    while (readStringHP(stdin, id_input) != NULL && strcmp(id_input, "FIM") != 0) {
        Personagem p_encontrado = BD_Personagens.GetPorID(id_input, &BD_Personagens);
        
        // Verifica se um personagem válido foi retornado (ID não vazio)
        if (strlen(p_encontrado.id) > 0) {
            listaDeTrabalho.Inserir(p_encontrado, &listaDeTrabalho);
        } else {
            // Opcional: Avisar se um ID não foi encontrado no BD
            // fprintf(stderr, "AVISO Main: Personagem com ID '%s' não encontrado no Banco de Dados.\n", id_input);
        }
    }

    // Mostrar os personagens que foram inseridos na listaDeTrabalho
    listaDeTrabalho.Mostrar(&listaDeTrabalho);

    // Liberar memória alocada para as listas
    BD_Personagens.Close(&BD_Personagens);
    listaDeTrabalho.Close(&listaDeTrabalho);

    return 0;
}