/*
2 - Crie um algoritmo em C para calcular a média aritmética de 5 alunos, o Algoritmo deve solicitar a primeira e segunda nota. Por fim calcular a média para cada aluno e exibir os alunos aprovados e reprovados se a Media for maior que 6.

*/

#include <stdio.h>
#include<stdlib.h>

int main(){
    float prov1, prov2, media, aprov, reprov;

    for (int i = 0; i < 5; i++)
    {
        fflush(stdin);

        printf("Informe a Primeira Nota:\n");
        scanf("%f", &prov1);

        printf("Informe a Segunda Nota:\n");
        scanf("%f", &prov2);

        media= (prov1+prov2)/2;


        if (media >=6)
        {
            printf("Você Foi Aprovado!\n");
            printf("Com média %.2f\n", media);
            aprov++;
        }
        else{
            printf("Você Foi Reprovado!\n");
            printf("Com média %.2f\n", media);
            reprov++;
        }
    }

    printf("Foram aprovados: %.f\n", aprov);
    printf("E Reprovado %.f\n", reprov);
    
}