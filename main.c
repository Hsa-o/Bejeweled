#include <stdio.h>

void posicao_troca(int matriz[3][3]){
    int linha, linha1, coluna, coluna1;
    printf("Linha, coluna: ");
    scanf("%d%d", &linha, &coluna);
    
    printf("Linha, coluna: ");
    scanf("%d%d", &linha1, &coluna1);
    printf("===================\n");
    
    printf("%d", matriz[linha-1][coluna-1]);
    printf("\n");
    printf("%d\n=================\n", matriz[linha1-1][coluna1-1]);
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
void troca(int matriz[3][3]){
    
    
}
int main (){
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 3},
        {7, 3, 9}
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    posicao_troca(matriz);
    
    return 0;
}
