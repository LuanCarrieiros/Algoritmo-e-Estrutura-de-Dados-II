#ifndef LIB_HP_H
#define LIB_HP_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h> // Para isspace()

// --------------------------- DEFINIÇÕES GLOBAIS E UTILITÁRIAS (Harry Potter) ---------------------------
#define HP_MAX_CHARACTERS 405
#define HP_FILE_PATH "tmp/characters.csv"
#define HP_MAX_UUID_SIZE 37
#define HP_MAX_NAME_SIZE 30
#define HP_MAX_ALT_NAME_COUNT 10     // Máximo de nomes alternativos/atores individuais
#define HP_MAX_INDIVIDUAL_ALT_NAME_SIZE 35 // Tamanho de cada nome alternativo/ator
#define HP_MAX_HOUSE_SIZE 15
#define HP_MAX_ANCESTRY_SIZE 15
#define HP_MAX_SPECIES_SIZE 20
#define HP_MAX_PATRONUS_SIZE 25
#define HP_MAX_ACTOR_NAME_SIZE 35
#define HP_MAX_EYE_COLOUR_SIZE 10
#define HP_MAX_GENDER_SIZE 10
#define HP_MAX_HAIR_COLOUR_SIZE 10
#define HP_MAX_LINE_SIZE 300
#define HP_MAX_CAMPO_SPLIT 512 
#define HP_NUM_CAMPOS_CSV 18

typedef const char* const literal_hp;
typedef char* StringHP;

// Forward declarations para clareza e ordem
struct SplitHP; typedef struct SplitHP SplitHP;
struct TimerHP; typedef struct TimerHP TimerHP;
struct LogHP; typedef struct LogHP LogHP;
struct Personagem; typedef struct Personagem Personagem;
struct ListaHP; typedef struct ListaHP ListaHP;

// --------------------------- DEFINIÇÕES DAS STRUCTS ---------------------------
struct SplitHP {
    char array[HP_NUM_CAMPOS_CSV][HP_MAX_CAMPO_SPLIT];
};

struct TimerHP {
    clock_t startTime; clock_t endTime; double totalTimeSeconds;
    void (*Start)(TimerHP*); void (*Stop)(TimerHP*); double (*GetTimeSeconds)(TimerHP*);
};

struct LogHP {
    int comparacoes; int movimentacoes;
    void (*RegistroPesquisa)(literal_hp fileName, TimerHP timer, LogHP log);
    void (*RegistroOrdenacao)(literal_hp fileName, TimerHP timer, LogHP log);
};

struct Personagem {
    char id[HP_MAX_UUID_SIZE];
    char name[HP_MAX_NAME_SIZE];
    char alternate_names_list[HP_MAX_ALT_NAME_COUNT][HP_MAX_INDIVIDUAL_ALT_NAME_SIZE + 1];
    int alternate_names_actual_count;
    char house[HP_MAX_HOUSE_SIZE];
    char ancestry[HP_MAX_ANCESTRY_SIZE];
    char species[HP_MAX_SPECIES_SIZE];
    char patronus[HP_MAX_PATRONUS_SIZE];
    bool hogwartsStaff;
    bool hogwartsStudent;
    char actorName[HP_MAX_ACTOR_NAME_SIZE];
    bool alive;
    char alternate_actors_list[HP_MAX_ALT_NAME_COUNT][HP_MAX_INDIVIDUAL_ALT_NAME_SIZE + 1];
    int alternate_actors_actual_count;
    char dateOfBirth[15]; // DD-MM-AAAA
    int yearOfBirth;
    char eyeColour[HP_MAX_EYE_COLOUR_SIZE];
    char gender[HP_MAX_GENDER_SIZE];
    char hairColour[HP_MAX_HAIR_COLOUR_SIZE];
    bool wizard;
    void* atributo_ordenacao;
    void (*Mostrar)(const Personagem* self);
};

