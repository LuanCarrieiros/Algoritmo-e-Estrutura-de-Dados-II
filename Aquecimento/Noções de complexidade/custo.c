#include <stdio.h>
/*
 * Instruçoes de entendimento:
 * O count representa o número de operaçoes que o problema pede, entao se ele quer 3n, eu fiz como count + 3, nao está executando 3x, mas a resposta será o número que o problema pede, que seriam 3 subtraçoes, logo, count + 3.
 * nem tenta rodar, mesmo com N = 1 vai demorar
 */ 

// 3n + 2n^2
int Custo1(int n)
{
    int i = 0, j = 0;
    int count = 0;
    while (i < n)
    {
        count = count + 3;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            count = count + 2;
        }
    }

    return count;
}

// 5n + 4n^3
int Custo2(int n)
{
    int i = 0, j = 0, z = 0;
    int count = 0;
    while (i < n)
    {
        count = count + 5;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (z = 0; z < n; z++)
            {
                count = count + 4;
            }
        }
    }

    return count;
}

// log(n) + n
int Custo3(int n)
{
    int i = 0;
    int count = 0;
    while ((n - 1) > 0)
    {
        n = n / 2;
        count = count + 1;
    }

    for (i = 0; i < n; i++)
    {
        count = count + 1;
    }
    
    return count;
}

// 2n^3 + 5
int Custo4(int n)
{
    int i = 0, j = 0, z = 0;
    int count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (z = 0; z < n; z++)
            {
                count = count + 2;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        count++;
    }

    return count;
}

// 9n^4 + 5n^2 + n/2
int Custo5(int n)
{
    int i = 0, j = 0, z = 0, v = 0;
    int count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (z = 0; z < n; z++)
            {
                for (v = 0; v < n; v++)
                {
                    count = count + 9;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (v = 0; v < n; v++)
        {
            count = count + 5;
        }
    }

    for (i = 0; i < n / 2; i++)
    {
        count++;
    }

    return count;
}

// log(n) + 5 lg(n)
int Custo6(int n)
{
    int i = 0, temp;
    int count = 0;
    while ((n - 1) > 0)
    {
        n = n / 2;
        count++;
    }

    for (i = 0; i < 5; i++)
    {
        temp = n;
        while ((temp - 1) > 0)
        {
            temp = temp / 2;
            count++;
        }
    }

    return count;
}

int main()
{

    int n;
    scanf("%d", &n);
    printf("n: %d\n", n);
    printf("Custo do método 3n + 2n^2: %d\n", Custo1(n));
    printf("Custo do método 5n + 4n^3: %d\n", Custo2(n));
    printf("Custo do metodo lg(n) + n: %d\n", Custo3(n));
    printf("Custo do método 2n^3 + 5: %d\n", Custo4(n));
    printf("Custo do método 2n^4 + 2n^2 + n/2: %d\n", Custo5(n));
    printf("Custo do método lg(n) + 5lg(n): %d\n", Custo6(n));
    return 0;
}
