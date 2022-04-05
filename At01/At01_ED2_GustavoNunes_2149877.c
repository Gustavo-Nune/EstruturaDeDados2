#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
//*************************************
//            InsertionSort
//*************************************
void insertionSort(int *vet, int tam)
{

    int i, j, aux;

    for (i = 1; i < tam; i++)
    {
        aux = vet[i];
        for (j = i; j > 0 && aux < vet[j - 1]; j--)
        {
            vet[j] = vet[j - 1];
        }
        vet[j] = aux;
    }
}
//*************************************
//            SelectionSort
//*************************************
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
//*************************************
//            BubleSort
//*************************************

void bubbleSort(int *vet, int n)
{
    int i, continua, aux, fim = n;
    do
    {
        continua = 0;
        for (i = 0; i < fim - 1; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                troca(&vet[i], &vet[i + 1]);
                continua = i;
            }
        }

    } while (continua != 0);
}
//*************************************
//            MergeSort
//*************************************

void merge(int *V, int inicio, int meio, int fim)
{
    int p1 = inicio;
    int p2 = meio + 1;
    int n, j, k, i = 0;

    int vetSize = (fim - inicio) + 1;
    int *vetAux;
    vetAux = malloc(vetSize * sizeof(int));

    while (p1 <= meio && p2 < fim)
    {
        if (V[p1] < V[p2])
        {
            vetAux[i++] = V[p1++];
        }
        if (V[p2] < V[p1])
        {
            vetAux[i++] = V[p2++];
        }

        // Se P1 > meio, sobraram elementos em P2
        if (p1 > meio)
        {
            // sobram End - p2 + 1 elementos
            n = fim - p2 + 1;
            // copia os elementos que sobraram da parte da direita (p2)
            for (j = 0; j < n; j++)
            {
                vetAux[i++] = V[p2++];
            }
        } // Senão, P2 > Fim, sobraram elementos em P1
        else
        {
            // sobram Middle - p1 + 1 elementos
            n = meio - p1 + 1;
            // copia os elementos que sobraram da parte da esquerda (p1)
            for (j = 0; j < n; j++)
            {
                vetAux[i++] = V[p1++];
            }
        }

        // copiar elementos do aux para v
        // aux e v podem ter tamanhos diferentes
        j = 0;
        k = inicio;
        while (j < vetSize)
        {
            V[k] = vetAux[j];
            j++;
            k++;
        }
    }

    free(vetAux);
}
void mergeSort(int *V, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = ((inicio + fim) / 2);
        mergeSort(V, inicio, meio);
        merge(V, inicio, meio, fim);
        mergeSort(V, meio + 1, fim);
    }
}

//*************************************
//            QuickSort
//*************************************
// IMPLEMENTAR
void quickSort(){}
//*************************************
//            HeapSort
//*************************************
// IMPLEMENTAR

//*************************************
//            Main
//*************************************

int main()
{
    int *vetor;
    int i,n ;
    char tipoVetor ;
    clock_t t;

    printf("Digite o tamanho do vetor : ");
    scanf("%d", &n);
    printf("Tipo do vetor:\nc - crescente\nd - decrescente\nr - randomico\n ");
    scanf("%s",&tipoVetor);
    tipoVetor = 'c';
    switch (tipoVetor)
    {
    case 'c'://gera o vetor de forma crescente
        for ( i = 0; i < n; i++)
        {
            vetor[i] = i ;
        }
        
        break;
    case 'd'://gera o vetor de forma decrescente
        for (i = 0; n > i; i--)
        {
            vetor[i] = i + 1;
        }

        break;
    case 'r'://gera o vetor de forma randomica
        for (i = 0; i < n; i++){
            vetor[i] = RandomInteger(0, 3200);
        }
        break;
    
    default:
        break;
    }



    for (i = 0; i < n; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
    /*
    t = clock();
    bubbleSort(vetor, TAM);
    t = clock() - t;
    for (i = 0; i < TAM; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\nTempo de execucao: %lf", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
    */
    return 0;
}