#define TAM 6
#define GEM 4
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
    printf("-----------------------------------------\n");
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

void trocar_pecas(int matriz[TAM][TAM], jogador jogada)
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

static int verificar_horizontal(int matriz[TAM][TAM], int linha)
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

static int verificar_vertical(int matriz[TAM][TAM], int coluna)
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

int trinca(int matriz[TAM][TAM], jogador jogada)
{
    if (verificar_horizontal(matriz, jogada.linha - 1) ||
        verificar_horizontal(matriz, jogada.linha1 - 1) ||
        verificar_vertical(matriz, jogada.coluna - 1) ||
        verificar_vertical(matriz, jogada.coluna1 - 1))
    {
        return 1;
    }
    return 0;
        
}

void remover_trincas(int matriz[TAM][TAM])
{
    int apagar[TAM][TAM] = {0};

    //Procura trincas horizontais
    for (int i = 0; i < TAM; i++)
    {
        int contador = 1;

        for (int j = 1; j < TAM; j++)
        {
            if (matriz[i][j] == matriz[i][j-1])
            {
                contador++;
            }
            else
            {
                if (contador >= 3)
                {
                    for (int k = j-contador; k < j; k++)
                    {
                        apagar[i][k] = 1;
                    }
                }

                contador = 1;
            }
        }

        // Caso a trinca termine na última coluna
        if (contador >= 3)
        {
            for (int k = TAM-contador; k < TAM; k++)
            {
                apagar[i][k] = 1;
            }
        }
    }

    //Procura trincas verticais
    for (int j = 0; j < TAM; j++)
    {
        int contador = 1;

        for (int i = 1; i < TAM; i++)
        {
            if (matriz[i][j] == matriz[i-1][j])
            {
                contador++;
            }
            else
            {
                if (contador >= 3)
                {
                    for (int k = i-contador; k < i; k++)
                    {
                        apagar[k][j] = 1;
                    }
                }

                contador = 1;
            }
        }

        // Caso a trinca termine na última linha
        if (contador >= 3)
        {
            for (int k = TAM-contador; k < TAM; k++)
            {
                apagar[k][j] = 1;
            }
        }
    }

    // Zera todas as posições marcadas
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (apagar[i][j])
            {
                matriz[i][j] = 0;
            }
        }
    }
}
