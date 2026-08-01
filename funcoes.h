#define TAM 8
#define GEM 5
#ifndef FUNCOES_H
#define FUNCOES_H

#include "raylib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
    Texture2D textura;
    Vector2 posicao;
    int tipo;
    Rectangle caixa;

} Gema;

void criar_matriz(Gema matriz[TAM][TAM]);

void mostrar_matriz(Gema matriz [TAM][TAM]);

typedef struct
{
    int linha;
    int coluna;
    int linha1;
    int coluna1;

} jogador;

void trocar_pecas(Gema matriz[TAM][TAM], jogador jogada);

int validar_posicao(jogador jogada);


int fez_trinca(Gema matriz[TAM][TAM], jogador jogada);

int remover_trincas(Gema matriz[TAM][TAM]);

void descer_pecas(Gema matriz[TAM][TAM]);

void preencher_matriz(Gema matriz[TAM][TAM]);

int existe_trinca(Gema matriz[TAM][TAM]);

int existe_jogada(Gema matriz[TAM][TAM]);

#endif