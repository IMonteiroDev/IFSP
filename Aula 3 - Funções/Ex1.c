// 1. Crie uma função para calcular a média aritmética de duas notas para os alunos.

#include <stdio.h>

float media(float n1, float n2){
    float media = (n1+n2)/2;
    return media;
}

int main(){
    float n1 = 0, n2 = 0;

    printf("Prova 1: \n");
    scanf("%f", &n1);
    printf("Prova 2: \n");
    scanf("%f", &n2);

    float resultado = media(n1,n2);
    printf("A Média do Aluno é: %.2f\n", resultado);
}