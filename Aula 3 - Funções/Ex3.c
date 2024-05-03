// 3. Você foi contratado para criar um software que verifique se o cliente tem renda suficiente para conseguir aprovação para um crédito imobiliário, utilize funções para organizar melhor o código do algoritmo.

#include <stdio.h>
#include <locale.h>

float financiamento(float valor, float salario, int anos, float entrada)
{
    system("clear");
    int meses = 12 * anos;
    int aprov = 30;
    float conta, result = 0;
    conta = (valor - entrada) / meses;
    result = salario * 0.30;
    if (conta > result)
    {
        printf("O Financiamento Não Foi Aprovado!\n");
        printf("Foram Informado!\n");
        printf("Salario: R$ %.2f Reais\n", salario);
        printf("Entrada: R$ %.2f Reais\n", entrada);
        printf("Financiamento: R$ %.2f Reais\n", valor);
        printf("Parcelas: %i\n", meses);
        printf("Valor total das parcelas R$ %.2f Reais\n", conta);
    }
    else
    {
        printf("O Financiamento Foi Aprovado!\n");
        printf("Foram Informado!\n");
        printf("Salario: R$ %.2f Reais\n", salario);
        printf("Entrada: R$ %.2f Reais\n", entrada);
        printf("Financiamento: R$ %.2f Reais\n", valor);
        printf("Parcelas: %i\n", meses);
        printf("Valor total das parcelas R$ %.2f Reais\n", conta);
    }
}

int main()
{
    system("clear");
    float valor, salario, entrada = 0;
    int anos;

    printf("Bem Vindo, qual é o valor do Crédito a ser Aprovado:\n");
    scanf("%f", &valor);

    printf("Informe seu Sálario:\n");
    scanf("%f", &salario);
    printf("Informe quantos anos deseja parcelar:\n");
    scanf("%i", &anos);

    printf("Entrada: \n");
    scanf("%f", &entrada);

    if (valor < 0 && salario < 0 && entrada < 0)
    {
        printf("Entrada Invalida!");
    }
    else if (entrada == 0)
    {
        financiamento(valor, salario, anos, 0);
    }
    else
    {
        financiamento(valor, salario, anos, entrada);
    }
}