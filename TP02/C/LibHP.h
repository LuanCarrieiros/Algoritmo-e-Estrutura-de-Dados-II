#ifndef LIB_HP_H
#define LIB_HP_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h> // Para strerror em ImportDataBaseHP

// --------------------------- DEFINIÇÕES GLOBAIS E UTILITÁRIAS (Harry Potter) ---------------------------

#define HP_MAX_CHARACTERS 405
#define HP_FILE_PATH "tmp/characters.csv"
#define HP_MAX_UUID_SIZE 37
#define HP_MAX_NAME_SIZE 30
#define HP_MAX_ALTERNATE_NAME_SIZE 35
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

// Forward declaration para LogHP
struct LogHP;
typedef struct LogHP LogHP;


char* readStringHP(FILE* stream, StringHP input_buffer) {
    if (!stream) stream = stdin;
    if (fgets(input_buffer, HP_MAX_LINE_SIZE, stream) == NULL) {
        input_buffer[0] = '\0';
        return NULL;
    }
    input_buffer[strcspn(input_buffer, "\n\r")] = '\0';
    return input_buffer;
}

// --------------------------- CLASSE SPLIT (Adaptada para Harry Potter) ---------------------------
typedef struct SplitHP {
    char array[HP_NUM_CAMPOS_CSV][HP_MAX_CAMPO_SPLIT];
} SplitHP;

SplitHP newSplitHP(FILE* csv_file) {
    SplitHP split_hp;
    char buffer_field[HP_MAX_CAMPO_SPLIT];

    for (int i = 0; i < HP_NUM_CAMPOS_CSV; i++) {
        buffer_field[0] = '\0';
        int scan_result = fscanf(csv_file, "%[^;\n]", buffer_field);
        
        if (scan_result == EOF) {
            strcpy(split_hp.array[i], "");
            for (int j = i + 1; j < HP_NUM_CAMPOS_CSV; j++) {
                strcpy(split_hp.array[j], "");
            }
            break; 
        } else if (scan_result == 0) {
            strcpy(split_hp.array[i], "");
        } else {
            strcpy(split_hp.array[i], buffer_field);
        }

        if (i < HP_NUM_CAMPOS_CSV - 1) {
            char delim_char = fgetc(csv_file);
            if (delim_char == '\n' || delim_char == EOF) {
                for (int j = i + 1; j < HP_NUM_CAMPOS_CSV; j++) {
                    strcpy(split_hp.array[j], "");
                }
                break; 
            } else if (delim_char != ';') {
                // Erro de delimitador, campo atual pode estar incompleto ou próximo campo pode ser afetado.
                // Para robustez, pode-se tentar consumir até o próximo \n ou EOF.
                // No entanto, a simples continuação já é um comportamento.
            }
        } else { 
            char end_char = fgetc(csv_file);
            if (end_char != '\n' && end_char != EOF) {
                 char temp_c;
                 while((temp_c = fgetc(csv_file)) != '\n' && temp_c != EOF);
            }
        }
    }
    return split_hp;
}


// --------------------------- CLASSE TIMER (Adaptada para Harry Potter) ---------------------------
typedef struct TimerHP {
    clock_t startTime;
    clock_t endTime;
    double totalTimeSeconds;
    void (*Start)(struct TimerHP*);
    void (*Stop)(struct TimerHP*);
    double (*GetTimeSeconds)(struct TimerHP*);
} TimerHP;

void TimerHPStart(TimerHP* timer) { timer->startTime = clock(); }
void TimerHPStop(TimerHP* timer) { timer->endTime = clock(); }
double TimerHPGetTimeSeconds(TimerHP* timer) {
    timer->totalTimeSeconds = ((double)(timer->endTime - timer->startTime)) / CLOCKS_PER_SEC;
    return timer->totalTimeSeconds;
}
TimerHP newTimerHP() {
    TimerHP timer;
    timer.Start = TimerHPStart;
    timer.Stop = TimerHPStop;
    timer.GetTimeSeconds = TimerHPGetTimeSeconds;
    timer.totalTimeSeconds = 0.0; timer.startTime = 0; timer.endTime = 0;
    return timer;
}

// --------------------------- CLASSE LOG (Adaptada para Harry Potter) ---------------------------
struct LogHP {
    int comparacoes;
    int movimentacoes;
    void (*RegistroPesquisa)(literal_hp fileName, TimerHP timer, struct LogHP log);
    void (*RegistroOrdenacao)(literal_hp fileName, TimerHP timer, struct LogHP log);
};

