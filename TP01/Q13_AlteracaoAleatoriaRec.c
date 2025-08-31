#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isEnd(char *text)
{
    return (strlen(text) == 3 && text[0] == 'F' && text[1] == 'I' && text[2] == 'M');
}

// Função para trocar letras na string recursivamente
void TrocaLetraRec(char *str, char *resultado, int index, char random1, char random2)
{
    // Caso base: Se atingirmos o final da string, terminamos
    if (str[index] == '\0')
    {
        resultado[index] = '\0';
        return;
    }

    char caractere = str[index];

    if (caractere == random1)
    {
        // Troca o caractere se for igual ao random1
        resultado[index] = random2;
    }
    else 
    {
        resultado[index] = caractere;
    }

    // Continua para o próximo caractere
    TrocaLetraRec(str, resultado, index + 1, random1, random2);
}

int main()
{
    char str[1000];
    char resultado[1000];
    int count = 0;
    const int MAX_ITERATIONS = 10000; // Safeguard para evitar loop infinito
    
    if (scanf(" %[^\r\n]%*c", str) != 1) {
        return 1; // Erro na leitura
    }

    srand(4); // Seed fixo conforme enunciado
    
    // repetindo o loop enquanto a minha entrada for diferente de FIM
    while (!isEnd(str) && count < MAX_ITERATIONS)
    {   
        // Geração aleatória das letras usando seed fixa
        char random1 = 'a' + (abs(rand()) % 26);
        char random2 = 'a' + (abs(rand()) % 26);
        
        TrocaLetraRec(str, resultado, 0, random1, random2);
        printf("%s\n", resultado);
        
        if (scanf(" %[^\r\n]%*c", str) != 1) {
            break; // Erro ou EOF na leitura
        }
        count++;
    }

    return 0;
}