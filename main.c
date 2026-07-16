#define TAM 6
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void posicao_troca(int matriz[TAM][TAM], jogador jogada)
{  
    //Tópico descartavel--------------------------
    printf("===================\n");
    printf("Valor na matriz: %d", matriz[jogada.linha-1][jogada.coluna-1]);
    printf("\n");
    printf("Valor na matriz: %d\n=================\n", matriz[jogada.linha1-1][jogada.coluna1-1]);
    //--------------------------------------------

    //Para substituir, precisa fazer uma trinca ----------   
    int copia_pos1 = matriz[jogada.linha-1][jogada.coluna-1];
    matriz[jogada.linha-1][jogada.coluna-1] = matriz[jogada.linha1-1][jogada.coluna1-1];
    matriz[jogada.linha1-1][jogada.coluna1-1] = copia_pos1;
    //-------------------------------------------------
    mostrar_matriz(matriz);
}
int verificar_jogada(int matriz[TAM][TAM], jogador jogada)
{
    
}
int main ()
{
    srand(time(NULL));
    int matriz[TAM][TAM];
    jogador jogada;

    criar_matriz(matriz);
    mostrar_matriz(matriz);

    do
    {
        printf("Linha da troca, coluna da troca:\n");
        scanf("%d%d", &jogada.linha, &jogada.coluna);
        
        printf("Linha da troca, coluna da troca:\n");
        scanf("%d%d", &jogada.linha1, &jogada.coluna1);
        
        if (!validar_posicao(jogada))
        {
            printf("Nao atende aos requisitos da troca: vizinha ou entre 1-%d\n", TAM);
        }
        
    } while(!validar_posicao(jogada));

    //Só entra na posicao_troca satisfazer o do while;
    posicao_troca(matriz, jogada);


    return 0;
}