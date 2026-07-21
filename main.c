#define _CRT_SECURE_NO_WARNINGS
#define TAM 6
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include "funcoes.h"

static void limpar_tela(void)
{
    system("cls");
}

static void aguardar_milisegundos(unsigned int ms)
{
    Sleep(ms);
}

static void mostrar_instrucoes(void)
{
    printf("Bejeweled simples - troque uma peca adjacente para formar trincas.\n");
    printf("Use as direcoes W=acima, S=abaixo, A=esquerda, D=direita.\n");
    printf("Digite: linha coluna direcao (por exemplo 3 4 D).\n");
    printf("Para sair, digite 0 0 X.\n");
    printf("Pecas novas aparecem entre colchetes [ ].\n\n");
}

static int ler_jogada(jogador *jogada)
{
    char direcao;
    int result;

    printf("Digite a peca e a direcao: ");
    result = scanf(" %d %d %c", &jogada->linha, &jogada->coluna, &direcao);
    if (result != 3)
    {
        while (getchar() != '\n' && !feof(stdin));
        return 0;
    }

    if (jogada->linha == 0 && jogada->coluna == 0)
    {
        jogada->linha1 = 0;
        jogada->coluna1 = 0;
        return 1;
    }

    direcao = toupper((unsigned char)direcao);
    jogada->linha1 = jogada->linha;
    jogada->coluna1 = jogada->coluna;

    if (direcao == 'W') jogada->linha1--;
    else if (direcao == 'S') jogada->linha1++;
    else if (direcao == 'A') jogada->coluna1--;
    else if (direcao == 'D') jogada->coluna1++;
    else
    {
        return -1;
    }

    return 1;
}

int main ()
{
    srand(time(NULL));
    int matriz[TAM][TAM];
    int novo[TAM][TAM] = {0};
    jogador jogada;
    int pontos = 0;

    criar_matriz(matriz);

    limpar_tela();
    mostrar_instrucoes();

    while (1)
    {
        mostrar_matriz(matriz);
        printf("\nPontos: %d\n", pontos);

        if (!ler_jogada(&jogada))
        {
            printf("Entrada invalida. Use o formato: linha coluna direcao (W/A/S/D).\n");
            continue;
        }

        if (jogada.linha == 0 && jogada.coluna == 0)
        {
            printf("Obrigado por jogar! Pontos finais: %d\n", pontos);
            break;
        }

        if (!validar_posicao(jogada))
        {
            printf("Nao atende aos requisitos da troca: escolha uma peca e uma direcao adjacente dentro do tabuleiro.\n");
            continue;
        }

        trocar_pecas(matriz, jogada);

        if (trinca(matriz, jogada))
        {
            int etapa = 0;
            do
            {
                etapa++;
                int removidas = remover_trincas(matriz);
                pontos += removidas * 10;

                printf("\nCascata %d: removidas %d peças\n", etapa, removidas);
                mostrar_matriz(matriz);
                aguardar_milisegundos(700);

                aplicar_gravidade(matriz);
                printf("Apos gravidade:\n");
                mostrar_matriz(matriz);
                aguardar_milisegundos(700);

                preencher_matriz(matriz, novo);
                printf("Apos preencher (novas pecas marcadas entre colchetes):\n");
                mostrar_matriz_com_marcador(matriz, novo);
                aguardar_milisegundos(700);
            }
            while (existe_trinca(matriz));

            printf("\nJogada valida!\n");
        }
        else
        {
            printf("\nSem trinca! Desfazendo jogada...\n");
            trocar_pecas(matriz, jogada);
        }
    }

    return 0;
}