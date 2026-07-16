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

int validar_posicao(int linha, int coluna, int linha1, int coluna1)
{
    if(linha < 1 || linha > TAM || coluna < 1 || coluna > TAM || linha1 < 1 || linha1 > TAM || coluna1 < 1 || coluna1 > TAM)
    {
        return 0;
    }

    //abs é usado para pegar o valor absoluto, ou seja, |x|} Módulo.
    if(((linha == linha1) && (abs(coluna-coluna1)==1)) || ((coluna == coluna1) && (abs(linha-linha1)==1)))
    {
        return 1;
    }
    
    return 0;
}

typedef struct
{
    int linha;
    int coluna;
    int linha1;
    int coluna1;

} jogador;