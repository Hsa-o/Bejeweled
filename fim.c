#include "fim.h"
#define TAM 8

void desenharFim(Texture2D *fim, Vector2 mouse, int *jogo_iniciado,  int *tela, Sound *somFim, Gema matriz[TAM][TAM], int *pontuacao) 
{
    
    Rectangle botaoFim = {825, 540, 75, 75};
    DrawTexturePro
        (
            *fim,
            (Rectangle){0, 0, fim->width, fim->height},
            (Rectangle){0, 0, 1255, 723},
            (Vector2){0, 0},
            0,
            WHITE
        );

        if (CheckCollisionPointRec(mouse, botaoFim))
        {
            DrawRectangleRec(botaoFim, Fade(GREEN, 0.3f));
    
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    PlaySound(*somFim);
                     *tela = 0;
                     *jogo_iniciado = 0;
                     *pontuacao = 0;
                     criar_matriz(matriz);
                }
        }

}