#include "funcoes.h"

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