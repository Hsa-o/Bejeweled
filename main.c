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
    //----------------------------------------------------
}

int verificar_horizontal(int matriz[TAM][TAM], int linha)
{
    int contador = 1;

    for (int j = 1; j < TAM; j++)
    {
        if (matriz[linha][j] == matriz[linha][j-1])
        {
            contador++;
        }
        else
        {
            contador = 1;
        }
        
        if (contador >= 3)
        {
            return 1;
        }
    }

    return 0;   
    
}

int verificar_vertical(int matriz[TAM][TAM], int coluna)
{
    int contador = 1;
    for (int i = 1; i < TAM; i++)
    {
        if (matriz[i][coluna] == matriz[i-1][coluna])
        {
            contador++;
        }
        else
        {
            contador = 1;
        }
        
        if (contador >= 3)
        {
            return 1;
        }
    }

    return 0;   
    
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
    mostrar_matriz(matriz);// Faz a troca
    posicao_troca(matriz, jogada);

    // Mostra o tabuleiro após a troca
    printf("\nDepois da troca:\n");
    mostrar_matriz(matriz);

    // Verifica se houve trinca
    if (verificar_horizontal(matriz, jogada.linha - 1) ||
        verificar_horizontal(matriz, jogada.linha1 - 1) ||
        verificar_vertical(matriz, jogada.coluna - 1) ||
        verificar_vertical(matriz, jogada.coluna1 - 1))
    {
        printf("\nJogada válida!\n");
    }
    else
    {
        printf("\nSem trinca! Desfazendo jogada...\n");

        // Desfaz a troca
        posicao_troca(matriz, jogada);

        // Mostra o tabuleiro restaurado
        mostrar_matriz(matriz);
    }

    return 0;
}