#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "funcoes.h"

#define TAM 8

void desenharMenu(Texture2D *menu, Vector2 mouse, int *jogo_iniciado,  int *tela, int matriz[TAM][TAM]);

#endif //MENU_H