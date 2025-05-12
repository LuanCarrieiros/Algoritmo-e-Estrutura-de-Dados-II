#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// funcao para testar se a entrada é FIM
bool isEnd(char *text)
{
    return (strlen(text) == 3
              && text[0] == 'F'
              && text[1] == 'I'
              && text[2] == 'M');
}

bool isPalindrome (char *text, int start, int end)
{
    if (start >= end)
    {
        return true; // se o start for maior ou igual a end, significa que percorremos todas as posicoes
    }

    if(text[start] != text[end]) 
    {
        return false;  // se a posicao index for diferente do tamanho - index - 1, o laço contato termina e retorna falso
    }
    // chamada da funcao para testar as proximas posicoes, que ocorre até que a primeira ou segunda estrutura condicional aconteça
    return isPalindrome(text, start + 1, end - 1);
}

int main ()
{
    // declaracao da variavel
    char str[1000];
    // leitura da entrada, ignorando espacos e lendo ate o \n
    scanf(" %[^\r\n]%*c", str);

        // laço que se repetirá enquanto a funcao isEnd retornar falso, quando retornar verdade, a entrada foi FIM e saio do laço
    while(!isEnd(str))
    {   
        // condicional para testar se o resultado foi verdadeiro ou falso
        if(isPalindrome(str, 0, strlen(str) - 1))
        {
            printf("SIM\n");
        }
        else
        {
            printf("NAO\n");
        }
        // releitura para continuar analisando novas entradas
        scanf(" %[^\r\n]%*c", str);
    }

    return 0;
}