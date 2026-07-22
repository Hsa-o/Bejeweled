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

void trocar_pecas(int matriz[TAM][TAM], jogador jogada);

int validar_posicao(jogador jogada);

int verificar_horizontal(int matriz[TAM][TAM], int linha);

int verificar_vertical(int matriz[TAM][TAM], int coluna);

int trinca(int matriz[TAM][TAM], jogador jogada);

void remover_trincas(int matriz[TAM][TAM]);

void cascata(int matriz[TAM][TAM]);

void preencher(int matriz[TAM][TAM]);

int existe_trinca(int matriz[TAM][TAM]);

#endif