#define PONTOS_GEMA 5
#include "funcoes.h"

void criar_matriz(Gema matriz[TAM][TAM])
{
      for (int i = 0; i < TAM; i++)
      {
        for (int j = 0; j < TAM; j++)
        {
            matriz[i][j].textura = (Texture2D){0};
            matriz[i][j].posicao = (Vector2){0,0};
            matriz[i][j].caixa = (Rectangle){0,0,0,0};
            do
            {
                matriz[i][j].tipo = rand() % GEM + 1;

            } 
            while 
            (
                (j >= 2 &&
                 matriz[i][j].tipo == matriz[i][j-1].tipo &&
                 matriz[i][j].tipo == matriz[i][j-2].tipo)

                ||

                (i >= 2 &&
                 matriz[i][j].tipo == matriz[i-1][j].tipo &&
                 matriz[i][j].tipo == matriz[i-2][j].tipo)
            );
        }
    }
}

void mostrar_matriz(Gema matriz [TAM][TAM])
{
    printf("-----------------------------------------\n");
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%d\t", matriz[i][j].tipo);
        }
        printf("\n");
    }
}

int validar_posicao(jogador jogada)
{
    if (jogada.linha < 1 || jogada.linha > TAM)
    return 0;

    if (jogada.coluna < 1 || jogada.coluna > TAM)
        return 0;

    if (jogada.linha1 < 1 || jogada.linha1 > TAM)
        return 0;

    if (jogada.coluna1 < 1 || jogada.coluna1 > TAM)
        return 0;

    //abs é usado para pegar o valor absoluto, ou seja, |x|} Módulo.
    if(((jogada.linha == jogada.linha1) && (abs(jogada.coluna-jogada.coluna1)==1)) || ((jogada.coluna == jogada.coluna1) && (abs(jogada.linha-jogada.linha1)==1)))
    {
        return 1;
    }
    
    return 0;
}

void trocar_pecas(Gema matriz[TAM][TAM], jogador jogada)
{ 
    //Para substituir, precisa fazer uma trinca ----------   
    Gema copia_pos1 = matriz[jogada.linha-1][jogada.coluna-1];
    matriz[jogada.linha-1][jogada.coluna-1] = matriz[jogada.linha1-1][jogada.coluna1-1];
    matriz[jogada.linha1-1][jogada.coluna1-1] = copia_pos1;
    //----------------------------------------------------
}

static int verificar_horizontal(Gema matriz[TAM][TAM], int linha)
{
    int contador = 1;

    for (int j = 1; j < TAM; j++)
    {
        if (matriz[linha][j].tipo == matriz[linha][j-1].tipo)
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

static int verificar_vertical(Gema matriz[TAM][TAM], int coluna)
{
    int contador = 1;

    for (int i = 1; i < TAM; i++)
    {
        if (matriz[i][coluna].tipo == matriz[i-1][coluna].tipo)
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

int fez_trinca(Gema matriz[TAM][TAM], jogador jogada)
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

int remover_trincas(Gema matriz[TAM][TAM])
{
    int apagar[TAM][TAM] = {0};
    int pontos = 0;
    //Procura trincas horizontais
    for (int i = 0; i < TAM; i++)
    {
        int contador = 1;

        for (int j = 1; j < TAM; j++)
        {
            if (matriz[i][j].tipo == matriz[i][j-1].tipo)
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
            if (matriz[i][j].tipo == matriz[i-1][j].tipo)
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
                matriz[i][j].tipo = 0;
                pontos += PONTOS_GEMA;
            }
        }
    }
    return pontos;
}

void descer_pecas(Gema matriz[TAM][TAM])
{
    for (int j = 0; j < TAM; j++)
    {
        for (int i = TAM - 1; i >= 0; i--)
        {
            if (matriz[i][j].tipo == 0)
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    if (matriz[k][j].tipo != 0)
                    {
                        matriz[i][j] = matriz[k][j];
                        matriz[k][j].tipo = 0;
                        break;
                    }
                }
            }
        }
    }
}

void preencher_matriz(Gema matriz[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (matriz[i][j].tipo == 0)
            {
                matriz[i][j].tipo = rand() % GEM + 1;
            }
        }
    }
}

int existe_trinca(Gema matriz[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        if (verificar_horizontal(matriz, i))
            return 1;
    }

    for (int j = 0; j < TAM; j++)
    {
        if (verificar_vertical(matriz, j))
            return 1;
    }

    return 0;
}

int existe_jogada(Gema matriz[TAM][TAM])
{
    jogador jogada;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            // Testa troca para a direita
            if (j < TAM - 1)
            {
                jogada.linha = i + 1;
                jogada.coluna = j + 1;
                jogada.linha1 = i + 1;
                jogada.coluna1 = j + 2;

                trocar_pecas(matriz, jogada);

                if (fez_trinca(matriz, jogada))
                {
                    trocar_pecas(matriz, jogada); // desfaz
                    return 1;
                }

                trocar_pecas(matriz, jogada); // desfaz
            }

            // Testa troca para baixo
            if (i < TAM - 1)
            {
                jogada.linha = i + 1;
                jogada.coluna = j + 1;
                jogada.linha1 = i + 2;
                jogada.coluna1 = j + 1;

                trocar_pecas(matriz, jogada);

                if (fez_trinca(matriz, jogada))
                {
                    trocar_pecas(matriz, jogada); // desfaz
                    return 1;
                }

                trocar_pecas(matriz, jogada); // desfaz
            }
        }
    }

    return 0;
}