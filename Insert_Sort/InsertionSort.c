/*
Insertion Sort
5 9 3 7 1
1 5 9 3 7
1 3 5 9 7
1 3 5 7 9
 */
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vet, int tam)
{

    int i, j, aux;

    for (i = 0; i < tam; i++)
    {
        aux = vet[i];
        for (j = i; j > 0 && aux < vet[j - 1]; j--)
        {
            vet[j] = vet[j - 1];
        }
        vet[j] = aux;
    }
}

int main()
{
    int vetor[5] = {5, 9, 3, 7, 1};
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");

    insertionSort(vetor, 5);

    for (i = 0; i < 5; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");

    return 0;
}
