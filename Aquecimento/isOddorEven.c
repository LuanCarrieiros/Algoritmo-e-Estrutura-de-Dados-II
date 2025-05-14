#include <stdio.h>
#include <stdbool.h>

bool isOdd(int number)
{
    return (number % 2 != 0); // retorna true se for impar, false se for par
}

int main()
{
    int number;
    bool control = true;

    scanf("%d", &number);
    getchar();
    while (control)
    {
        if (isOdd(number != 0))
        {
            isOdd(number) ? printf("I\n") : printf("P\n");
            scanf("%d", &number);
            getchar();
        } else
        {
            control = false;
        }
    }

    return 0;
}