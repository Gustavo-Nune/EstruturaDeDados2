#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief 
 * 
 * @param arq Arquivo de entrada
 * @param key chave canonica
 * @return int 
 */
int deleteRecord(FILE *arq,char*key){
    int i = 0;
    char *aux;

    strcpy(aux,key);
     
     while(key[i]) {
       //key[i] = toupper(aux[i]);
      putchar (toupper(key[i]));
      i++;
   }
}
/**
 * @brief 
 * 
 * @param arq 
 * @param key 
 */
void storageCompaction(FILE *arq,char*key){

}

void main(){


    FILE *arqEntrada = fopen("heroi.txt","r");
    FILE *arqNovo = fopen("Saida.txt","w");

    deleteRecord(arqEntrada,"Steve Rogers");
    
    //remove("heroi.txt");
    //rename("Saida.txt","heroi.txt");
  

}