#include "../include/utils.h"
#include "../include/common.h"
#include "../include/personagem.h" // Para Personagem
#include "../include/list.h"      // Para List
#include "../include/linked_list.h" // Para ListPersonagem, addEnd, start, freeCell

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Para isspace

/* Funcao para saber se duas strings sao iguais, retorna verdadeiro caso seja
 * @param str1 primeira string
 * @param str2 segunda string
*/
bool equals(String str1, String str2)
{
    return (strcmp(str1, str2) == 0);
}

/* Funcao para saber se a primeira string é maior que a segunda, retorna verdadeiro caso seja
 * @param str1 primeira string
 * @param str2 segunda string
*/
bool isBigger(String str1, String str2)
{
    return (strcmp(str1, str2) > 0);
}

/* Funcao para saber se a primeira string é menor que a segunda, retorna verdadeiro caso seja
 * @param str1 primeira string
 * @param str2 segunda string
*/
bool isShorter(String str1, String str2)
{
    return (strcmp(str1, str2) < 0);
}

void isYes(bool value)
{
    value == true ? printf("SIM\n") : printf("NAO\n");
}

// Funcao para formatar a data para o padrao dd-mm-aaaa
void format_Date(String date)
{
    int day;
    int month;
    int year;

    sscanf(date, "%d-%d-%d", &day, &month, &year);
    sprintf(date, "%02d-%02d-%d", day, month, year);
}
// Funcao para contar a quantidade de ocorrencia de um determinado delimitador em uma string
int countDelim(char delim, String str)
{
    int size = strlen(str);
    int countDelim = 0;
    for(int i = 0; i < size; i++)
    {
        if(str[i] == delim) // Se o caractere atual for o delimitador
        {
            countDelim++; // Incrementa o contador de delimitadores
        }
    }

    return ( countDelim + 1 );
}

/* Função que divide uma string em substrings com base em um delimitador
 * @param str: string a ser dividida
  * @param delimitador: caractere que será usado para dividir a string
  * @return: matriz de strings com as substrings
*/
StringArray split(String str, char delimitador)
{
    // Cópia da string original para não modificá-la
    char *str_copy = strdup(str);
    if (str_copy == NULL) {
        fprintf(stderr, "Erro de alocação de memória para str_copy na funcao split.\n");
        exit(EXIT_FAILURE);
    }

    size_t size = countDelim(delimitador, str);
    StringArray array = (StringArray) malloc (size * sizeof(String)); // Aloca memória para a matriz

    if(array == NULL) // Verifica se houve erro na alocação de memória
    {
        fprintf(stderr, "Erro de alocação de memoria na funcao split. ALOC 1\n"); // Imprime mensagem de erro
        free(str_copy); // Liberar a cópia
        exit(EXIT_FAILURE); // Encerra o programa
    } else
    {
        char *token;
        char *rest = str_copy;
        size_t i = 0;

        while ((token = strtok_r(rest, &delimitador, &rest))) { // Usando strtok_r para reentrância
            array[i] = (String) malloc (strlen(token) + 1); // Aloca memória para cada token
            if (array[i] == NULL) {
                fprintf(stderr, "Erro de alocação de memória na funcao split. ALOC 2\n");
                // Libera o que já foi alocado antes de sair
                for (size_t k = 0; k < i; k++) {
                    free(array[k]);
                }
                free(array);
                free(str_copy);
                exit(EXIT_FAILURE);
            }
            strcpy(array[i], token);
            i++;
        }
        // Se a string termina com delimitador, strtok_r não criará um token vazio no final.
        // Se o número de delimitadores + 1 for maior que os tokens encontrados,
        // preenche com strings vazias para corresponder ao size.
        while (i < size) {
            array[i] = (String)malloc(1); // Aloca espaço para uma string vazia
            if (array[i] == NULL) {
                 fprintf(stderr, "Erro de alocação de memória na funcao split. ALOC 3\n");
                for (size_t k = 0; k < i; k++) {
                    free(array[k]);
                }
                free(array);
                free(str_copy);
                exit(EXIT_FAILURE);
            }
            array[i][0] = '\0';
            i++;
        }
    }
    free(str_copy); // Liberar a cópia da string
    return (array); // Retorna a matriz de strings
}


