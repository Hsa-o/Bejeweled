#include "raylib.h"

#define TAM 8
#define GEM 5
#define PONTOS_GEMA 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "funcoes.h"
#include "menu.h"
#include "jogo.h"
#include "fim.h"

int main(void)
{

    InitWindow(1255, 723, "Bejeweled");
    InitAudioDevice();

    Texture2D menu = LoadTexture("perifericos/fundo.png");
    Texture2D jogo = LoadTexture("perifericos/jogo.png");
    Texture2D fim = LoadTexture("perifericos/game-over.png");

    Texture2D som = LoadTexture("perifericos/unmute.png");
    Texture2D mute = LoadTexture("perifericos/mute.png");
 
    Texture2D gemas[GEM];
    gemas[0] = LoadTexture("perifericos/gema1.png");
    gemas[1] = LoadTexture("perifericos/gema2.png");
    gemas[2] = LoadTexture("perifericos/gema3.png");
    gemas[3] = LoadTexture("perifericos/gema4.png");
    gemas[4] = LoadTexture("perifericos/gema5.png");

    Sound somClique = LoadSound("perifericos/select.wav");
    Sound somJogar = LoadSound("perifericos/newArtifact.wav");
    Sound somFim = LoadSound("perifericos/newRecord.wav");

    Music musicaFundo = LoadMusicStream("perifericos/pelicano.mp3");
    PlayMusicStream(musicaFundo);
    SetMusicVolume(musicaFundo, 0.8f); 

    int larguraTabuleiro = 800;
    int alturaTabuleiro = 435;

    int larguraGema = larguraTabuleiro / TAM;
    int alturaGema = alturaTabuleiro / TAM; 

    int inicioX = 230;
    int inicioY = 155;

    int tela = 0;

    srand(time(NULL));
    
    Gema matriz[TAM][TAM];
    jogador jogada;

    int pontuacao = 0;
    int selecionada = 0;
    int linhaSelecionada = -1;
    int colunaSelecionada = -1;
    int jogo_iniciado = 0;
    int esperando = 0;
    double tempoTroca = 0;

    int somLigado = 1;

    Rectangle botaoSom = {30, 642, 50, 50};
    Rectangle botaoFim = {460, 630, 334, 80};

    while (!WindowShouldClose())
    {
        UpdateMusicStream(musicaFundo);

        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse, botaoSom))
        {
            somLigado = !somLigado;

            if (somLigado)
            {
                SetMasterVolume(0.6f);
                ResumeMusicStream(musicaFundo);
            }
            else
            {
                SetMasterVolume(0.0f);
                PauseMusicStream(musicaFundo);
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        if (tela == 0)
        {
            desenharMenu(&menu, mouse, &jogo_iniciado, &tela, matriz, &somJogar);
        }

        else if(tela == 1)
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySound(somClique);
                int coluna = (mouse.x - inicioX) / larguraGema;
                int linha = (mouse.y - inicioY) / alturaGema;

                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM)
                {
                    if (selecionada == 0)
                    {
                        jogada.linha = linha + 1;
                        jogada.coluna = coluna + 1;

                        linhaSelecionada = linha;
                        colunaSelecionada = coluna;

                        selecionada = 1;

                        printf("Primeira: %d %d\n", jogada.linha, jogada.coluna);
                    }
                    else
                    {
                        jogada.linha1 = linha + 1;
                        jogada.coluna1 = coluna + 1;

                        selecionada = 0;
                        linhaSelecionada = -1;
                        colunaSelecionada = -1;

                        printf("Segunda: %d %d\n", jogada.linha1, jogada.coluna1);

                        if (validar_posicao(jogada))
                        {
                            trocar_pecas(matriz, jogada);
                            esperando = 1;
                            tempoTroca = GetTime();

                            
                        }
                        else
                        {
                            printf("Posições inválidas\n");
                        }

                    }
                }
            }
            if (esperando)
            {
                if (GetTime() - tempoTroca >= 0.3)
                {
                    esperando = 0;

                    if (fez_trinca(matriz, jogada))
                    {
                        printf("Formou trinca!\n");

                        pontuacao += remover_trincas(matriz);

                        while (existe_trinca(matriz))
                        {
                            descer_pecas(matriz);
                            preencher_matriz(matriz);
                            pontuacao += remover_trincas(matriz);
                        }
                    }
                    else
                    {
                        printf("Sem trinca!\n");
                        trocar_pecas(matriz, jogada);
                    }
                }
            }
            if (CheckCollisionPointRec(mouse, botaoFim))
               {
                   if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                   {
                        PlaySound(somFim);
                        tela = 2;
                        jogo_iniciado = 0;
                   }
               }

            desenharJogo(&jogo, gemas, matriz, inicioX, inicioY, larguraTabuleiro, alturaTabuleiro, larguraGema, alturaGema, linhaSelecionada, colunaSelecionada, pontuacao); 
        }
        else
        desenharFim(&fim, mouse, &jogo_iniciado, &tela, &somFim);

        if (somLigado)
        {
            DrawTexturePro(
                som,
                (Rectangle){0, 0, som.width, som.height},
                botaoSom,
                (Vector2){0,0},
                0,
                WHITE
            );
        }
        else
        {
            DrawTexturePro(
                mute,
                (Rectangle){0, 0, mute.width, mute.height},
                botaoSom,
                (Vector2){0,0},
                0,
                WHITE
            );
        }
        
        EndDrawing();
    }


    UnloadTexture(menu);
    UnloadTexture(jogo);
    UnloadTexture(fim);

    for(int i = 0; i < GEM; i++)
    {
        UnloadTexture(gemas[i]);
    }
    
    UnloadSound(somJogar);
    UnloadSound(somClique);
    UnloadSound(somFim);
    StopMusicStream(musicaFundo);
    UnloadMusicStream(musicaFundo);
    UnloadTexture(som);
    UnloadTexture(mute);

    CloseAudioDevice();

    CloseWindow();

    return 0;
}