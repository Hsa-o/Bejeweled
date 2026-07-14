#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criar_matriz(int matriz[3][3]){
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = (rand() % 5)+1;
        }
    }
}

void mostrar_matriz(int matriz [3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void posicao_troca(int matriz[3][3]){

    int linha, coluna, linha1, coluna1;
    printf("Linha da troca, coluna da troca:\n");
    scanf("%d%d", &linha, &coluna);
    
    printf("Linha da troca, coluna da troca:\n");
    scanf("%d%d", &linha1, &coluna1);

    //Tópico descartavel--------------------------
    printf("===================\n");
    printf("Valor na matriz: %d", matriz[linha-1][coluna-1]);
    printf("\n");
    printf("Valor na matriz: %d\n=================\n", matriz[linha1-1][coluna1-1]);
    //--------------------------------------------

    //se linha e coluna diferente de 1-4, error!

    int copia_pos1 = matriz[linha-1][coluna-1];
    matriz[linha-1][coluna-1] = matriz[linha1-1][coluna1-1];
    matriz[linha1-1][coluna1-1] = copia_pos1;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
 
int main (){
    int matriz[3][3];
    criar_matriz(matriz);
    mostrar_matriz(matriz);
    posicao_troca(matriz);
    
    return 0;
}
