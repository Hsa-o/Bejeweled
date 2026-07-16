#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void posicao_troca(int matriz[4][4]){
    int linha, coluna, linha1, coluna1;
    int expressao, expressao1;
    do
    {
        printf("Linha da troca, coluna da troca:\n");
        scanf("%d%d", &linha, &coluna);
        
        printf("Linha da troca, coluna da troca:\n");
        scanf("%d%d", &linha1, &coluna1);
        
        expressao1 = (linha < 1 || linha > 4 || coluna < 1 || coluna > 4 || linha1 < 1 || linha1 > 4 || coluna1 < 1 || coluna1 > 4);
        expressao = ((linha == linha1)&&(abs(coluna - coluna1) == 1))||((coluna == coluna1)&&(abs(linha - linha1) == 1));

        if(!expressao || expressao1){
            printf("Tente novamente!\n");
        }
        
    //se linha e coluna diferente de 1-4, error!
    } while ( !expressao || expressao1);
    
    //Tópico descartavel--------------------------
    printf("===================\n");
    printf("Valor na matriz: %d", matriz[linha-1][coluna-1]);
    printf("\n");
    printf("Valor na matriz: %d\n=================\n", matriz[linha1-1][coluna1-1]);

        
    int copia_pos1 = matriz[linha-1][coluna-1];
    matriz[linha-1][coluna-1] = matriz[linha1-1][coluna1-1];
    matriz[linha1-1][coluna1-1] = copia_pos1;
    
    mostrar_matriz(matriz);
}


int main (){

    srand(time(NULL));
    int matriz[4][4];
    
    criar_matriz(matriz);
    //do while-------------
    mostrar_matriz(matriz);
    posicao_troca(matriz);
    //---------------------
    return 0;
}