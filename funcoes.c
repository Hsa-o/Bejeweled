#define TAM 6
#define GEM 5
#include "funcoes.h"

void criar_matriz(int matriz[TAM][TAM])
{
      for (int i = 0; i < TAM; i++)
      {
        for (int j = 0; j < TAM; j++)
        {
            do
            {
                matriz[i][j] = rand() % GEM + 1;

            } 
            while 
            (
                (j >= 2 &&
                 matriz[i][j] == matriz[i][j-1] &&
                 matriz[i][j] == matriz[i][j-2])

                ||

                (i >= 2 &&
                 matriz[i][j] == matriz[i-1][j] &&
                 matriz[i][j] == matriz[i-2][j])
            );
        }
    }
}

void mostrar_matriz(int matriz [TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int validar_posicao(jogador jogada)
{
    if(jogada.linha < 1 || jogada.linha > TAM || jogada.coluna < 1 || jogada.coluna > TAM || jogada.linha1 < 1 || jogada.linha1 > TAM || jogada.coluna1 < 1 || jogada.coluna1 > TAM)
    {
        return 0;
    }

    //abs é usado para pegar o valor absoluto, ou seja, |x|} Módulo.
    if(((jogada.linha == jogada.linha1) && (abs(jogada.coluna-jogada.coluna1)==1)) || ((jogada.coluna == jogada.coluna1) && (abs(jogada.linha-jogada.linha1)==1)))
    {
        return 1;
    }
    
    return 0;
}
