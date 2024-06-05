#include "investimento.h"


void calcularSaldo(Investimento *investimento, float saldoInicial, int mes){
    investimento->saldoInicial = saldoInicial;
    investimento->saldoAtual = investimento->saldoInicial;
    for (int i = 0; i < mes; i++)
    {
        investimento->saldoAtual*=(1+investimento->taxaJuros);
    }
}
