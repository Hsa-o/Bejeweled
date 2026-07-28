#include "raylib.h"
#define TAM 8
#define GEM 5
#define PONTOS_GEMA 5
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <time.h>
#include "menu.h"

int main(void)
{
    //1200 = largura; 700 = altura
    InitWindow(1255, 723, "Bejeweled");

    //IMAGENS PARA O JOGO
    Texture2D menu = LoadTexture("perifericos/fundo.png");
    Texture2D jogo = LoadTexture("perifericos/jogo.png");
    
    Texture2D gemas[GEM];
    gemas[0] = LoadTexture("perifericos/gema1.png");
    gemas[1] = LoadTexture("perifericos/gema2.png");
    gemas[2] = LoadTexture("perifericos/gema3.png");
    gemas[3] = LoadTexture("perifericos/gema4.png");
    gemas[4] = LoadTexture("perifericos/gema5.png");
    //------------------------

    //Rectangle botaoJogar = {460, 405, 334, 80};

    int larguraTabuleiro = 800;
    int alturaTabuleiro = 435;

    int larguraGema = larguraTabuleiro / TAM;
    int alturaGema = alturaTabuleiro / TAM; 

    int inicioX = 230;
    int inicioY = 155;

    int tela = 0;

    srand(time(NULL));
    int matriz[TAM][TAM];
    int pontuacao = 0;
    jogador jogada;

    int jogo_iniciado = 0;

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);
        if (tela == 0)
        {
            
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
                     *tela = 1;
                     criar_matriz(matriz);
                     *jogo_iniciado = 1;
                   }
               }

}
        }

        else if(tela == 1)
        {
            DrawTexturePro(
                jogo,
                (Rectangle){0,0,jogo.width,jogo.height},
                (Rectangle){0,0,1255,723},
                (Vector2){0,0},
                0,
                WHITE
            );


            // Área onde as peças vão nascer
            DrawRectangleLines(
                inicioX,
                inicioY,
                larguraTabuleiro,
                alturaTabuleiro,
                RED
            );


            // Desenha as gemas dentro da área
            for(int i = 0; i < TAM; i++)
            {
                for(int j = 0; j < TAM; j++)
                {

                    int x = inicioX + j * larguraGema;
                    int y = inicioY + i * alturaGema;


                    DrawTexturePro(
                        gemas[matriz[i][j]-1],

                        // tamanho original da imagem
                        (Rectangle){0,0,48,48},

                        // tamanho que ela ocupará na tela
                        (Rectangle){
                            x,
                            y,
                            larguraGema,
                            alturaGema
                        },

                        (Vector2){0,0},
                        0,
                        WHITE
                    );

                }
            }
        }

        EndDrawing();
    }


    UnloadTexture(menu);
    UnloadTexture(jogo);
    for(int i = 0; i < GEM; i++)
    {
        UnloadTexture(gemas[i]);
    }

    CloseWindow();

    return 0;
}