#ifndef COMMON_H
#define COMMON_H

// ---------------------- LISTA DE DEPENDENCIAS
#include <stdio.h>   // para entradas e saidas
#include <stddef.h>  // para definicoes basicas
#include <stdlib.h>  // para a biblioteca padrao
#include <string.h>  // para cadeias de caracteres
#include <stdarg.h>  // para tratar argumentos
#include <stdbool.h> // para definicoes logicas
#include <ctype.h>   // para tipos padroes
#include <math.h>    // para definicoes matematicas
#include <time.h>    // para medir tempo
#include <wchar.h>   // para 16-bit characters
#include <iso646.h>  // para and, or, xor, not alternatives

// -------------------------- DEFINICOES DE TIPO
typedef char* String;
typedef char** StringArray;
typedef const char* const literal;

// ---------------------- definicoes de constantes
#define STR_SIZE 200    // definir tamanho padrao para caracteres
#define LINE_SIZE 1024 // definir tamanho padrao para linhas
#define FIT_SIZE 50
#define COMMON_SIZE 15
#define TOTAL_CHARACTERS 500
#define ALTERNATIVE_NAMES_SIZE 10

// --------------------------- CLASSE TIMER ---------------------------
typedef struct Timer {
	clock_t startTime;
	clock_t endTime;
	double totalTime;
	void (*Start)(struct Timer*);
	void (*Stop)(struct Timer*);
	double (*Time)(struct Timer*);
} Timer;

void TimerStart(Timer* timer);
void TimerStop(Timer* timer);
double TimerTime(Timer* timer);
Timer newTimer();

typedef struct Log {
	int comparacoes, movimentacoes;
	void (*RegistroPesquisa) (literal fileName, Timer, struct Log);
	void (*RegistroOrdenacao) (literal fileName, Timer, struct Log);
} Log;

void RegistroPesquisa(literal fileName, Timer timer, Log log);
void RegistroOrdenacao(literal fileName, Timer timer, Log log);
Log newLog();

#endif