struct ListaHP {
    Personagem* array; int maxSize; int size;
    void (*Inserir)(Personagem p, ListaHP* lista);
    void (*ImportDataBase)(literal_hp filePath, ListaHP* bd_lista);
    Personagem (*GetPorID)(const char* id_str, const ListaHP* bd_lista);
    void (*setAtributoOrdenacao)(ListaHP* lista, int index_personagem, const char* nome_campo_personagem);
    bool (*CompareToInt)(Personagem p1, Personagem p2, LogHP* log);
    int  (*CompareToStr)(Personagem p1, Personagem p2, LogHP* log);
    bool (*CompareToBool)(Personagem p1, Personagem p2, LogHP* log);
    int  (*CompareToDateStr)(Personagem p1, Personagem p2, LogHP* log);
    void (*Mostrar)(const ListaHP* lista);
    void (*MostrarParcial)(int k, const ListaHP* lista);
    void (*Close)(ListaHP* lista);
};

// --------------------------- PROTÓTIPOS DAS FUNÇÕES ---------------------------
char* readStringHP(FILE* stream, StringHP input_buffer);
SplitHP newSplitHP(FILE* csv_file);
void TimerHPStart(TimerHP* timer); void TimerHPStop(TimerHP* timer); double TimerHPGetTimeSeconds(TimerHP* timer); TimerHP newTimerHP();
void RegistroPesquisaHP(literal_hp fileName, TimerHP timer, LogHP log); void RegistroOrdenacaoHP(literal_hp fileName, TimerHP timer, LogHP log); LogHP newLogHP();
void MostrarPersonagem(const Personagem* p);
Personagem newPersonagem();
void ConstrutorPersonagem(Personagem* p, SplitHP campos_split);
Personagem ClonarPersonagem(const Personagem* original);
void processarCampoHP(const char* token, char* buffer, size_t buffer_size);
bool parseBooleanHP(const char* str);
void parseListOfStrings(const char* list_str, char list_array[][HP_MAX_INDIVIDUAL_ALT_NAME_SIZE + 1], int* actual_count, int max_count, int max_str_len_each_item);
void InserirListaHP(Personagem p, ListaHP* lista);
void ImportDataBaseHP(literal_hp filePath, ListaHP* bd_lista);
Personagem GetPersonagemPorID_HP(const char* id_str, const ListaHP* bd_lista);
void setAtributoOrdenacaoHP(ListaHP* lista, int index_personagem_na_lista, const char* nome_campo_personagem);
void MostrarListaHP(const ListaHP* lista); void MostrarParcialListaHP(int k, const ListaHP* lista); void CloseListaHP(ListaHP* lista);
ListaHP newListaHP(size_t maxSize);
void swapHP(Personagem* a, Personagem* b, LogHP* log);
bool CompareHP_IntAttr_Then_Name(Personagem p1, Personagem p2, LogHP* log);
int CompareHP_StrAttr_Then_Name(Personagem p1, Personagem p2, LogHP* log);
bool CompareHP_BoolAttr_Then_Name(Personagem p1, Personagem p2, LogHP* log);
int CompareHP_DateStr_Then_Name(Personagem p1, Personagem p2, LogHP* log);
bool parseDateHP_for_compare(const char* dateStr, int* year, int* month, int* day);

// --------------------------- IMPLEMENTAÇÕES ---------------------------

char* readStringHP(FILE* stream, StringHP input_buffer) {
    if (!stream) stream = stdin;
    if (fgets(input_buffer, HP_MAX_LINE_SIZE, stream) == NULL) { input_buffer[0] = '\0'; return NULL; }
    input_buffer[strcspn(input_buffer, "\n\r")] = '\0';
    return input_buffer;
}

