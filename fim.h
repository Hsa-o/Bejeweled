#ifndef FIM_H
#define FIM_H

#define TAM 8
#include "funcoes.h"

#include "raylib.h"

void desenharFim(Texture2D *fim, Vector2 mouse, int *jogo_iniciado,  int *tela, Sound *somFim, Gema matriz[TAM][TAM], int *pontuacao);

#endif //FIM_H