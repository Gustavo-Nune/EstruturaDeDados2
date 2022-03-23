/*
5 9 3 7 1 menor : 4 i : 0
1 9 3 7 5 menor : 2 i : 1
1 3 9 7 5 menor : 4 i : 2
1 3 5 7 9 menor : 3 i : 3
1 3 5 7 9 fim
*/
#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}

void selectionSort(int *vet, int tam)
{

    int i, j = 0, auxiliar, menor, indice = 0;

    for (i = 0; i < tam - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < tam; j++)
        {
            if (vet[j] < vet[menor])
            {
                menor = j;
            }
        }
        if (i != menor)
        {
            troca(&vet[menor], &vet[i]);
        }
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

    selectionSort(vetor, 5);

    for (i = 0; i < 5; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");

    return 0;
}