SplitHP newSplitHP(FILE* csv_file) {
    SplitHP split_hp;
    char buffer_field[HP_MAX_CAMPO_SPLIT];
    for (int i = 0; i < HP_NUM_CAMPOS_CSV; i++) {
        buffer_field[0] = '\0'; 
        int scan_result = fscanf(csv_file, "%[^;\n]", buffer_field);
        if (scan_result == EOF) {
            strcpy(split_hp.array[i], "");
            for (int j = i + 1; j < HP_NUM_CAMPOS_CSV; j++) strcpy(split_hp.array[j], "");
            break; 
        } else if (scan_result == 0) {
            strcpy(split_hp.array[i], "");
        } else {
            strcpy(split_hp.array[i], buffer_field);
        }
        char delim_char = fgetc(csv_file);
        if (i < HP_NUM_CAMPOS_CSV - 1) {
            if (delim_char == '\n' || delim_char == EOF) {
                for (int j = i + 1; j < HP_NUM_CAMPOS_CSV; j++) strcpy(split_hp.array[j], "");
                if (delim_char == EOF) break; // Sai do loop de campos se EOF
                break; // Sai do loop de campos se \n prematuro
            }
            // Se delim_char não for ';', o próximo fscanf pode ter problemas. O CSV deve ser consistente.
        } else { // É o último campo, delim_char deveria ser \n ou EOF
            if (delim_char != '\n' && delim_char != EOF) {
                 char temp_c;
                 while((temp_c = fgetc(csv_file)) != '\n' && temp_c != EOF);
            }
        }
    }
    return split_hp;
}

void TimerHPStart(TimerHP* timer) { timer->startTime = clock(); }
void TimerHPStop(TimerHP* timer) { timer->endTime = clock(); }
double TimerHPGetTimeSeconds(TimerHP* timer) {
    timer->totalTimeSeconds = ((double)(timer->endTime - timer->startTime)) / CLOCKS_PER_SEC;
    return timer->totalTimeSeconds;
}
TimerHP newTimerHP() {
    TimerHP timer;
    timer.Start = TimerHPStart; timer.Stop = TimerHPStop; timer.GetTimeSeconds = TimerHPGetTimeSeconds;
    timer.totalTimeSeconds = 0.0; timer.startTime = 0; timer.endTime = 0;
    return timer;
}

void RegistroPesquisaHP(literal_hp fileName, TimerHP timer, LogHP log) {
    FILE* file = fopen(fileName, "w");
    if (!file) { perror("LogHP: Erro ao abrir arquivo de log da pesquisa"); return; }
    fprintf(file, "Matricula: 816676\t"); // SUA MATRÍCULA AQUI
    fprintf(file, "Tempo de execucao: %.6fs\t", timer.GetTimeSeconds(&timer));
    fprintf(file, "Numero de comparacoes: %d\n", log.comparacoes);
    fclose(file);
}
void RegistroOrdenacaoHP(literal_hp fileName, TimerHP timer, LogHP log) {
    FILE* file = fopen(fileName, "w");
    if (!file) { perror("LogHP: Erro ao abrir arquivo de log da ordenacao"); return; }
    fprintf(file, "Matricula: 816676\t"); // SUA MATRÍCULA AQUI
    fprintf(file, "Tempo de execucao: %.6fs\t", timer.GetTimeSeconds(&timer));
    fprintf(file, "Numero de comparacoes: %d\t", log.comparacoes);
    fprintf(file, "Numero de movimentacoes: %d\n", log.movimentacoes);
    fclose(file);
}
LogHP newLogHP() {
    LogHP log = {0, 0};
    log.RegistroPesquisa = RegistroPesquisaHP; log.RegistroOrdenacao = RegistroOrdenacaoHP;
    return log;
}

Personagem newPersonagem() {
    Personagem p;
    memset(&p, 0, sizeof(Personagem)); 
    p.alternate_names_actual_count = 0;
    p.alternate_actors_actual_count = 0;
    for (int i = 0; i < HP_MAX_ALT_NAME_COUNT; i++) {
        p.alternate_names_list[i][0] = '\0';
        p.alternate_actors_list[i][0] = '\0';
    }
    p.Mostrar = MostrarPersonagem;
    return p;
}

