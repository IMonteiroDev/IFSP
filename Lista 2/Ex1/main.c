// Desenvolva um simulador de investimentos que permita ao usuário escolher diferentes opções de investimentos (ações, poupança, etc.), calcular retornos ao longo do tempo com base em taxas de juros variáveis.

//gcc main.c investimento.c -o invest && invest

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "investimento.h"

void telaInformacao()
{
    printf("Escolha o tipo de investimento:\n");
    printf("1. Poupança\n");
    printf("2. Ações\n");
    printf("3. Tesouro Direto\n");
    printf("4. Selic\n");
    printf("5. Fundo imobiliário\n");
    printf("Informe uma Opção:\n");
}

int main()
{
    setlocale(LC_ALL, "pt-BR");
    Investimento investimentos[5];
    float saldoInicial;
    int opcao, mes;
    system("cls");

    strcpy(investimentos[0].nome, "Poupança");
    investimentos[0].taxaJuros = 0.0058;

    strcpy(investimentos[1].nome, "Ações");
    investimentos[1].taxaJuros = 0.001;

    strcpy(investimentos[2].nome, "Tesouro Direto");
    investimentos[2].taxaJuros = 0.0084;

    strcpy(investimentos[3].nome, "Selic");
    investimentos[3].taxaJuros = 0.0089;

    strcpy(investimentos[4].nome, "Fundo imobiliário");
    investimentos[4].taxaJuros = 0.0075;
    telaInformacao();
    scanf("%d", &opcao);
    printf("Digite a quantidade de meses para simular:\n");
    scanf("%d", &mes);
    printf("Informe um valor para simular:\n");
    scanf("%f", &saldoInicial);

    if ((opcao < 1 || opcao > 4) && saldoInicial > 0)
    {
        printf("Opção Invalida!\n");
        return 1;
    }

    opcao--; // utilizado para deixar no mesmo nivel do Array

    calcularSaldo(&investimentos[opcao], saldoInicial, mes);

    printf("\nApós %d meses, o saldo do investimento em %s foi: \n", mes, investimentos[opcao].nome);
    printf("Saldo Inicial: R$ %.2f\n", investimentos[opcao].saldoInicial);
    printf("Saldo Final: R$ %.2f\n", investimentos[opcao].saldoAtual);
    printf("Saldo Com Juros Mensais de: R$ %.4f\n", investimentos[opcao].taxaJuros);

    return 0;
}