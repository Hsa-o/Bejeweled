#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criar_matriz(int matriz[4][4]){
      for (int i = 0; i < 4; i++)
      {
        for (int j = 0; j < 4; j++)
        {
            do
            {
                matriz[i][j] = rand() % 5 + 1;

            } 
            while (
                (j >= 2 &&
                 matriz[i][j] == matriz[i][j-1] &&
                 matriz[i][j] == matriz[i][j-2])

                ||

                (i >= 2 &&
                 matriz[i][j] == matriz[i-1][j] &&
                 matriz[i][j] == matriz[i-2][j])
            );
        }
    }
}

void mostrar_matriz(int matriz [4][4]){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void posicao_troca(int matriz[4][4]){
    
    int linha, coluna, linha1, coluna1;
    
    printf("Linha da troca, coluna da troca:\n");
    scanf("%d%d", &linha, &coluna);
    
    printf("Linha da troca, coluna da troca:\n");
    scanf("%d%d", &linha1, &coluna1);
    
    //se linha e coluna diferente de 1-4, error!
        
    //Tópico descartavel--------------------------
    printf("===================\n");
    printf("Valor na matriz: %d", matriz[linha-1][coluna-1]);
    printf("\n");
    printf("Valor na matriz: %d\n=================\n", matriz[linha1-1][coluna1-1]);
    //--------------------------------------------
        
    int copia_pos1 = matriz[linha-1][coluna-1];
    matriz[linha-1][coluna-1] = matriz[linha1-1][coluna1-1];
    matriz[linha1-1][coluna1-1] = copia_pos1;
    
    mostrar_matriz(matriz);
}

int main (){

    srand(time(NULL));
    int matriz[4][4];
    
    criar_matriz(matriz);
    mostrar_matriz(matriz);
    posicao_troca(matriz);
    
    return 0;
}