void RegistroPesquisaHP(literal_hp fileName, TimerHP timer, LogHP log) {
    FILE* file = fopen(fileName, "w");
    if (!file) { perror("LogHP: Erro ao abrir arquivo de log da pesquisa"); return; }
    fprintf(file, "Matricula: [SUA_MATRICULA_HP]\t"); // Substitua pela sua matrícula
    fprintf(file, "Tempo de execucao: %.6fs\t", timer.GetTimeSeconds(&timer));
    fprintf(file, "Numero de comparacoes: %d\n", log.comparacoes);
    fclose(file);
}
void RegistroOrdenacaoHP(literal_hp fileName, TimerHP timer, LogHP log) {
    FILE* file = fopen(fileName, "w");
    if (!file) { perror("LogHP: Erro ao abrir arquivo de log da ordenacao"); return; }
    fprintf(file, "Matricula: [SUA_MATRICULA_HP]\t"); // Substitua pela sua matrícula
    fprintf(file, "Tempo de execucao: %.6fs\t", timer.GetTimeSeconds(&timer));
    fprintf(file, "Numero de comparacoes: %d\t", log.comparacoes);
    fprintf(file, "Numero de movimentacoes: %d\n", log.movimentacoes);
    fclose(file);
}
LogHP newLogHP() {
    LogHP log = {0, 0};
    log.RegistroPesquisa = RegistroPesquisaHP;
    log.RegistroOrdenacao = RegistroOrdenacaoHP;
    return log;
}

// --------------------------- STRUCT PERSONAGEM (Harry Potter) ---------------------------
typedef struct Personagem {
    char id[HP_MAX_UUID_SIZE];
    char name[HP_MAX_NAME_SIZE];
    char alternate_names[HP_MAX_ALTERNATE_NAME_SIZE];
    char house[HP_MAX_HOUSE_SIZE];
    char ancestry[HP_MAX_ANCESTRY_SIZE];
    char species[HP_MAX_SPECIES_SIZE];
    char patronus[HP_MAX_PATRONUS_SIZE];
    bool hogwartsStaff;
    bool hogwartsStudent;
    char actorName[HP_MAX_ACTOR_NAME_SIZE];
    bool alive;
    char alternate_actors[HP_MAX_ALTERNATE_NAME_SIZE];
    char dateOfBirth[15];
    int yearOfBirth;
    char eyeColour[HP_MAX_EYE_COLOUR_SIZE];
    char gender[HP_MAX_GENDER_SIZE];
    char hairColour[HP_MAX_HAIR_COLOUR_SIZE];
    bool wizard;
    void* atributo_ordenacao;
    void (*Mostrar)(const struct Personagem* self);
} Personagem;

// Protótipos para funções de Personagem
void MostrarPersonagem(const Personagem* p);
Personagem newPersonagem();
void ConstrutorPersonagem(Personagem* p, SplitHP campos_split);
Personagem ClonarPersonagem(const Personagem* original);
void processarCampoHP(const char* token, char* buffer, size_t buffer_size);
bool parseBooleanHP(const char* str);

