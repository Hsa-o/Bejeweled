#include "menu.h"

void desenharMenu(Texture2D *menu, Vector2 mouse, int *jogo_iniciado,  int *tela, Gema matriz[TAM][TAM], Sound *somJogar) {
    
    Rectangle botaoJogar = {460, 405, 334, 80};
     DrawTexturePro
            (
                *menu,
    
                //"Qual pedaço dessa imagem eu quero usar?"
                //0,0 que é o canto superior esquerdo ate o widht e o height da imagem(1920, 1080)
                (Rectangle){0, 0, menu->width, menu->height},
    
                //"Depois de pegar esse pedaço, onde ele será desenhado e com qual tamanho?"
                //0,0 ate o tamanho do initwindows, que é o tamanho da janela criada.
                (Rectangle){0, 0, 1255, 723},
                (Vector2){0, 0},
                0,
                WHITE
            );
               if (CheckCollisionPointRec(mouse, botaoJogar))
               {
                   DrawRectangleRec(botaoJogar, Fade(GREEN, 0.3f));
    
                   if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                   {
                    PlaySound(*somJogar);
                     *tela = 1;
                     criar_matriz(matriz);
                     *jogo_iniciado = 1;
                   }
               }

}