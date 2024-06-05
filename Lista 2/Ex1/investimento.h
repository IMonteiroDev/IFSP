#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

typedef struct{
    char nome[50];
    float saldoInicial;
    float saldoAtual;
    double taxaJuros;
} Investimento;

void calcularSaldo(Investimento *investimento, float saldoInicial, int mes);

#endif