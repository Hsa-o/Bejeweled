#include "fim.h"

void desenharFim(Texture2D *fim, Vector2 mouse, int *jogo_iniciado,  int *tela, Sound *somFim) {
    
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
        DrawRectangleLinesEx(botaoFim, 2, RED);
        if (CheckCollisionPointRec(mouse, botaoFim))
        {
            DrawRectangleRec(botaoFim, Fade(GREEN, 0.3f));
    
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    PlaySound(*somFim);
                     *tela = 0;
                     *jogo_iniciado = 0;
                }
        }

}