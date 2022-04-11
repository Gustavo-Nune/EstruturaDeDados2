#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RandomInteger(int low, int high)
{
    int k;
    k = (rand() % high) + low;
    return k;
}
// Faz atroca de posição em um vetor
void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
// Gera um vetor
void geraVetor(int *V, int tam, char tipoVetor)
{

    int i, auxD = 0;
    // Define o tipo de vetor a ser criado
    switch (tipoVetor)
    {
    case 'c': // gera o vetor de forma crescente
        for (i = 0; i < tam; i++)
        {
            V[i] = i + 1;
        }

        break;
    case 'd': // gera o vetor de forma decrescente
        for (i = tam; i > 0; i--)
        {
            V[auxD] = i;
            auxD++;
        }

        break;
    case 'r': // gera o vetor de forma randomica

        for (i = 0; i < tam; i++)
        {
            V[i] = RandomInteger(0, 3200);
        }
        break;

    default:
        break;
    }
}
// imprime o vetor organizado com o tempo
void imprimeTimeVetor(int *v, int tam, clock_t t)
{
    
     for (int i = 0; i < 5; i++)
     {
         printf("[%d] ", v[i]);
     }
    printf("Tempo de execucao: %lf", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
}

int particiona(int *V,int inicio, int fim){
    int esq,dir,pivo,aux;
    esq = inicio;
    dir = fim;
    pivo = V[inicio];

    while (esq < dir)
    {
        while(V[esq] <= pivo){
            esq++;
        }
        while(V[dir] > pivo){
            dir--;
        }
        if (esq < dir)
        {
            troca(&V[esq],&V[dir]);
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;

}

void quickSort(int *V, int inicio, int fim){
    int pivo;
    if (fim > inicio)
    {
        pivo = particiona(V,inicio,fim);
        quickSort(V,inicio,pivo-1);
        quickSort(V,pivo+1,fim);
     }
    
}

int main()
{
    int vetor[5] = {5, 9, 3, 7, 1};
    int i, n, auxD = 0;
    char tipoVetor;
    clock_t t;

    printf("Vetor desorganizado : \n");
    for (i = 0; i < 5; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");

    // quickSort
    printf("InsertionSort : ");
    t = clock();
    quickSort(vetor,0,5);
    t = clock() - t;
    imprimeTimeVetor(vetor, n, t);
    printf("\n");

    return 0;
}