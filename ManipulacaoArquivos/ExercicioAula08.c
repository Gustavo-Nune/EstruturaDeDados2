#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heroi
{
    char nome[15];
    char poder[15];
    char fraqueza[15];
    char nomeReal[20];
    char cidade[20];
    char profissao[20];
} Heroi;

// Fprintf
// Cada linha com 1 herois com cada atributo com tamanho fixo Quebra linha
void escritaTamanhosFixos(FILE *arq, Heroi h)
{/*


    int i;

    for ( i = 0; i < 15; i++)
    {
    fputc(h.nome[i],arq);
    fprintf(arq, "|");
    fputc(h.poder[i],arq);
    fprintf(arq, "|");
    fputc(h.fraqueza[i],arq);
    fprintf(arq, "|");
        
    }
*/
    
/**/
        fprintf(arq, "%s|", h.nome);
        fprintf(arq, "%s|", h.poder);
        fprintf(arq, "%s|", h.fraqueza);
 

        fprintf(arq, "%s|", h.nomeReal);
        fprintf(arq, "%s|", h.cidade);
        fprintf(arq, "%s|", h.profissao);
}
// com a quantidade certo do tamanho do atributo C
void escritaQtdeCamps(FILE *arq, Heroi h, int n)
{

        fprintf(arq, "%s|", h.nome);
        fprintf(arq, "%s|", h.poder);
        fprintf(arq, "%s|", h.fraqueza);
 

        fprintf(arq, "%s|", h.nomeReal);
        fprintf(arq, "%s|", h.cidade);
        fprintf(arq, "%s|", h.profissao);
}
// Soma dos bytes dos atributos C
void escritaQtdeBytesComeço(FILE *arq, Heroi h)
{
}
// Hora que terminar o registro de um heroi usar # C
void escritaDelimitador(FILE *arq, Heroi h)
{
}

void leituraTamanhosFixos(FILE *arq, Heroi h);
void leituraQtdeCamps(FILE *arq, Heroi h, int n);
void leituraQtdeBytesComeco(FILE *arq, Heroi h);
void leituraDelimitador(FILE *arq, Heroi h);

void main()
{

    FILE *arqTFixos = fopen("TFixos.txt", "w+r");
    FILE *arqQtdCampos = fopen("QtdCampos.txt", "w+r");
    FILE *arqQtsBytes = fopen("QtsBytes.txt", "w+r");
    FILE *arqLimitador = fopen("Limitador.txt", "w+r");

    Heroi h = {"Super-Man", "Forca", "Kriptonita", "Clack-Kent", "Metropolis", "Jornalista"};


        escritaTamanhosFixos(arqTFixos, h);
    
}