#include "jogo.h"

void desenharJogo(Texture2D *jogo, Texture2D gemas[GEM], Gema matriz[TAM][TAM], int inicioX, int inicioY, int larguraTabuleiro, int alturaTabuleiro, int larguraGema, int alturaGema, int linhaSelecionada, int colunaSelecionada, int pontuacao)
{
    DrawTexturePro(
        *jogo,
        (Rectangle){0, 0, jogo->width, jogo->height},
        (Rectangle){0, 0, 1255, 723},
        (Vector2){0, 0},
        0,
        WHITE
    );

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            int x = inicioX + j * larguraGema;
            int y = inicioY + i * alturaGema;

            if (matriz[i][j].tipo > 0)
            {
                DrawTexturePro(
                    gemas[matriz[i][j].tipo - 1],
                    (Rectangle){0, 0, 48, 48},
                    (Rectangle){x, y, larguraGema, alturaGema},
                    (Vector2){0, 0},
                    0,
                    WHITE
                );
            }
            if (i == linhaSelecionada && j == colunaSelecionada)
            {
                DrawRectangleLinesEx(
                    (Rectangle){x, y, larguraGema, alturaGema},
                    4,
                    YELLOW
                );
            }
        }
    }
    char textoPontuacao[50];

    sprintf(textoPontuacao, "Pontos: %d", pontuacao);

    int larguraTexto = MeasureText(textoPontuacao, 30);

    DrawText(
        textoPontuacao,
        1255 - larguraTexto - 40,
        40,
        30,
        WHITE
    );
    Rectangle caixa = {450, 650, 300, 100};

    DrawRectangleRec(caixa, DARKBLUE);          // Fundo
    DrawRectangleLinesEx(caixa, 2, WHITE);      // Borda
    int tamanhoFonte = 45;
    char texto[] = "ENCERRAR";

    DrawText(
        texto,
        caixa.x + (caixa.width - MeasureText(texto, tamanhoFonte)) / 2,
        caixa.y + (caixa.height - tamanhoFonte) / 2,
        tamanhoFonte,
        WHITE
    );
}