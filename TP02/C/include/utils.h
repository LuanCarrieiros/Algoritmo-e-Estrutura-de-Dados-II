#ifndef UTILS_H
#define UTILS_H

#include "../include/common.h" // Para String, StringArray, bool
#include "../include/list.h"   // Para List
#include "../include/personagem.h" // Para Personagem (usada em read)
#include "../include/linked_list.h"

// --------------------------------------- MANIPULAÇÃO DE STRINGS ---------------------------------- //

bool equals(String str1, String str2);
bool isBigger(String str1, String str2);
bool isShorter(String str1, String str2);
void isYes(bool value);
void format_Date(String date);
int countDelim(char delim, String str);
StringArray split(String str, char delimitador);
String replace(String str, char oldChar, char newChar);
String trim(String str);
void remove_char(String str, char removee);

// Funções para carregar e obter fragmentos de personagens
ListPersonagem createList(String FileName);
Personagem* getFragmentsOfCharacter(ListPersonagem *List, int *size);
StringArray fillFieldWithIds(int *size);
void showFragmentsOfCharacter(Personagem *personagem, int size);
void showFragmentsOfCharacter_static(StringArray personagem, int size, ListPersonagem *List);


#endif