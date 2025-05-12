#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

bool isEnd(char *text)
{
    return (strlen(text) == 3 && text[0] == 'F' && text[1] == 'I' && text[2] == 'M');
}

// Função para trocar letras na string
char* TrocaLetra(char *str, int index, char random1, char random2)
{
    // Caso base: Se atingirmos o final da string, retornamos a string modificada
    if (str[index] == '\0')
    {
        return str;
    }

    char caractere = str[index];

    if (caractere == random1)
    {
        // Troca o caractere se for igual ao random1
        str[index] = random2;
    }

    // Continua para o próximo caractere
    return TrocaLetra(str, index + 1, random1, random2);
}

int main()
{
    char str[1000];
    scanf(" %[^\r\n]%*c", str);

    
    // repetindo o loop enquanto a minha entrada for diferente de FIM, chamando minha funcao isEnd e passando a string como parametro
    while (!isEnd(str))
    {   
        srand(time(NULL)); // Semente para a função rand() baseada no tempo atual
        // Geração aleatória das letras, dentro do while, para cada nova entrada, novas letras serem geradas
        char random1 = 'a' + rand() % 26; // 'a' + um número aleatório entre 0 e 25
        char random2 = 'a' + rand() % 26; // 'a' + um número aleatório entre 0 e 25
        
        printf("%s\n", TrocaLetra(str, 0, random1, random2));
        scanf(" %[^\r\n]%*c", str);
    }

    return 0;
}