void parseListOfStrings(const char* list_str, 
                        char list_array[][HP_MAX_INDIVIDUAL_ALT_NAME_SIZE + 1], 
                        int* actual_count, 
                        int max_count, 
                        int max_str_len_each_item) {
    *actual_count = 0;
    if (list_str == NULL || list_str[0] == '\0' || strcmp(list_str, "[]") == 0 || strcmp(list_str, "['']") == 0) {
        return;
    }

    char temp_str_buffer[HP_MAX_CAMPO_SPLIT]; 
    strncpy(temp_str_buffer, list_str, HP_MAX_CAMPO_SPLIT - 1);
    temp_str_buffer[HP_MAX_CAMPO_SPLIT - 1] = '\0';

    char* current_parse_ptr = temp_str_buffer;

    if (current_parse_ptr[0] == '[') {
        current_parse_ptr++;
        size_t len = strlen(current_parse_ptr);
        if (len > 0 && current_parse_ptr[len - 1] == ']') {
            current_parse_ptr[len - 1] = '\0';
        }
    }
    
    char* token = strtok(current_parse_ptr, ",");
    while (token != NULL && *actual_count < max_count) {
        char* item_start = token;
        
        while (*item_start && (isspace((unsigned char)*item_start) || *item_start == '\'')) {
            item_start++;
        }

        char* item_end = item_start + strlen(item_start) - 1;
        while (item_end >= item_start && (isspace((unsigned char)*item_end) || *item_end == '\'')) {
            *item_end = '\0'; 
            item_end--;
        }
        
        if (strlen(item_start) > 0) {
            strncpy(list_array[*actual_count], item_start, max_str_len_each_item);
            list_array[*actual_count][max_str_len_each_item] = '\0'; 
            (*actual_count)++;
        }
        token = strtok(NULL, ",");
    }
}

void ConstrutorPersonagem(Personagem* p, SplitHP campos_split) {
    processarCampoHP(campos_split.array[0], p->id, sizeof(p->id));
    processarCampoHP(campos_split.array[1], p->name, sizeof(p->name));
    parseListOfStrings(campos_split.array[2], p->alternate_names_list, &p->alternate_names_actual_count, HP_MAX_ALT_NAME_COUNT, HP_MAX_INDIVIDUAL_ALT_NAME_SIZE);
    processarCampoHP(campos_split.array[3], p->house, sizeof(p->house));
    processarCampoHP(campos_split.array[4], p->ancestry, sizeof(p->ancestry));
    processarCampoHP(campos_split.array[5], p->species, sizeof(p->species));
    processarCampoHP(campos_split.array[6], p->patronus, sizeof(p->patronus));
    p->hogwartsStaff = parseBooleanHP(campos_split.array[7]);
    p->hogwartsStudent = parseBooleanHP(campos_split.array[8]);
    processarCampoHP(campos_split.array[9], p->actorName, sizeof(p->actorName));
    p->alive = parseBooleanHP(campos_split.array[10]);
    parseListOfStrings(campos_split.array[11], p->alternate_actors_list, &p->alternate_actors_actual_count, HP_MAX_ALT_NAME_COUNT, HP_MAX_INDIVIDUAL_ALT_NAME_SIZE);
    processarCampoHP(campos_split.array[12], p->dateOfBirth, sizeof(p->dateOfBirth));
    if (campos_split.array[13][0] == '\0') {
        p->yearOfBirth = 0;
    } else {
        char* endptr;
        p->yearOfBirth = (int)strtol(campos_split.array[13], &endptr, 10);
        if (campos_split.array[13] == endptr || *endptr != '\0') { p->yearOfBirth = 0; }
    }
    processarCampoHP(campos_split.array[14], p->eyeColour, sizeof(p->eyeColour));
    processarCampoHP(campos_split.array[15], p->gender, sizeof(p->gender));
    processarCampoHP(campos_split.array[16], p->hairColour, sizeof(p->hairColour));
    p->wizard = parseBooleanHP(campos_split.array[17]);
    p->atributo_ordenacao = NULL;
}

