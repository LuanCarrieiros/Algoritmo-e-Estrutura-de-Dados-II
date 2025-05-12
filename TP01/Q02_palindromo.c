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


bool isPalindrome (char *text)
{
    int size = strlen(text);

    for (int index = 0; index < size / 2; index++)
    {
        if(text[index] != text[size - index - 1]) // se a posicao index for diferente do tamanho - index - 1, o laço contato termina e retorna falso
        {
            return false;
        }
    }

    return true;
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
        if(isPalindrome(str))
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