void MostrarPersonagem(const Personagem* p) {
    if (p == NULL) { printf("NULL_PERSONAGEM\n"); return; }
    printf("[");
    printf("%s ## ", p->id);
    printf("%s ## ", p->name);
    char formatted_alternate_names[HP_MAX_ALTERNATE_NAME_SIZE * 2 + 3] = "{}"; // +3 for '{', '}' and '\0'
    if (p->alternate_names[0] != '\0' && strcmp(p->alternate_names, "[]") != 0) {
        int j = 0; formatted_alternate_names[j++] = '{';
        for (int i = 0; p->alternate_names[i] != '\0' && j < (int)sizeof(formatted_alternate_names) - 2; i++) {
            if (p->alternate_names[i] == '[' || p->alternate_names[i] == ']' || p->alternate_names[i] == '\'') continue;
            formatted_alternate_names[j++] = p->alternate_names[i];
        }
        // Remove trailing comma and space if present
        if (j > 1 && formatted_alternate_names[j-1] == ' ') j--;
        if (j > 1 && formatted_alternate_names[j-1] == ',') j--;
        
        formatted_alternate_names[j++] = '}'; formatted_alternate_names[j] = '\0';
    }
    printf("%s ## ", formatted_alternate_names);
    printf("%s ## ", p->house);
    printf("%s ## ", p->ancestry);
    printf("%s ## ", p->species);
    printf("%s ## ", p->patronus);
    printf("%s ## ", p->hogwartsStaff ? "VERDADEIRO" : "FALSO");
    printf("%s ## ", p->hogwartsStudent ? "VERDADEIRO" : "FALSO");
    printf("%s ## ", p->actorName);
    printf("%s ## ", p->alive ? "VERDADEIRO" : "FALSO");
    char formatted_alternate_actors[HP_MAX_ALTERNATE_NAME_SIZE * 2 + 3] = "{}";
    if (p->alternate_actors[0] != '\0' && strcmp(p->alternate_actors, "[]") != 0) {
        int j = 0; formatted_alternate_actors[j++] = '{';
        for (int i = 0; p->alternate_actors[i] != '\0' && j < (int)sizeof(formatted_alternate_actors) - 2; i++) {
            if (p->alternate_actors[i] == '[' || p->alternate_actors[i] == ']' || p->alternate_actors[i] == '\'') continue;
            formatted_alternate_actors[j++] = p->alternate_actors[i];
        }
        if (j > 1 && formatted_alternate_actors[j-1] == ' ') j--;
        if (j > 1 && formatted_alternate_actors[j-1] == ',') j--;
        formatted_alternate_actors[j++] = '}'; formatted_alternate_actors[j] = '\0';
    }
    printf("%s ## ", formatted_alternate_actors);
    printf("%s ## ", p->dateOfBirth);
    printf("%d ## ", p->yearOfBirth);
    printf("%s ## ", p->eyeColour);
    printf("%s ## ", p->gender);
    printf("%s ## ", p->hairColour);
    printf("%s", p->wizard ? "VERDADEIRO" : "FALSO");
    printf("]\n");
}

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
    // Aceita "VERDADEIRO" (maiúsculas) ou "true" (minúsculas, comum em alguns CSVs)
    return (strcmp(str, "VERDADEIRO") == 0 || strcmp(str, "true") == 0);
}

void ConstrutorPersonagem(Personagem* p, SplitHP campos_split) {
    processarCampoHP(campos_split.array[0], p->id, sizeof(p->id));
    processarCampoHP(campos_split.array[1], p->name, sizeof(p->name));
    processarCampoHP(campos_split.array[2], p->alternate_names, sizeof(p->alternate_names));
    processarCampoHP(campos_split.array[3], p->house, sizeof(p->house));
    processarCampoHP(campos_split.array[4], p->ancestry, sizeof(p->ancestry));
    processarCampoHP(campos_split.array[5], p->species, sizeof(p->species));
    processarCampoHP(campos_split.array[6], p->patronus, sizeof(p->patronus));
    p->hogwartsStaff = parseBooleanHP(campos_split.array[7]);
    p->hogwartsStudent = parseBooleanHP(campos_split.array[8]);
    processarCampoHP(campos_split.array[9], p->actorName, sizeof(p->actorName));
    p->alive = parseBooleanHP(campos_split.array[10]);
    processarCampoHP(campos_split.array[11], p->alternate_actors, sizeof(p->alternate_actors));
    processarCampoHP(campos_split.array[12], p->dateOfBirth, sizeof(p->dateOfBirth));
    if (campos_split.array[13][0] == '\0') {
        p->yearOfBirth = 0;
    } else {
        char* endptr;
        p->yearOfBirth = (int)strtol(campos_split.array[13], &endptr, 10);
        if (campos_split.array[13] == endptr || *endptr != '\0') {
            p->yearOfBirth = 0; 
        }
    }
    processarCampoHP(campos_split.array[14], p->eyeColour, sizeof(p->eyeColour));
    processarCampoHP(campos_split.array[15], p->gender, sizeof(p->gender));
    processarCampoHP(campos_split.array[16], p->hairColour, sizeof(p->hairColour));
    p->wizard = parseBooleanHP(campos_split.array[17]);
    p->atributo_ordenacao = NULL;
}

Personagem newPersonagem() {
    Personagem p;
    memset(&p, 0, sizeof(Personagem));
    p.Mostrar = MostrarPersonagem;
    return p;
}

Personagem ClonarPersonagem(const Personagem* original) {
    return *original;
}

// --------------------------- CLASSE LISTA (Adaptada para Personagem) ---------------------------
struct ListaHP; // Já declarado antecipadamente
typedef struct ListaHP ListaHP;

// Protótipos para funções de "métodos" da ListaHP (já declarados antes da struct ListaHP)