void MostrarPersonagem(const Personagem* p) {
    if (p == NULL) { printf("NULL_PERSONAGEM\n"); return; }
    printf("[");
    printf("%s ## ", p->id);
    printf("%s ## ", p->name);
    printf("{");
    for (int i = 0; i < p->alternate_names_actual_count; i++) {
        printf("%s%s", p->alternate_names_list[i], (i < p->alternate_names_actual_count - 1) ? ", " : "");
    }
    printf("} ## ");
    printf("%s ## ", p->house);
    printf("%s ## ", p->ancestry);
    printf("%s ## ", p->species);
    printf("%s ## ", p->patronus);
    printf("%s ## ", p->hogwartsStaff ? "VERDADEIRO" : "FALSO");
    printf("%s ## ", p->hogwartsStudent ? "VERDADEIRO" : "FALSO");
    printf("%s ## ", p->actorName);
    printf("%s ## ", p->alive ? "VERDADEIRO" : "FALSO");
    printf("{");
    for (int i = 0; i < p->alternate_actors_actual_count; i++) {
        printf("%s%s", p->alternate_actors_list[i], (i < p->alternate_actors_actual_count - 1) ? ", " : "");
    }
    printf("} ## ");
    printf("%s ## ", p->dateOfBirth);
    printf("%d ## ", p->yearOfBirth);
    printf("%s ## ", p->eyeColour);
    printf("%s ## ", p->gender);
    printf("%s ## ", p->hairColour);
    printf("%s", p->wizard ? "VERDADEIRO" : "FALSO");
    printf("]\n");
}

Personagem ClonarPersonagem(const Personagem* original) { return *original; }
void processarCampoHP(const char* token, char* buffer, size_t buffer_size) {
    if (buffer == NULL || buffer_size == 0) return;
    if (token == NULL) { buffer[0] = '\0'; return; }
    size_t token_len = strlen(token);
    if (token_len >= buffer_size) {
        strncpy(buffer, token, buffer_size - 1);
        buffer[buffer_size - 1] = '\0';
    } else {
        strcpy(buffer, token);
    }
}
bool parseBooleanHP(const char* str) {
    if (str == NULL || *str == '\0') return false;
    return (strcmp(str, "VERDADEIRO") == 0 || strcmp(str, "true") == 0);
}

void InserirListaHP(Personagem p, ListaHP* lista) {
    if (lista->size >= lista->maxSize) { return; }
    lista->array[lista->size++] = ClonarPersonagem(&p);
}
void CloseListaHP(ListaHP* lista) {
    if (lista->array != NULL) { free(lista->array); lista->array = NULL; }
    lista->size = 0; lista->maxSize = 0;
}
void MostrarListaHP(const ListaHP* lista) {
    for (int i = 0; i < lista->size; i++) lista->array[i].Mostrar(&lista->array[i]);
}
void MostrarParcialListaHP(int k, const ListaHP* lista) {
    for (int i = 0; i < k && i < lista->size; i++) lista->array[i].Mostrar(&lista->array[i]);
}

