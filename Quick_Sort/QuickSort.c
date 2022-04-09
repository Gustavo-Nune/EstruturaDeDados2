#include <stdio.h>
#include <stdlib.h>

int RandomInteger(int low, int high)
{
    int k;
    k = (rand() % high) + low;
    return k;
}

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int Particiona(int *V, int inicio, int fim)
{
    int esq = inicio;
    int dir = fim;
    int pivo = V[inicio];

    while (esq < dir)
    {
        while(V[esq] <= pivo && esq <= fim){
            
        }
        while(V[dir] <= pivo && dir <= inicio){

        }
        if (esq < dir)
        {
            troca(V[esq],V[dir]);
        }
    troca(V[dir],V[esq]);
    
    }
    

    return (dir);
}

void quickSort(int *V, int inicio, int fim)
{

    int pivo;

    if (inicio < fim)
    {
        pivo = Particiona(V, inicio, fim);
        quickSort(V, inicio, pivo - 1);
        quickSort(V, pivo + 1, fim);
    }
}
void main()
{
}