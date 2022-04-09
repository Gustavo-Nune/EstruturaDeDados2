#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//*************************************
//        Funçoes auxiliares
//*************************************
//Cria numeros aleatorios
int RandomInteger(int low, int high)
{
    int k;
    k = (rand() % high) + low;
    return k;
}
//Faz atroca de posição em um vetor
void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
// Gera um vetor
void geraVetor(int *V,int tam,char tipoVetor){
    
    int i,auxD = 0;
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
void imprimeTimeVetor(int *v,int tam,clock_t t){
   /*
    for (int i = 0; i < tam; i++)
    {
        printf("[%d] ", v[i]);
    }*/
    printf("Tempo de execucao: %lf", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
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

void merge(int *v, int inicio, int meio, int fim)
{
    int *temp;
    int i, j, k;
    int p1, p2;
    int vecSize;

    bool finished1 = false;
    bool finished2 = false;

    vecSize = (fim - inicio) + 1;

    p1 = inicio;
    p2 = meio + 1;

    temp = (int *)malloc(vecSize * sizeof(int));

    if (temp != NULL)
    {

        for (i = 0; i < vecSize; i++)
        {

            if (!finished1 && !finished2)
            {
                if (v[p1] < v[p2])
                {
                    temp[i] = v[p1++];
                }
                else
                {
                    temp[i] = v[p2++];
                }

                /* checking if any sub vector finished */
                if (p1 > meio)
                {
                    finished1 = true;
                }
                if (p2 > fim)
                {
                    finished2 = true;
                }
            }
            else
            {
                /* copying the remaining elements */
                if (!finished1)
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
            }
        }
        /* copying elements from temp to v */
        for (j = 0, k = inicio; j < vecSize; j++, k++)
        {
            v[k] = temp[j];
        }

    } // if
    free(temp);
}
void mergeSort(int *V, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = ((inicio + fim) / 2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
}

//*************************************
//            QuickSort
//*************************************
// IMPLEMENTAR Pagina 117
void quickSort(){}
//*************************************
//            HeapSort
//*************************************
// IMPLEMENTAR Pagina 103
void heapSort(){}
//*************************************
//            Main
//*************************************

int main()
{
    int *vetor;
    int i, n, auxD = 0;
    char tipoVetor ;
    clock_t t;

    printf("Tipo do vetor:\nc - crescente\nd - decrescente\nr - randomico\n ");
    scanf("%s", &tipoVetor);
    printf("Digite o tamanho do vetor : ");
    scanf("%d", &n);

    vetor = (int*) malloc(n*sizeof(int));

    geraVetor(vetor,n,tipoVetor);

    printf("Vetor desorganizado : \n");
    for (i = 0; i < n; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");

    //InsertionSort
    printf("InsertionSort : ");
    t = clock();
    insertionSort(vetor,n);
    t = clock() - t;
    imprimeTimeVetor(vetor,n,t);
    printf("\n");

    geraVetor(vetor, n, tipoVetor);
    /*printf("Vetor desorganizado : \n");
    for (i = 0; i < n; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");*/

    // SelectionSort
    printf("SelectionSort : ");
    t = clock();
    bubbleSort(vetor, n);
    t = clock() - t;
    imprimeTimeVetor(vetor,n,t);

    geraVetor(vetor, n, tipoVetor);

    printf("\n");
    // BubbleSort
    printf("BubbleSort : ");
    t = clock();
    bubbleSort(vetor, n);
    t = clock() - t;
    imprimeTimeVetor(vetor,n,t);
    printf("\n");
    geraVetor(vetor, n, tipoVetor);
    // MergeSort
    printf("MergeSort : ");
    t = clock();
    bubbleSort(vetor, n);
    t = clock() - t;
    imprimeTimeVetor(vetor,n,t);
    printf("\n");

    /*
        for (i = 0; i < n; i++)
        {
            printf("[%d] ", vetor[i]);
        }
        printf("\nTempo de execucao: %lf", ((double)t) / ((CLOCKS_PER_SEC / 1000)));*/

    return 0;
}