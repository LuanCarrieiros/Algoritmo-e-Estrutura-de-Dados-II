#include "../include/personagem.h"
#include "../include/common.h"
#include "../include/list.h"
#include "../include/utils.h" // Para trim, remove_char, split, format_Date, equals, etc.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ----------------------------- MÉTODOS E FUNCOES DA STRUCT PERSONAGEM -----------------------//

void reset(Personagem *personagem)
{
    personagem->hogwarts_staff = false;
    personagem->alive = false;
    personagem->yearOfBirth = 0;
    personagem->wizard = false;
    personagem->alternative_names = (List *)malloc(sizeof(List));
    init_list(50, personagem->alternative_names);
    personagem->alternative_actors = (List *)malloc(sizeof(List));
    init_list(50, personagem->alternative_actors);
}

// Funcao para ler e tratar os dados do arquivo
void read(Personagem *personagem, String line)
{
    StringArray tratamento = split(line, ';'); // dividir a linha lida em substrings
    // atribuicoes
    strcpy(personagem->id, tratamento[0]);
    strcpy(personagem->name, tratamento[1]);
    strcpy(personagem->house, tratamento[3]);
    strcpy(personagem->ancestry, tratamento[4]);
    strcpy(personagem->species, tratamento[5]);
    strcpy(personagem->patronus, tratamento[6]);
    strcpy(personagem->actor_name, tratamento[9]);
    strcpy(personagem->dateOfBirth, tratamento[12]);
    format_Date(personagem->dateOfBirth);
    personagem->yearOfBirth = atoi (tratamento[13]);
    strcpy(personagem->eye_colour, tratamento[14]);
    strcpy(personagem->gender, tratamento[15]);
    strcpy(personagem->hair_colour, tratamento[16]);

    // tratamento booleano
    personagem->hogwarts_staff = (strcmp(tratamento[7], "VERDADEIRO") == 0) ? 1 : 0;   // operador ternário para atribuir 1 ou 0 ao valor booleano
    personagem->hogwarts_student = (strcmp(tratamento[8], "VERDADEIRO") == 0) ? 1 : 0; // operador ternário para atribuir 1 ou 0 ao valor booleano
    personagem->alive = (strcmp(tratamento[10], "VERDADEIRO") == 0) ? 1 : 0; // operador ternário para atribuir 1 ou 0 ao valor booleano
    personagem->wizard = (tratamento[17][0] == 'V') ? 1 : 0; // operador ternário para atribuir 1 ou 0 ao valor booleano

    // tratamento da lista de nomes alternativos
    // A alocação já é feita no reset. Aqui, apenas reutilizamos/limpamos.
    // Se for alocar novamente, liberar a anterior para evitar vazamento.
    // Para evitar duplo free/vazamento, garanta que reset é chamado antes.
    if (personagem->alternative_names == NULL) { // Garante que a lista está inicializada
        personagem->alternative_names = (List*) malloc (sizeof(List));
        init_list(15, personagem->alternative_names);
    } else {
        // Limpar lista existente se read for chamado múltiplas vezes para o mesmo Personagem
        // free_List(personagem->alternative_names); // Se free_List liberar a própria struct List
        // init_list(15, personagem->alternative_names); // E aqui inicializaria novamente
        // Ou apenas resetar o size para 0 se o malloc das strings internas for mantido
        personagem->alternative_names->size = 0;
    }


    String aux = tratamento[2];
    // tratamento a string para remover os caracteres indesejados
    remove_char(aux, '[');
    remove_char(aux, ']');
    remove_char(aux, '\'');

    size_t countD = countDelim(',', aux);
    StringArray altname = split(aux, ',');

    for(size_t i = 0; i < countD; i++)
    {
        String trimmed_name = trim(altname[i]); // trim retorna a própria string modificada ou uma nova
        if(strlen(trimmed_name) > 0) // Verifica se a string não está vazia após o trim
        {
            add_listEnd(trimmed_name, personagem->alternative_names, countD);
        }
    }
    // Libere altname após o uso
    for (size_t i = 0; i < countD; i++) {
        free(altname[i]);
    }
    free(altname);


    // tratamento da lista de atores alternativos
    if (personagem->alternative_actors == NULL) { // Garante que a lista está inicializada
        personagem->alternative_actors = (List*) malloc (sizeof(List));
        init_list(15, personagem->alternative_actors);
    } else {
        personagem->alternative_actors->size = 0;
    }

    String aux2;
    aux2 = tratamento[11];

    // tratamento a string para remover os caracteres indesejados
    remove_char(aux2, '[');
    remove_char(aux2, ']');
    remove_char(aux2, '\'');

    int countD2 = countDelim(',', aux2);
    StringArray altactor = split(aux2, ',');

    for(size_t i = 0; i < countD2; i++)
    {
        String trimmed_actor = trim(altactor[i]);
        if(strlen(trimmed_actor) > 0) { // Verifica se a string não está vazia após o trim
             add_listEnd(trimmed_actor, personagem->alternative_actors, countD2 );
        }
    }
    // Libere altactor após o uso
    for (size_t i = 0; i < countD2; i++) {
        free(altactor[i]);
    }
    free(altactor);

    // Libere tratamento após o uso
    for (int i = 0; i < countDelim(';', line); i++) { // Use a contagem original de delimitadores para tratamento
        free(tratamento[i]);
    }
    free(tratamento);
}

// Funcao para imprimir os dados do personagem
void print(Personagem personagem)
{
    printf("[%s ## %s ## {", personagem.id, personagem.name);
    for(int i = 0; i < personagem.alternative_names->size; i++)
    {
        if(i == (personagem.alternative_names->size - 1))
        {
            printf("%s", personagem.alternative_names->element[i]);
        } else
        {
            printf("%s, ", personagem.alternative_names->element[i]);
        }
    }

    printf("} ## %s ## ", personagem.house);
    printf("%s ## ", personagem.ancestry);
    printf("%s ## ", personagem.species);
    printf("%s ## ", personagem.patronus);
    printf("%s ", personagem.hogwarts_staff ? "true ##" : "false ##");
    printf("%s ", personagem.hogwarts_student ? "true ##" : "false ##");
    printf("%s ## ", personagem.actor_name);
    printf("%s ", personagem.alive ? "true ##" : "false ##");
    printf("%s ## ", personagem.dateOfBirth);
    printf("%d ## ", personagem.yearOfBirth);
    printf("%s ## ", personagem.eye_colour);
    printf("%s ## ", personagem.gender);
    printf("%s ## ", personagem.hair_colour);
    printf("%s", personagem.wizard ? "true]\n" : "false]\n");
}