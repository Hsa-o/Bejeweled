#define TAM 6
#define PONTOS_GEMA 5
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main ()
{
    srand(time(NULL));
    int matriz[TAM][TAM];
    int pontuacao = 0;
    jogador jogada;

    criar_matriz(matriz);
    mostrar_matriz(matriz);

    do
    {
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

        if (fez_trinca(matriz, jogada))
        {
            printf("\nJogada válida!\n");

            do
            {
                pontuacao += remover_trincas(matriz);
                printf("Pontuação: %d\n", pontuacao);

                mostrar_matriz(matriz);

                descer_pecas(matriz);
                mostrar_matriz(matriz);

                preencher_matriz(matriz);
                mostrar_matriz(matriz);


            } while (existe_trinca(matriz));
        }
        else
        {
            printf("\nSem trinca! Desfazendo jogada...\n");

            // Desfaz a troca
            trocar_pecas(matriz, jogada);

            // Mostra o tabuleiro restaurado
            mostrar_matriz(matriz);
        }
    }
    while (existe_jogada(matriz));

    return 0;
}