#include <stdio.h>
#include <string.h>

int countUpper(char *text)
{
    int size = strlen(text);
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            count++;
        }
    }

    return count;
}

int main ()
{
    char text[1000];
    scanf(" %[^\n]%*c", text);
    int control = 1;

    while (control)
    {
        printf("%d\n", countUpper(text));
        scanf(" %[^\n]%*c", text);
        
        if(strcmp(text, "FIM") == 0)
        {
            control = 0;
        }
        
    }
    
    return 0;
}