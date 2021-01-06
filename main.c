#include <stdio.h>

#define SIZE 5

int binarySearch(int *v, int key, int low, int high);
int binarySearchRecursive(int *v, int key, int low, int high);
int linearSearch(int *v, int key, int size);
int linearSearchRecursive(int *v, int key, int size);
int minRecursive(int *v, int size);
void bubbleSort(int v[], int size);
void bubbleSortRecursive(int *v, int size);
void printArray(int *v, int size);

int main(void)
{

    int x[] = {48, 24, 96, 12, 192};

    bubbleSortRecursive(x, SIZE);

    //bubbleSort(x, SIZE); // ordina array
    
    printArray(x, SIZE); // stampa array ordinato

    puts("");

    printf("Ricerca binaria di 24: posizione %d\n", binarySearch(x, 24, 0, SIZE - 1));
    printf("Ricerca binaria ricorsiva di 24: posizione %d\n", binarySearchRecursive(x, 24, 0, SIZE - 1));
    printf("Ricerca lineare di 48: posizione %d\n", linearSearch(x, 48, SIZE - 1));
    printf("Ricerca lineare ricorsiva di 48 : posizione %d\n", linearSearch(x, 48, SIZE - 1));
    printf("Elemento minimo array: %d ", minRecursive(x, SIZE - 1));
}

int binarySearch(int *v, int key, int low, int high)
{

    while (low <= high)
    {
        int middle = (low + high) / 2;

        if (key == v[middle])
            return middle;

        else if (key < v[middle])
            high = middle - 1;

        else
            low = middle + 1;
    }

    return -1;
}

int binarySearchRecursive(int *v, int key, int low, int high)
{
    if (low <= high)
    {

        int middle = (low + high) / 2;

        if (v[middle] == key) // caso base
            return middle;

        /*Passi ricorsivi*/

        if (key < v[middle])
            return binarySearchRecursive(v, key, low, middle - 1);

        if (key > v[middle])
            return binarySearchRecursive(v, key, middle + 1, high);
    }
    else
    {
        return -1;
    }
}

int minRecursive(int *v, int size)
{
    size--;

    if (size == 0) // caso base
        return v[0];

    else if (minRecursive(v, size) < v[size]) // passo ricorsivo
    {
        return minRecursive(v, size);
    }
}

int linearSearch(int *v, int key, int size)
{
    for (int i = 0; i < size; i++)
        if (v[i] == key)
            return i;
}

int linearSearchRecursive(int *v, int key, int size)
{
    size--;

    if (v[size] == key) // caso base
        return size;
    else // passo ricorsivo
        return linearSearchRecursive(v, key, size);
}

void bubbleSort(int v[], int size)
{
    int scambio = 1; // true
    while (scambio == 1)
    {
        scambio = 0;

        for (int i = 0; i < size - 1; i++)
        {
            if (v[i] > v[i + 1]) // ordinamento crescente
            {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                scambio = 1;
            }
        }

        size--;
    }
}

void bubbleSortRecursive(int *v, int size)
{
    size--;

    if (size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        if (v[i] > v[i + 1]) // ordinamento crescente
        {
            int temp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp;
        }
    }

    return bubbleSortRecursive(v, size);
}

void printArray(int *v, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\n", v[i]);
}