void ImportDataBaseHP(literal_hp filePath, ListaHP* bd_lista) {
    FILE* csv_file = fopen(filePath, "r");
    if (csv_file == NULL) {
        fprintf(stderr, "ERRO FATAL em ImportDataBaseHP: Nao foi possivel abrir o arquivo '%s'. %s\n", filePath, strerror(errno));
        return;
    }
    char header_line[HP_MAX_LINE_SIZE * 2];
    if (readStringHP(csv_file, header_line) == NULL || header_line[0] == '\0') {
         fprintf(stderr, "ERRO FATAL ImportDataBaseHP: Falha ao ler cabeçalho de '%s'.\n", filePath);
         fclose(csv_file); return;
    }
    Personagem p_temp;
    while (bd_lista->size < bd_lista->maxSize) {
        int peek_char = fgetc(csv_file);
        if (peek_char == EOF) break;
        ungetc(peek_char, csv_file);
        SplitHP campos_da_linha = newSplitHP(csv_file);
        if (campos_da_linha.array[0][0] == '\0') { 
             int eof_check = fgetc(csv_file); 
             if (eof_check == EOF) break;
             ungetc(eof_check, csv_file); 
             if (bd_lista->size > 0 && bd_lista->array[bd_lista->size -1].id[0] == '\0') break; 
             if (bd_lista->size == 0 && feof(csv_file)) break; 
             continue; 
        }
        p_temp = newPersonagem(); 
        ConstrutorPersonagem(&p_temp, campos_da_linha);
        if (strlen(p_temp.id) > 0) { 
             if (bd_lista->size < bd_lista->maxSize) {
                 bd_lista->Inserir(p_temp, bd_lista);
             } else { break; }
        } else if(feof(csv_file)){ break; }
    }
    fclose(csv_file);
}
Personagem GetPersonagemPorID_HP(const char* id_str, const ListaHP* bd_lista) {
    if (id_str == NULL) return newPersonagem();
    for (int i = 0; i < bd_lista->size; i++) {
        if (strcmp(bd_lista->array[i].id, id_str) == 0) return ClonarPersonagem(&bd_lista->array[i]);
    }
    return newPersonagem();
}
void setAtributoOrdenacaoHP(ListaHP* lista, int index_personagem_na_lista, const char* nome_campo_personagem) {
    if (lista == NULL || index_personagem_na_lista < 0 || index_personagem_na_lista >= lista->size) return;
    Personagem* p_ptr = &(lista->array[index_personagem_na_lista]);
    if (strcmp(nome_campo_personagem, "id") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->id;
    else if (strcmp(nome_campo_personagem, "name") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->name;
    else if (strcmp(nome_campo_personagem, "house") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->house;
    else if (strcmp(nome_campo_personagem, "ancestry") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->ancestry;
    else if (strcmp(nome_campo_personagem, "species") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->species;
    else if (strcmp(nome_campo_personagem, "patronus") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->patronus;
    else if (strcmp(nome_campo_personagem, "actorName") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->actorName;
    else if (strcmp(nome_campo_personagem, "dateOfBirth") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->dateOfBirth;
    else if (strcmp(nome_campo_personagem, "eyeColour") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->eyeColour;
    else if (strcmp(nome_campo_personagem, "gender") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->gender;
    else if (strcmp(nome_campo_personagem, "hairColour") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->hairColour;
    else if (strcmp(nome_campo_personagem, "yearOfBirth") == 0) p_ptr->atributo_ordenacao = (void*)&p_ptr->yearOfBirth;
    else if (strcmp(nome_campo_personagem, "hogwartsStaff") == 0) p_ptr->atributo_ordenacao = (void*)&p_ptr->hogwartsStaff;
    else if (strcmp(nome_campo_personagem, "hogwartsStudent") == 0) p_ptr->atributo_ordenacao = (void*)&p_ptr->hogwartsStudent;
    else if (strcmp(nome_campo_personagem, "alive") == 0) p_ptr->atributo_ordenacao = (void*)&p_ptr->alive;
    else if (strcmp(nome_campo_personagem, "wizard") == 0) p_ptr->atributo_ordenacao = (void*)&p_ptr->wizard;
    else { p_ptr->atributo_ordenacao = (void*)p_ptr->name; }
}

bool CompareHP_IntAttr_Then_Name(Personagem p1, Personagem p2, LogHP* log) {
    if (log) log->comparacoes++;
    if (p1.atributo_ordenacao == NULL || p2.atributo_ordenacao == NULL) return false; 
    int val1 = *((int*)p1.atributo_ordenacao);
    int val2 = *((int*)p2.atributo_ordenacao);
    if (val1 != val2) return val1 > val2;
    if (log) log->comparacoes++;
    return strcmp(p1.name, p2.name) > 0;
}
int CompareHP_StrAttr_Then_Name(Personagem p1, Personagem p2, LogHP* log) {
    if (log) log->comparacoes++;
    if (p1.atributo_ordenacao == NULL || p2.atributo_ordenacao == NULL) return 0;
    int cmp = strcmp((const char*)p1.atributo_ordenacao, (const char*)p2.atributo_ordenacao);
    if (cmp != 0) return cmp;
    if (log) log->comparacoes++;
    return strcmp(p1.name, p2.name);
}
bool CompareHP_BoolAttr_Then_Name(Personagem p1, Personagem p2, LogHP* log) {
    if (log) log->comparacoes++;
    if (p1.atributo_ordenacao == NULL || p2.atributo_ordenacao == NULL) return false; 
    bool val1 = *((bool*)p1.atributo_ordenacao);
    bool val2 = *((bool*)p2.atributo_ordenacao);
    if (val1 != val2) return val1; 
    if (log) log->comparacoes++;
    return strcmp(p1.name, p2.name) > 0;
}
bool parseDateHP_for_compare(const char* dateStr, int* year, int* month, int* day) {
    if (dateStr == NULL || strlen(dateStr) < 8 ) return false;
    int d_temp=0, m_temp=0, y_temp=0;
    if (sscanf(dateStr, "%d-%d-%d", &d_temp, &m_temp, &y_temp) == 3) {
        if (d_temp >= 0 && d_temp <= 31 && m_temp >= 0 && m_temp <= 12) {
            *day = d_temp; *month = m_temp; *year = y_temp;
            return true;
        }
    }
    return false;
}
int CompareHP_DateStr_Then_Name(Personagem p1, Personagem p2, LogHP* log) {
    if (log) log->comparacoes++;
    if (p1.atributo_ordenacao == NULL || p2.atributo_ordenacao == NULL) return 0;
    const char* dateStr1 = (const char*)p1.atributo_ordenacao;
    const char* dateStr2 = (const char*)p2.atributo_ordenacao;
    int y1=0, m1=0, d1=0, y2=0, m2=0, d2=0;
    bool valid1 = parseDateHP_for_compare(dateStr1, &y1, &m1, &d1);
    bool valid2 = parseDateHP_for_compare(dateStr2, &y2, &m2, &d2);
    if (!valid1 && !valid2) { /*ambas inválidas*/ }
    else if (!valid1) return -1; 
    else if (!valid2) return 1;  
    else { 
        if (y1 != y2) return y1 < y2 ? -1 : 1;
        if (m1 != m2) return m1 < m2 ? -1 : 1;
        if (d1 != d2) return d1 < d2 ? -1 : 1;
    }
    if (log) log->comparacoes++;
    return strcmp(p1.name, p2.name);
}

ListaHP newListaHP(size_t maxSize) {
    ListaHP lista;
    lista.maxSize = (maxSize > 0) ? maxSize : HP_MAX_CHARACTERS;
    lista.size = 0;
    lista.array = (Personagem*)malloc(lista.maxSize * sizeof(Personagem));
    if (lista.array == NULL && lista.maxSize > 0) {
        perror("Erro Crítico LibHP: Falha ao alocar memória para array de Personagens em newListaHP");
        exit(EXIT_FAILURE);
    }
    lista.Inserir = InserirListaHP;
    lista.ImportDataBase = ImportDataBaseHP;
    lista.GetPorID = GetPersonagemPorID_HP;
    lista.Mostrar = MostrarListaHP;
    lista.MostrarParcial = MostrarParcialListaHP;
    lista.Close = CloseListaHP;
    lista.setAtributoOrdenacao = setAtributoOrdenacaoHP;
    lista.CompareToInt = CompareHP_IntAttr_Then_Name;
    lista.CompareToStr = CompareHP_StrAttr_Then_Name;
    lista.CompareToBool = CompareHP_BoolAttr_Then_Name;
    lista.CompareToDateStr = CompareHP_DateStr_Then_Name;
    return lista;
}

void swapHP(Personagem* a, Personagem* b, LogHP* log) {
    Personagem temp = *a;
    *a = *b;
    *b = temp;
    if(log) log->movimentacoes += 3;
}

#endif // LIB_HP_H