/* Função que substitui um caractere por outro em uma string
   @param str: string a ser tratada
   @param old: caractere a ser substituído
   @param new: novo caractere
   @return: string com o caractere substituído
*/
String replace(String str, char oldChar, char newChar)
{
    int size = strlen (str);
    String newString = (String) malloc (size + 1 * sizeof(char)); // Aloca memória para a nova string auxiliar
    if (newString == NULL) {
        fprintf(stderr, "Erro de alocação de memória para newString na funcao replace.\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;

    while (str[i] != '\0') // Enquanto não chegarmos ao final da string
    {
        if(str[i] != oldChar) // Se o caractere atual não for o caractere a ser substituído
        {
            newString[i] = str[i]; // Atribui o caractere atual para a nova string
        } else
        {
            newString[i] = newChar; // Substitui o caractere atual pelo novo caractere
        }
        i++; // Incrementa o índice
    }

    newString[i] = '\0'; // Termina a nova string com '\0'

    // Copia a nova string para a string original novamente só pra poder já dar free aqui mesmo dentro da funcao
    // Alternativamente, você pode apenas retornar newString e o chamador seria responsável por liberá-la
    strcpy(str, newString); // Copia o conteúdo de newString de volta para str

    free(newString); // Já libero a memória alocada para nova string aqui dentro mesmo
    return (str); // Retorno a original modificada
}

// Funcao para remover whitespaces do inicio e final de uma str
String trim(String str)
{
    int size = strlen(str);
    int start = 0;
    int end = size - 1;
    int i = 0;

    if (str == NULL || size == 0) return str; // Trata string nula ou vazia

    while (start < size && isspace((unsigned char)str[start])) // Enquanto o caractere inicial for um espaço
    {
        start++; // Incrementa o índice inicial
    }

    if(start == size) // Se a string for composta apenas por espaços
    {
        str[0] = '\0'; // Atribui '\0' para a string
        return (str); // Retorna uma string vazia
    }

    while (end >= start && isspace((unsigned char)str[end])) // Enquanto o caractere final for um espaço
    {
        end--;  // Decrementa o índice final
    }

    // Move os caracteres para o início da string
    for(i = 0; start <= end; i++, start++)
    {
        str[i] = str[start];
    }

    str[i] = '\0'; // Termina a string com '\0' para indicar o final da string
    return str;
}

// Funcao para remover um caractere de uma string, ou qualquer outro caractere que queira substituir por nada
void remove_char(String str, char removee)
{
    int i, j;
    for(i = 0, j = 0; str[i] != '\0'; i++)
    {
        if(str[i] != removee)
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// ======================================= CREATELIST ======================================= //
/* Recebe o nome de um arquivo como parametro e retorna uma lista de personagens
 * @param FileName: nome do arquivo
 * @return: lista de personagens
*/
ListPersonagem createList(String FileName)
{
    printf("DEBUG: Tentando abrir o arquivo: %s\n", FileName); 
    FILE *arq_file = fopen(FileName, "r");
    if (arq_file == NULL)
    {
        printf("ERRO FATAL: Nao foi possivel abrir o arquivo '%s'. Verifique o caminho e permissoes.\n", FileName); // <-- Mude esta linha para ser mais descritiva
        exit(EXIT_FAILURE);
    }
    printf("DEBUG: Arquivo '%s' aberto com sucesso.\n", FileName); 
    ListPersonagem List1;
    Personagem personagem_temp_sentinela; // Usada para o nó sentinela
    reset(&personagem_temp_sentinela); // Inicializa para evitar lixo

    start(personagem_temp_sentinela, &List1); // Cria um nó sentinela

    // --------- leitura do arquivo csv
    char line[LINE_SIZE];
    fgets(line, sizeof(line), arq_file); // Descarta o cabeçalho

    while(fgets(line, sizeof(line), arq_file) != NULL)
    {
        Personagem personagem_lida;
        reset(&personagem_lida); // Inicializa uma nova Personagem para cada linha
        read(&personagem_lida, line);
        addEnd(personagem_lida, &List1);
    }

    fclose(arq_file);
    printf("DEBUG: createList concluida. Total de personagens na lista: %d\n", getSize(&List1)); 
    return List1;
}

// ======================================= GET FRAGMETNS OF CHARACTER ======================================= //
Personagem* getFragmentsOfCharacter(ListPersonagem *List, int *size)
{
    printf("DEBUG: Entrando em getFragmentsOfCharacter para ler IDs.\n"); 
    Personagem *personagemShell = (Personagem*) malloc(27 * sizeof(Personagem));
    if (personagemShell == NULL) {
        fprintf(stderr, "Erro de alocação de memória para personagemShell.\n");
        exit(EXIT_FAILURE);
    }

    char text[LINE_SIZE]; // Use LINE_SIZE para o buffer de leitura de entrada
    
    // Leitura do primeiro ID/comando
    if (scanf(" %[^\r\n]%*c", text) != 1) {
        printf("DEBUG: scanf inicial falhou ou EOF. Retornando array vazio.\n"); 
        *size = 0; // Se não leu nada, o size é 0
        return personagemShell; // Retorna array vazio
    }

    int i = 0;
    while(!equals(text, "FIM") && i < 27)
    {
        Personagem found_personagem = getElementByID(text, List);
        if (strcmp(found_personagem.id, "NOT_FOUND") != 0) {
            personagemShell[i] = found_personagem;
            i++;
        } else {
            fprintf(stderr, "Personagem com ID '%s' nao encontrada (getFragmentsOfCharacter).\n", text); 
        }
        printf("DEBUG: Leu entrada '%s'. (Total lido: %d)\n", text, i); 
        
        // Leitura dos IDs/comandos seguintes
        if (scanf(" %[^\r\n]%*c", text) != 1) {
            if (feof(stdin) || ferror(stdin)) {
                printf("DEBUG: EOF ou erro na leitura do scanf subsequente. Encerrando leitura de IDs.\n"); 
                break; // Se for EOF ou erro, sair do loop
            }
        }
    }
    *size = i;
    printf("DEBUG: getFragmentsOfCharacter concluida. Total de IDs lidos: %d\n", *size); 
    return personagemShell;
}

StringArray fillFieldWithIds(int *size)
{
    printf("DEBUG: Entrando em fillFieldWithIds para ler IDs.\n"); 
    StringArray field = (StringArray) malloc (27 * sizeof(String));
    if (field == NULL) {
        fprintf(stderr, "Erro de alocação de memória para field em fillFieldWithIds.\n");
        exit(EXIT_FAILURE);
    }

    for (int k = 0; k < 27; k++) // Use 'k' para não conflitar com 'i' mais abaixo
    {
        field[k] = (String) malloc (FIT_SIZE * sizeof(char));
        if (field[k] == NULL) {
             fprintf(stderr, "Erro de alocação de memória para field[%d] em fillFieldWithIds.\n", k);
             for(int j = 0; j < k; j++) free(field[j]); // Use 'j' aqui
             free(field);
             exit(EXIT_FAILURE);
        }
    }

    int i = 0;
    char text[LINE_SIZE]; // Use LINE_SIZE

    if (scanf(" %[^\r\n]%*c", text) != 1) {
        printf("DEBUG: scanf inicial falhou ou EOF em fillFieldWithIds. Retornando array vazio.\n"); 
        *size = 0;
        return field;
    }

    while(!equals(text, "FIM") && i < 27)
    {
        strcpy(field[i], text);
        i++;
        printf("DEBUG: fillFieldWithIds leu entrada '%s'. (Total lido: %d)\n", text, i); 

        if (scanf(" %[^\r\n]%*c", text) != 1) {
            if (feof(stdin) || ferror(stdin)) {
                printf("DEBUG: EOF ou erro no scanf subsequente em fillFieldWithIds. Encerrando leitura.\n"); 
                break;
            }
        }
    }
    *size = i;
    printf("DEBUG: fillFieldWithIds concluida. Total de IDs lidos: %d\n", *size); 
    return field;
}

// ======================================= SHOW FRAGMENTS OF CHARACTER ======================================= //
// Funcao para exibir os fragmentos de personagens
/* @param personagemShell: vetor de personagens
 * @param size: tamanho do vetor
*/
void showFragmentsOfCharacter(Personagem *personagem, int size)
{
    for (int i = 0; i < size; i++)
    {
        print(personagem[i]);
    }
}

void showFragmentsOfCharacter_static(StringArray personagem, int size, ListPersonagem *List)
{
    Personagem p;
    for (int i = 0; i < size; i++)
    {
        p = getElementByID(personagem[i], List);
        if (strcmp(p.id, "NOT_FOUND") != 0) { // Verifica se a personagem foi realmente encontrada
            print(p);
        } else {
            fprintf(stderr, "Personagem com ID '%s' não encontrada para exibição estática.\n", personagem[i]);
        }
    }
}