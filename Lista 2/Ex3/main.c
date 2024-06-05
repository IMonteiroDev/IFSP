// Desenvolva um sistema para o estacionamento de carros que fica no centro da cidade, você deve considerar que o estacionamento possui 2 blocos(A, B) para estacionar, sendo que, o cliente pode escolher o bloco caso tenha vaga disponível para estacionar. Utilize a tabela abaixo para calcular os valores:

// Veículo	    Valor por hora	Convênio
// Carro peq.	R$ 3,00	        Sim
// Carro peq.	R$ 3,50	        Não
// Carro méd.	R$ 4,00	        Sim
// Carro méd	R$ 4,50	        Não
// Caminhonete	R$ 5,50	        Sim
// Caminhonete	R$ 6,50	        Não

// Caso o veículo estacionado (qualquer modelo) fique mais de 3 horas tem um desconto de 10%.

// gcc main.c estacionamento.c -o estac && estac

#include <stdio.h>
#include <locale.h>
#include "estacionamento.h"

int main()
{
    Blocos blocoA, blocoB;
    float valorTotal;

    iniciarBloco(&blocoA);
    iniciarBloco(&blocoB);
    
    system("cls");
    int escolhaBloco;
    while (1)
    {
        printf("Escolha o Bloco para Estacionar:\n1 - Bloco A\t2 - Bloco B\t0 - Sair\n");
        scanf("%d", &escolhaBloco);

        if (escolhaBloco == 0)
        {
            break;
        }
        switch (escolhaBloco)
        {
        case 1:
            estacionarVeiculo(&blocoA);
            break;

        case 2:
            estacionarVeiculo(&blocoA);
            break;

        default:
            printf("Escolha Inválida!\n");
        }
    }

    system("cls");
    printf("\n");
    printf("Bloco A:\n");
    mostrarVeiculos(blocoA);

    printf("\n");
    printf("Bloco B:\n");
    mostrarVeiculos(blocoB);

    valorTotal = calcularValorTotal(blocoA, blocoB);

    printf("\nO Valor total recebido com todas as saídas é R$%.2f reais\n", valorTotal);

    return 0;
}