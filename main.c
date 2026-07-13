#include <stdio.h>
#include "funcoes.h"

int main(){

    int x, y;

    printf("Digite dois numeros: ");
    scanf("%d%d",&x,&y);

    printf("Soma = %d\n", soma(x,y));
    printf("Subtracao = %d\n", subtracao(x,y));
    printf("Multiplicacao = %d\n", multiplicacao(x,y));
    printf("Divisao = %.2f\n", divisao(x,y));

    return 0;
}