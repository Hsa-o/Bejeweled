#define TAM 6
#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>

void criar_matriz(int matriz[TAM][TAM]);

void mostrar_matriz(int matriz [TAM][TAM]);
void mostrar_matriz_com_marcador(int matriz[TAM][TAM], int novo[TAM][TAM]);

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

int remover_trincas(int matriz[TAM][TAM]);
void aplicar_gravidade(int matriz[TAM][TAM]);
void preencher_matriz(int matriz[TAM][TAM], int novo[TAM][TAM]);
int existe_trinca(int matriz[TAM][TAM]);

#endif