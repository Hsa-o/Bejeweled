#define TAM 6
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"



void marcar_horizontal(int matriz[TAM][TAM], int apagar[TAM][TAM])
{
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM - 2; j++)
        {
            if(matriz[i][j] == matriz[i][j+1] &&
               matriz[i][j] == matriz[i][j+2])
            {
                apagar[i][j] = 1;
                apagar[i][j+1] = 1;
                apagar[i][j+2] = 1;
            }
        }
    }
}

void marcar_vertical(int matriz[TAM][TAM], int apagar[TAM][TAM])
{
    for(int i = 0; i < TAM - 2; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            if(matriz[i][j] == matriz[i+1][j] &&
               matriz[i][j] == matriz[i+2][j])
            {
                apagar[i][j] = 1;
                apagar[i+1][j] = 1;
                apagar[i+2][j] = 1;
            }
        }
    }
}

void zerar_trinca(int matriz[TAM][TAM], int apagar[TAM][TAM])
{
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            if(apagar[i][j])
            {
                matriz[i][j] = 0;
            }
        }
    }
}

int main ()
{
    srand(time(NULL));
    int matriz[TAM][TAM];
    int marcar_trinca[TAM][TAM] = {0};
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

    //Só entra no trocar_pecas se satisfazer o do while;
    trocar_pecas(matriz, jogada);

    printf("\nDepois da troca:\n");
    mostrar_matriz(matriz);

    if (trinca(matriz, jogada))
    {
        printf("\nJogada válida!\n");
        marcar_horizontal(matriz, apagar);
        marcar_vertical(matriz, apagar);

        zerar_trinca(matriz, apagar);

        mostrar_matriz(matriz);
    }
    else
    {
        printf("\nSem trinca! Desfazendo jogada...\n");

        // Desfaz a troca
        trocar_pecas(matriz, jogada);

        // Mostra o tabuleiro restaurado
        mostrar_matriz(matriz);
    }

    return 0;
}