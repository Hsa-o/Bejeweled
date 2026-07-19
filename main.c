#define TAM 6
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


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
        remover_trincas(matriz);
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