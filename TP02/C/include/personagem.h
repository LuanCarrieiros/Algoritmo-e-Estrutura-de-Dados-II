#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "../include/common.h" // Para constantes como FIT_SIZE, COMMON_SIZE
#include "../include/list.h"   // Porque Personagem usa List

// ------------------------------ STRUCT PERSONAGEM ----------------------------- //
typedef struct Personagem
{
    char id[FIT_SIZE];
    char name[FIT_SIZE];
    List *alternative_names;
    char house[COMMON_SIZE];
    char ancestry[COMMON_SIZE];
    char species[COMMON_SIZE];
    char patronus[COMMON_SIZE];
    bool hogwarts_staff;
    bool hogwarts_student;
    char actor_name[FIT_SIZE];
    bool alive;
    List *alternative_actors;
    char dateOfBirth[11]; // para inserir o espaço da data formatada
    int yearOfBirth;
    char eye_colour[COMMON_SIZE];
    char gender[COMMON_SIZE];
    char hair_colour[COMMON_SIZE];
    bool wizard;
} Personagem;

// ----------------------------- MÉTODOS E FUNCOES DA STRUCT PERSONAGEM -----------------------//
void reset(Personagem *personagem);
void print(Personagem personagem);
void read(Personagem *personagem, String line); // read é uma função de tratamento de Personagem

#endif