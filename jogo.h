#ifndef JOGO_H
#define JOGO_H

#include "raylib.h"
#include "funcoes.h"

void desenharJogo(Texture2D *jogo, Texture2D gemas[GEM], Gema matriz[TAM][TAM], int inicioX, int inicioY, int larguraTabuleiro, int alturaTabuleiro, int larguraGema, int alturaGema, int linhaSelecionada, int colunaSelecionada, int pontuacao);

#endif //JOGO_H