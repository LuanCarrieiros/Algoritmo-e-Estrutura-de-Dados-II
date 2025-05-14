#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para remover texto dentro de colchetes '[' e ']'
char* removeColchete(char* text)
{
    int size = strlen(text); // Calcula o tamanho do texto
    int j = 0; // Variável para controlar a posição no novo texto
    char* newText = (char*)calloc(size, sizeof(char)); // Aloca memória para o novo texto
    
    for (int i = 0; i < size; i++) // Loop para percorrer o texto
    {
        
        if (text[i] == '[') // Se encontrar um colchete aberto '['
        {
            
            while (text[++i] != ']' && text[i] != '[') // Enquanto não encontrar o colchete fechado ']' ou um novo colchete aberto '['
            {
                newText[j++] = text[i]; // Copia o texto para o novo texto, ignorando os colchetes
            }
            i++; // Avança para o próximo caractere após o colchete fechado ']'
        }
    }

    for (int i = 0; i < size; i++) // Loop para percorrer o texto novamente e copiar os caracteres que não estão entre colchetes
    {
        if (text[i] == '[' || text[i] == ']') // Se encontrar um colchete '[' ou ']'
        {
            while (text[i] != ']') // Enquanto não encontrar o colchete fechado ']'
            {
                i++; // Avança para o próximo caractere
            }
        }
        else
        {
            newText[j++] = text[i]; // Copia o texto para o novo texto
        }
    }

    return newText; // Retorna o novo texto sem os caracteres dentro dos colchetes
}

int main()
{
    char text[100000]; // Declaração de uma string para armazenar o texto
    
    while (scanf("%s", text) != EOF) // Loop para ler o texto enquanto não atingir o final do arquivo (EOF)
    {
        printf("%s\n", removeColchete(text)); // Chama a função para remover os colchetes e imprime o resultado
    }

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
