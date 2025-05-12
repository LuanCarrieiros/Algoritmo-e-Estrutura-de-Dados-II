#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// funcao para escrever no arquivo
void fileWrite(char *FileName, int size)
{
    // declaracoes
    FILE *Arq = fopen(FileName, "wb");

    float reais;

    // Verificando se o arquivo foi aberto corretamente
    if (Arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Entrada dos números e escrita no arquivo
    for (int i = 0; i < size; i++)
    {
        scanf("%f", &reais);
        fwrite(&reais, sizeof(float), 1, Arq);
    }
    fclose(Arq);
}
// funcao para remover os zeros desnecessários

char *printFormattedFloat(char *str)
{
    int len = strlen(str);
    int i = len - 1;

    // Percorre a string a partir do final para encontrar o primeiro caractere diferente de '0'
    while (i >= 0 && str[i] == '0') {
        i--;
    }

    // Se encontramos um ponto decimal antes dos zeros, também removemos o ponto
    if (str[i] == '.') {
        i--;
    }

    // Definimos o próximo caractere após o último zero encontrado como terminador de string
    str[i + 1] = '\0';

    return str;
}

void fileRead(char *FileName, int size)
{
    // declarações
    FILE *Arq = fopen(FileName, "rb");
    float numero;

    // Verificando se o arquivo foi aberto corretamente
    if (Arq == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    
    fseek(Arq, 0, SEEK_END);  // Movendo o cursor para o final do arquivo
    long int fileSize = ftell(Arq);                    // Obtendo o tamanho do arquivo em bytes
    long int lastNumberPos = fileSize - sizeof(float); // Posição do último número

    char buffer[20]; // Buffer para armazenar temporariamente a string formatada, a fim de evitar os zeros extras


    // Lendo os números do arquivo na ordem inversa
    for (int i = size - 1; i >= 0; i--)
    {
        fseek(Arq, lastNumberPos, SEEK_SET);   // Posicionando o cursor no último número
        fread(&numero, sizeof(float), 1, Arq); // Lendo o número do arquivo

        // Formatar o número com no máximo 3 casas decimais
        snprintf(buffer, sizeof(buffer), "%.3f", numero);  // funcao para formatar uma sequência de caracteres e armazená-la em um buffer

        // Imprimir o número formatado
        printf("%s\n", printFormattedFloat(buffer));

        lastNumberPos -= sizeof(float); // Movendo para o próximo número
    }

    fclose(Arq); // Fechando o arquivo após a leitura
}

int main()
{
    // abrindo o arquivo e declarando as variaveis
    char *FileName = "Questao09.txt";
    int size;

    // leitura do numero de numeros que serao lidos
    scanf("%d", &size);
    fileWrite(FileName, size);
    fileRead(FileName, size);

    return 0;
}