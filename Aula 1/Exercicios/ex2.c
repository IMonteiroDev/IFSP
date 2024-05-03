// Você precisa desenvolver um algoritmo para aprovar o financiamento imobiliário, sendo que o valor da parcela não pode ser maior que 30% do salário da pessoa

#include <stdio.h>
#include <stdlib.h>

int main(){
    int anos;
    float salario, financiamento, parcelas, valor, aprov = 0;
    float result;

    fflush(stdin);
    printf("Informe o Valor do Sálario:\n");
    scanf("%f", &salario);

    printf("Valor Financiamento:\n");
    scanf("%f", &financiamento);

    printf("Informe a quantidade de parcelas:\n");
    scanf("%f", &parcelas);

    valor = salario*0.3;
    aprov = financiamento/parcelas;


    if (aprov>valor)
    {
        printf("Desculpa, Seu financiamento foi Reprovado!\n");
    }
    else{
        anos = parcelas/12;
        system("clear");
        printf("--------- Financiamento ---------\n");
        printf("Valor Requisitado: R$ %.2f\n", financiamento);
        printf("Quantidade de Parcelas: %i anos\n", anos);
        printf("Valor de cada Parcela: R$ %.2f\n", aprov);
    }

    return 0;
}