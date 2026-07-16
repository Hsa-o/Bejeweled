#define TAM 6
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void posicao_troca(int matriz[TAM][TAM], int linha, int linha1, int coluna, int coluna1)
{  
    //Tópico descartavel--------------------------
    printf("===================\n");
    printf("Valor na matriz: %d", matriz[linha-1][coluna-1]);
    printf("\n");
    printf("Valor na matriz: %d\n=================\n", matriz[linha1-1][coluna1-1]);
    //--------------------------------------------

    //Para substituir, precisa fazer uma trinca ----------   
    int copia_pos1 = matriz[linha-1][coluna-1];
    matriz[linha-1][coluna-1] = matriz[linha1-1][coluna1-1];
    matriz[linha1-1][coluna1-1] = copia_pos1;
    //-------------------------------------------------
    mostrar_matriz(matriz);
}




int main ()
{

    srand(time(NULL));

    int matriz[TAM][TAM];
    int linha, coluna, linha1, coluna1, expressao, expressao1;

    criar_matriz(matriz);
    mostrar_matriz(matriz);

    do
    {
        printf("Linha da troca, coluna da troca:\n");
        scanf("%d%d", &linha, &coluna);
        
        printf("Linha da troca, coluna da troca:\n");
        scanf("%d%d", &linha1, &coluna1);
        
        expressao1 = (linha < 1 || linha > TAM || coluna < 1 || coluna > TAM || linha1 < 1 || linha1 > TAM || coluna1 < 1 || coluna1 > TAM);
        expressao = ((linha == linha1)&&(abs(coluna - coluna1) == 1))||((coluna == coluna1)&&(abs(linha - linha1) == 1));

        //abs é usado para pegar o valor absoluto, ou seja, |x|} Módulo.

        if(!expressao || expressao1){
            printf("Tente novamente!\n");
        }
        
        //se linha e coluna diferente de 1-TAM, e se nao for vizinhas
    } while ( !expressao || expressao1);

    //Só entra na posicao_troca satisfazer o do while;
    posicao_troca(matriz, linha, linha1, coluna, coluna1);


    return 0;
}