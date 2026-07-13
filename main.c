#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criar_matriz(int matriz[8][8]){
    srand(time(NULL));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            matriz[i][j] = (rand() % 5)+1;
        }
    }
}
void mostrar_matriz(int matriz [8][8]){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int matriz [8][8];
    criar_matriz(matriz);
    mostrar_matriz(matriz);
    return 0;
}   