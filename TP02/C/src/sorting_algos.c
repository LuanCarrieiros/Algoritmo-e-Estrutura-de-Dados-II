#include "../include/sorting_algos.h"
#include "../include/common.h"
#include "../include/personagem.h"
#include "../include/utils.h" // Para equals, isBigger, isShorter, etc.

#include <string.h>

// ================================================ SWAP ================================================ //
void swap(Personagem personagens[], int i, int j)
{
    Personagem tmp = personagens[i];
    personagens[i] = personagens[j];
    personagens[j] = tmp;
}

void swap_static(StringArray array, int i, int j)
{
    String tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int desempateEye (Personagem Pivo, Personagem aux)
{
    int eye = strcmp(Pivo.eye_colour, aux.eye_colour);
    return eye != 0 ? eye : strcmp(Pivo.name, aux.name);
}

int desempateHouse (Personagem Pivo, Personagem aux, Log* log)
{
    int house = strcmp(Pivo.house, aux.house);
    log->comparacoes++;
    return house != 0 ? house : strcmp(Pivo.name, aux.name);
}

int desempateHairColour (Personagem Pivo, Personagem aux, Log* log)
{
    int hair_colour = strcmp(Pivo.hair_colour, aux.hair_colour);
    log->comparacoes++;
    return hair_colour != 0 ? hair_colour : strcmp(Pivo.name, aux.name);
}

// ======================================= BUBBLESORT ======================================= //

void bubblesort(Personagem personagens[], int size, Log *log)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            log->comparacoes++;
            if(desempateHairColour(personagens[j], personagens[j + 1], log) > 0)
            {
                swap(personagens, j, j + 1);
                log->movimentacoes+=3;
            }
        }
    }
}

// ======================================= QUICKSORT ======================================= //
void quicksort(Personagem personagens[], int left, int right, Log *log)
{
    int i = left, j = right;
    Personagem Pivo;
    Pivo = personagens[( i + j ) / 2 ];
    while (i <= j)
    {
        while(desempateHouse(personagens[i], Pivo, log) < 0)
        {
            i++;
        }

        while (desempateHouse(personagens[j], Pivo, log) > 0)
        {
            j--;
        }
        if(i <= j)
        {
            swap(personagens, i, j);
            log->movimentacoes+=3;
            i++;
            j--;
        }
    }

    if(left < j) quicksort (personagens, left, j, log);
    if(i < right) quicksort (personagens, i, right, log);
}

// ======================================= SELECTION SORT ======================================= //
void selectionsort(Personagem personagens[], int size, int currentIndex, Log* log)
{
    if(currentIndex == size - 1)
    {   // Base case: se currentIndex alcançou o último elemento, a lista está ordenada
        return;
    }

    // encontra o índice do menor elemento na sublista restante
    int minIndex = currentIndex;
    for(int i = currentIndex + 1; i < size; ++i)
    {
        log->comparacoes++;
        if(isShorter(personagens[i].name, personagens[minIndex].name)) { minIndex = i; }
    }
    log->movimentacoes+=3;
    swap(personagens, currentIndex, minIndex);
    selectionsort(personagens, size, currentIndex + 1, log);
}

// ======================================= INSERCAO POR COR ======================================= //
void insercaoPorCor(Personagem personagens[], int n, int cor, int h, Log* Log){

    for (int i = (h + cor); i < n; i+=h) {

        Personagem tmp = personagens[i];
        int j = i - h;

        while ((j >= 0) && (desempateEye(personagens[j], tmp) > 0)) {
            personagens[j + h] = personagens[j];
            j -= h;
            Log->movimentacoes++;
        }

        personagens[j + h] = tmp;
        Log->movimentacoes+=2; // A atribuição do tmp ao final da inserção também é uma movimentação
    }
}
// ========================================= SHELLSORT ========================================= //
void shellsort(Personagem personagens[], int n, Log* Log) {
    int h = 1;

    do { h = (h * 3) + 1; } while (h < n);

    do {
        h /= 3;
        for(int cor = 0; cor < h; cor++){
            insercaoPorCor(personagens, n, cor, h, Log);
        }
    } while (h != 1);
}

// ======================================= HEAPSORT ======================================= //

void buildHeap(Personagem personagens[], int root, int n, Log* log)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    log->comparacoes++;
    if(left < n && desempateHairColour(personagens[left], personagens[largest], log) > 0)
    {
        largest = left;
    }

    log->comparacoes++;
    if(right < n && desempateHairColour(personagens[right], personagens[largest], log) > 0)
    {
        largest = right;
    }

    if(largest != root)
    {
        swap(personagens, root, largest);
        log->movimentacoes+=3;
        buildHeap(personagens, largest, n, log);
    }
}

void heapsort(Personagem personagens[], int n, Log *log)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        buildHeap(personagens, i, n, log);
    }

    for(int i = n - 1; i > 0; i--)
    {
        swap(personagens, 0, i);
        log->movimentacoes+=3;
        buildHeap(personagens, 0, i, log);
    }
}