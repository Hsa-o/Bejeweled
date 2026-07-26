#define TAM 6
#define GEM 4
#define PONTOS_GEMA 5
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

void trocar_pecas(int matriz[TAM][TAM], jogador jogada)
{ 
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

int fez_trinca(int matriz[TAM][TAM], jogador jogada)
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

int remover_trincas(int matriz[TAM][TAM])
{
    int apagar[TAM][TAM] = {0};
    int pontos = 0;
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
                pontos += PONTOS_GEMA;
            }
        }
    }
    return pontos;
}

void descer_pecas(int matriz[TAM][TAM])

{
    // Percorre cada coluna
    for (int j = 0; j < TAM; j++)
    {
        // Percorre de baixo para cima
        for (int i = TAM - 1; i >= 0; i--)
        {
            // Se encontrou um espaço vazio
            if (matriz[i][j] == 0)
            {
                // Procura uma peça acima
                for (int k = i - 1; k >= 0; k--)
                {
                    if (matriz[k][j] != 0)
                    {
                        // Move a peça para baixo
                        matriz[i][j] = matriz[k][j];
                        matriz[k][j] = 0;

                        // Para de procurar nessa posição
                        break;
                    }
                }
            }
        }
    }
}

void preencher_matriz(int matriz[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (matriz[i][j] == 0)
            {
                matriz[i][j] = rand() % GEM + 1;
            }
        }
    }
}

int existe_trinca(int matriz[TAM][TAM])
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

int existe_jogada(int matriz[TAM][TAM])
{
    jogador teste;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            // Testa troca para a direita
            if (j < TAM - 1)
            {
                teste.linha = i + 1;
                teste.coluna = j + 1;
                teste.linha1 = i + 1;
                teste.coluna1 = j + 2;

                trocar_pecas(matriz, teste);

                if (fez_trinca(matriz, teste))
                {
                    trocar_pecas(matriz, teste); // desfaz
                    return 1;
                }

                trocar_pecas(matriz, teste); // desfaz
            }

            // Testa troca para baixo
            if (i < TAM - 1)
            {
                teste.linha = i + 1;
                teste.coluna = j + 1;
                teste.linha1 = i + 2;
                teste.coluna1 = j + 1;

                trocar_pecas(matriz, teste);

                if (fez_trinca(matriz, teste))
                {
                    trocar_pecas(matriz, teste); // desfaz
                    return 1;
                }

                trocar_pecas(matriz, teste); // desfaz
            }
        }
    }

    return 0;
}