struct ListaHP {
    Personagem* array;
    int maxSize;
    int size;
    void (*Inserir)(Personagem p, struct ListaHP* lista);
    void (*ImportDataBase)(literal_hp filePath, struct ListaHP* bd_lista);
    Personagem (*GetPorID)(const char* id_str, const struct ListaHP* bd_lista);
    void (*setAtributoOrdenacao)(struct ListaHP* lista, int index_personagem, const char* nome_campo_personagem);
    bool (*CompareToInt)(Personagem p1, Personagem p2, struct LogHP* log);
    int  (*CompareToStr)(Personagem p1, Personagem p2, struct LogHP* log);
    bool (*CompareToBool)(Personagem p1, Personagem p2, struct LogHP* log);
    int  (*CompareToDateStr)(Personagem p1, Personagem p2, struct LogHP* log);
    void (*Mostrar)(const struct ListaHP* lista);
    void (*MostrarParcial)(int k, const struct ListaHP* lista);
    void (*Close)(struct ListaHP* lista);
};

void InserirListaHP(Personagem p, ListaHP* lista) {
    if (lista->size >= lista->maxSize) {
        //fprintf(stderr, "Erro ListaHP: Lista cheia (size: %d, maxSize: %d). Não foi possível inserir.\n", lista->size, lista->maxSize);
        return;
    }
    lista->array[lista->size++] = ClonarPersonagem(&p);
}

void CloseListaHP(ListaHP* lista) {
    if (lista->array != NULL) {
        free(lista->array);
        lista->array = NULL;
    }
    lista->size = 0;
    lista->maxSize = 0;
}

void MostrarListaHP(const ListaHP* lista) {
    for (int i = 0; i < lista->size; i++) {
        lista->array[i].Mostrar(&lista->array[i]);
    }
}

void MostrarParcialListaHP(int k, const ListaHP* lista) {
    for (int i = 0; i < k && i < lista->size; i++) {
        lista->array[i].Mostrar(&lista->array[i]);
    }
}

void ImportDataBaseHP(literal_hp filePath, ListaHP* bd_lista) {
    FILE* csv_file;
    csv_file = fopen(filePath, "r");

    if (csv_file == NULL) {
        fprintf(stderr, "ERRO FATAL em ImportDataBaseHP: Nao foi possivel abrir o arquivo '%s'.\n", filePath);
        perror("Motivo do erro de fopen");
        return;
    }

    char header_line[HP_MAX_LINE_SIZE * 2];
    if (readStringHP(csv_file, header_line) == NULL || header_line[0] == '\0') {
         fprintf(stderr, "ERRO FATAL ImportDataBaseHP: Falha ao ler o cabeçalho do CSV '%s' ou arquivo/cabeçalho vazio.\n", filePath);
         fclose(csv_file);
         return;
    }
    
    Personagem p_temp;
    
    while (bd_lista->size < bd_lista->maxSize) {
        int next_char_peek = fgetc(csv_file);
        if (next_char_peek == EOF) {
            break; 
        }
        ungetc(next_char_peek, csv_file); 

        SplitHP campos_da_linha = newSplitHP(csv_file);

        if (campos_da_linha.array[0][0] == '\0') {
             int eof_check_after_empty_id = fgetc(csv_file);
             if (eof_check_after_empty_id == EOF) {
                break;
             } else {
                ungetc(eof_check_after_empty_id, csv_file);
                // Se não for EOF, pode ser uma linha em branco, newSplitHP deveria ter avançado
                // o ponteiro do arquivo ao consumir o \n.
                // Se o ID é vazio, mas não é EOF, pode ser uma linha em branco ou erro.
                // Para evitar loop infinito em algumas formatações de CSV ruins no final,
                // se o ID for vazio e não for o primeiro personagem sendo lido (size>0)
                // E o ID do último personagem lido também foi vazio, então pare.
                if (bd_lista->size > 0 && bd_lista->array[bd_lista->size -1].id[0] == '\0') {
                    break; 
                }
                // Se for a primeira tentativa de leitura e o ID está vazio, pode ser o fim.
                if (bd_lista->size == 0 && feof(csv_file)) break; // Verificação adicional
             }
        }
        
        p_temp = newPersonagem(); 
        ConstrutorPersonagem(&p_temp, campos_da_linha);
        
        // Só insere se o ID não for vazio, para evitar personagens "fantasmas" de linhas malformadas
        // ou do final do arquivo.
        if (strlen(p_temp.id) > 0) {
             if (bd_lista->size < bd_lista->maxSize) {
                 bd_lista->Inserir(p_temp, bd_lista);
             } else {
                 break; 
             }
        } else {
            // Se o ID está vazio E já estamos no final do arquivo, paramos.
            if(feof(csv_file)) break;
            // Se ID vazio mas não EOF, pode ser uma linha em branco, newSplitHP deveria ter consumido o \n.
            // O loop while continuará e o peek com fgetc tentará ler o próximo char.
        }
    }
    fclose(csv_file);
}

