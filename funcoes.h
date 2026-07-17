#define TAM 6
#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>

void criar_matriz(int matriz[TAM][TAM]);

void mostrar_matriz(int matriz [TAM][TAM]);

typedef struct
{
    int linha;
    int coluna;
    int linha1;
    int coluna1;

} jogador;

int validar_posicao(jogador jogada);

#endif