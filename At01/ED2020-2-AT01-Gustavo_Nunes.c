#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

//****************************************************************************
//*                           PILHA ESTATICA                                 *
//****************************************************************************
typedef struct
{
  int vetor[N]; //vetor
  int topo;     //controla o topo da pilha
} PilhaEstatica;

// A pilha é iniciado quando colocamos o valor do topo no 0
void iniciaPilha(PilhaEstatica *p) { p->topo = 0; }
// imprimePilha nesta funçao é impresso o que esta dentro da pilha , como se estivessemos percorrendo um vetor,
//alem disso o for so irá parar quando i for igual a posição do topo.
void imprimePilha(PilhaEstatica *p)
{
  printf("Pilha = {");
  for (int i = 0; i < p->topo; i++)
  {
    printf("|%d| ", p->vetor[i]);
  }
  printf("}\n");
}
// Verifica se a pilha esta vazia ou cheia
bool estaVazia(PilhaEstatica *p) { return (p->topo == 0); }
bool estaCheia(PilhaEstatica *p) { return (p->topo == N); }
// Para empilharmos essa pilha utilizamos um if com a condição da pilha não estar cheia(funçao estaCheia), em seguida atribuimos
//o valor a posição em que o topo esta
int empilhar(PilhaEstatica *p, int valor)
{
  if (!estaCheia(p))
  {
    p->vetor[p->topo] = valor;
    p->topo++;
  }
  else
  {
    ("Warning: nao inserido porque esta cheia\n");
  }
}
// Para desempilhar ele muda a posiçao do topo para um valor a menos
int desempilhar(PilhaEstatica *p)
{
  int x = -1;
  if (estaVazia(p))
  {
    return (x);
  }
  else
  {
    return (p->vetor[--p->topo]);
  }
}

//****************************************************************************
//*                           PILHA DINAMICA                                 *
//****************************************************************************

typedef struct NoPilha *PtrNoPilha; // Implementa o tipo que permite concatenar os nós dinamicos

typedef struct NoPilha
{
  int valor; // Implementa o nosso valor
  PtrNoPilha proximo;
} NoPilha; // Implementa os nós da  pilha

typedef struct
{
  PtrNoPilha topo;
  int tamanho;
} PilhaDinamica; // Implementa o TDA para pilha

void iniciaPilhaDinamica(PilhaDinamica *pd) // Inicia a Pilha com o topo em NULL e o tamanho valendo 0
{
  pd->topo = NULL;
  pd->tamanho = 0;
}
bool PdestaVazia(PilhaDinamica *pd) { return (pd->tamanho == 0); }
void push(PilhaDinamica *pd, int valor)
{                                               // Empilha
  PtrNoPilha aux;                               // Cria um novo no de Pilha
  aux = (PtrNoPilha)malloc(sizeof(PtrNoPilha)); // Aloca memoria do no de pilha
  aux->valor = valor;                           // Recebe o valor a ser inserido
  aux->proximo = pd->topo;
  pd->topo = aux;
  pd->tamanho++;
}
void imprimePilhaD(PilhaDinamica *pd)
{
  printf("Pilha : {");
  for (PtrNoPilha ptr = pd->topo; ptr != NULL; ptr = ptr->proximo)
  {
    printf(" %d ", ptr->valor);
  }
  printf("}\n");
}
int pop(PilhaDinamica *pd)
{ // Desempilha
  int x = -99;
  if (!PdestaVazia(pd))
  {
    PtrNoPilha aux;
    aux = pd->topo;
    x = aux->valor;
    pd->topo = aux->proximo;
    free(aux);
    pd->tamanho--;
  }
  else
  {
    printf("Warning : a pilha esta vazia!!\n");
  }
  return (x);
}

