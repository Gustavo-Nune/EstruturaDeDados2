#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int *vet , int n ){
    int i, continua, aux, fim = n;
    do
    {
        continua = 0;
        for ( i = 0; i < fim-1; i++)
        {
            if (vet[i] > vet[i+1])
            {
                troca(&vet[i],&vet[i+1]);
                continua = i;
            }
            
        }
        
    } while (continua != 0);
    
    
}

int main(){
    int vetor[5] = { 5 , 9 , 3 , 7 , 1};
    int i;

    for (i = 0; i < 5; i++)
    {
    printf("[%d] ",vetor[i]);
    }
    printf("\n");

    bubbleSort(vetor,5);

    for (i = 0; i < 5; i++)
    {
        printf("[%d] ", vetor[i]);
    }

    return 0;
}