Personagem GetPersonagemPorID_HP(const char* id_str, const ListaHP* bd_lista) {
    if (id_str == NULL) return newPersonagem();
    for (int i = 0; i < bd_lista->size; i++) {
        if (strcmp(bd_lista->array[i].id, id_str) == 0) {
            return ClonarPersonagem(&bd_lista->array[i]);
        }
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
    else if (strcmp(nome_campo_personagem, "alternate_names") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->alternate_names;
    else if (strcmp(nome_campo_personagem, "alternate_actors") == 0) p_ptr->atributo_ordenacao = (void*)p_ptr->alternate_actors;
    else { p_ptr->atributo_ordenacao = (void*)p_ptr->name; }
}

bool CompareHP_IntAttr_Then_Name(const Personagem p1, const Personagem p2, LogHP* log) {
    if (log) log->comparacoes++;
    if (p1.atributo_ordenacao == NULL || p2.atributo_ordenacao == NULL) return false; 
    int val1 = *((int*)p1.atributo_ordenacao);
    int val2 = *((int*)p2.atributo_ordenacao);
    if (val1 != val2) return val1 > val2;
    if (log) log->comparacoes++;
    return strcmp(p1.name, p2.name) > 0;
}

int CompareHP_StrAttr_Then_Name(const Personagem p1, const Personagem p2, LogHP* log) {
    if (log) log->comparacoes++;
    if (p1.atributo_ordenacao == NULL || p2.atributo_ordenacao == NULL) return 0;
    int cmp = strcmp((const char*)p1.atributo_ordenacao, (const char*)p2.atributo_ordenacao);
    if (cmp != 0) return cmp;
    if (log) log->comparacoes++;
    return strcmp(p1.name, p2.name);
}

bool CompareHP_BoolAttr_Then_Name(const Personagem p1, const Personagem p2, LogHP* log) {
    if (log) log->comparacoes++;
    if (p1.atributo_ordenacao == NULL || p2.atributo_ordenacao == NULL) return false; 
    bool val1 = *((bool*)p1.atributo_ordenacao);
    bool val2 = *((bool*)p2.atributo_ordenacao);
    if (val1 != val2) return val1; // true (1) > false (0)
    if (log) log->comparacoes++;
    return strcmp(p1.name, p2.name) > 0;
}

bool parseDateHP_for_compare(const char* dateStr, int* year, int* month, int* day) {
    if (dateStr == NULL || strlen(dateStr) < 8) return false; // Formato DD-MM-AAAA requer pelo menos 8, ex: 1-1-1990
    
    // Tenta parsear. sscanf é mais seguro para formatos específicos.
    int d_temp=0, m_temp=0, y_temp=0;
    if (sscanf(dateStr, "%d-%d-%d", &d_temp, &m_temp, &y_temp) == 3) {
        // Verifica se os valores são minimamente razoáveis (ex: dia/mês > 0)
        // Esta não é uma validação de data completa, mas ajuda a filtrar lixo.
        if (d_temp > 0 && d_temp <= 31 && m_temp > 0 && m_temp <= 12) {
            *day = d_temp;
            *month = m_temp;
            *year = y_temp;
            return true;
        }
    }
    return false; // Falha no parse ou valores não razoáveis
}

int CompareHP_DateStr_Then_Name(const Personagem p1, const Personagem p2, LogHP* log) {
    if (log) log->comparacoes++;
    if (p1.atributo_ordenacao == NULL || p2.atributo_ordenacao == NULL) return 0;

    const char* dateStr1 = (const char*)p1.atributo_ordenacao;
    const char* dateStr2 = (const char*)p2.atributo_ordenacao;

    int y1=0, m1=0, d1=0, y2=0, m2=0, d2=0; // Inicializa com 0
    bool valid1 = parseDateHP_for_compare(dateStr1, &y1, &m1, &d1);
    bool valid2 = parseDateHP_for_compare(dateStr2, &y2, &m2, &d2);

    if (!valid1 && !valid2) { /* Ambas inválidas, compara por nome */ }
    else if (!valid1) return -1; // Inválidas primeiro
    else if (!valid2) return 1;  // Válidas depois
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