//****************************************************************************
//*                               MAIN                                       *
//****************************************************************************
int main()
{

  // Cria o ponterio para os arquivos.
  FILE *arqEntrada;
  FILE *arqSaida;
  // Declara as pilhas usadas.
  PilhaEstatica pilhaEImpressao;
  PilhaEstatica pilhaEConversao;
  PilhaDinamica pilhaDImpressao;
  PilhaDinamica pilhaDConversao;
  // Variaveis
  int cont = 0;
  char c;
  int num;
  // Abre os arquivos para leitura e gravação.
  arqEntrada = fopen("entrada02.txt", "r");
  arqSaida = fopen("saida.txt", "w");
  // Percorre o arquivo para saber quantas linhas possui.
  while (fread(&c, sizeof(char), 1, arqEntrada) != 0)
  {
    if (c == '\n')
    {
      cont++;
    }
  }

  //Variaveis
  char msgErro[18] = {"Arquivo invalido!!"};
  char tipoPilha;

  // Atribui a tipoPilha o tipo da pilha
  fseek(arqEntrada, 0, SEEK_SET);
  tipoPilha = fgetc(arqEntrada);
  printf("A pilha eh do tipo : %c\n", tipoPilha);

  // Verifica se há erros
  if (arqEntrada == NULL || arqSaida == NULL)
  {
    printf("\n\n#### Ocorreu um erro ao abrir o arquivo ####\n#### O programa esta sendo encerrado ####\n\n");
    exit(1);
  }
  if (tipoPilha != 'd' && tipoPilha != 'e')
  {
    printf("\n\n#### Opcao de Pilha invalida ####\n#### O programa esta sendo encerrado ####\n\n");
    fwrite(&msgErro, sizeof(char), 18, arqSaida);
    exit(1);
  }
  // Faz a conversão caso for solicitado a Pilha Dinamica.
  if (tipoPilha == 'd')
  {
    // Inicia as Pilhas Dinamicas
    printf("Iniciando Pilha Dinamica...\n");
    iniciaPilhaDinamica(&pilhaDImpressao);
    iniciaPilhaDinamica(&pilhaDConversao);
    // Passa os numeros para a pilhaDImpressao
    for (int i = 0; i < cont; i++)
    {
      fscanf(arqEntrada, "%d", &num);
      push(&pilhaDImpressao, num);
    }
    imprimePilhaD(&pilhaDImpressao);

    printf("Convertendo os numeros em Binario..\n");
    // Ira repetir ate que a pilhaDimpressao estiver vazia
    while (!PdestaVazia(&pilhaDImpressao))
    {
      // A variavel num recebe o numero que foi desempilhado de pilhaDImpressao
      num = pop(&pilhaDImpressao);
      imprimePilhaD(&pilhaDImpressao);
      while (num != 0)
      {
        // Empilha o resto da divisao por 2 na pilhaDConversao
        push(&pilhaDConversao, num % 2);
        // Divide o numero ate que a pilha fique vazia assim pegando o resto das metades ate cheagar em 0
        num /= 2;
        imprimePilhaD(&pilhaDConversao);
      }
      imprimePilhaD(&pilhaDConversao);
      while (!PdestaVazia(&pilhaDConversao))
      {
        // Atribui o valor retirado de pilhaDconversao para num
        num = pop(&pilhaDConversao);
        fprintf(arqSaida, "%d", num);
        printf("%d", num);
      }
      fprintf(arqSaida, "\n");
      printf("\n***************\n");
    }
    printf("Convertidos com sucesso!!!\n");
  }
  // Faz a conversão caso for solicitado a Pilha Estatica.
  if (tipoPilha == 'e')
  {
    // Inicia as Pilhas Estaticas
    printf("Iniciando Pilha Estatica...\n");
    iniciaPilha(&pilhaEImpressao);
    iniciaPilha(&pilhaEConversao);
    // Passa os numeros para a pilhaEImpressao
    for (int i = 0; i < cont; i++)
    {
      fscanf(arqEntrada, "%d", &num);
      empilhar(&pilhaEImpressao, num);
    }
    imprimePilha(&pilhaEImpressao);
    printf("Convertendo os numeros em Binario..\n");
    // Ira repetir ate que a pilhaEimpressao estiver vazia
    while (!estaVazia(&pilhaEImpressao))
    {
      // A variavel num recebe o numero que foi desempilhado de pilhaEImpressao
      num = desempilhar(&pilhaEImpressao);
      imprimePilha(&pilhaEImpressao);
      while (num != 0)
      {
        // Empilha o resto da divisao por 2 na pilhaEConversao
        empilhar(&pilhaEConversao, num % 2);
        // Divide o numero ate que a pilha fique vazia assim pegando o resto das metades ate cheagar em 0
        num /= 2;
        imprimePilha(&pilhaEConversao);
      }
      imprimePilha(&pilhaEConversao);
      while (!estaVazia(&pilhaEConversao))
      {
        // Atribui o valor retirado de pilhaEconversao para num
        num = desempilhar(&pilhaEConversao);
        fprintf(arqSaida, "%d", num);
        printf("%d", num);
      }
      fprintf(arqSaida, "\n");
      printf("\n***************\n");
    }
    printf("Convertidos com sucesso!!!\n");
  }
  // Fecha arquivos
  fclose(arqEntrada);
  fclose(arqSaida);

  return 0;
}
