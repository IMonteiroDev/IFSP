#include "estacionamento.h"
#include <ctype.h>

void iniciarBloco(Blocos *bloco){
    bloco->numVeiculos = 0;
}

void estacionarVeiculo(Blocos *bloco){
    char tipo, convenio;
    if (bloco->numVeiculos < MAX_VEIC) {
        Veiculo novoVeiculo;
        printf("Digite o tipo do veículo>\nP - Carro Pequeno\nM - Carro Médio\nC - Caminhonete\n");
        scanf(" %c", &tipo);
        novoVeiculo.tipo = toupper(tipo);

        printf("O cliente possui convênio?\nS - Sim\tN - Não\n");
        scanf(" %c", &convenio);
        novoVeiculo.convenio = toupper(convenio);

        printf("Digite o tempo de permanência em horas:\n");
        scanf("%d", &novoVeiculo.tempo);
        bloco->veiculo[bloco->numVeiculos] = novoVeiculo;
        bloco->numVeiculos++;
        printf("Veículo Estacionado.\n");
        
    } else {
        system("cls");
        printf("O bloco está lotado, não há vagas.\n");
    }
}

void mostrarVeiculos(Blocos bloco){
    printf("Veículos estacionados no bloco:\n");
    for (int i = 0; i < bloco.numVeiculos; i++)
    {
        printf("Veículo %d: Tipo: %c, Convênio: %c, Tempo de Permanência: %d horas\n", i + 1, bloco.veiculo[i].tipo, bloco.veiculo[i].convenio, bloco.veiculo[i].tempo);
    }
}

float calcularValorTotal(Blocos blocoA, Blocos blocoB) {
    float valorTotal = 0;
    for (int i = 0; i < blocoA.numVeiculos; i++) {
        float valorHora;
        switch (blocoA.veiculo[i].tipo) {
            case 'P':
                valorHora = (blocoA.veiculo[i].convenio == 'S') ? TAXA_CARRO_PEQUENO_SIM : TAXA_CARRO_PEQUENO_NAO;
                break;
            case 'M':
                valorHora = (blocoA.veiculo[i].convenio == 'S') ? TAXA_CARRO_MEDIO_SIM : TAXA_CARRO_MEDIO_NAO;
                break;
            case 'C':
                valorHora = (blocoA.veiculo[i].convenio == 'S') ? TAXA_CAMINHONETE_SIM : TAXA_CAMINHONETE_NAO;
                break;
            default:
                printf("Tipo de veículo inválido!\n");
                return 0;
        }
        float valorParcial = valorHora * blocoA.veiculo[i].tempo;
        if (blocoA.veiculo[i].tempo > 3) {
            valorParcial *= 0.9; // Desconto de 10% será aplicado
        }
        valorTotal += valorParcial;
    }
    for (int i = 0; i < blocoB.numVeiculos; i++) {
        float valorHora;
        switch (blocoB.veiculo[i].tipo) {
            case 'P':
                valorHora = (blocoB.veiculo[i].convenio == 'S') ? TAXA_CARRO_PEQUENO_SIM : TAXA_CARRO_PEQUENO_NAO;
                break;
            case 'M':
                valorHora = (blocoB.veiculo[i].convenio == 'S') ? TAXA_CARRO_MEDIO_SIM : TAXA_CARRO_MEDIO_NAO;
                break;
            case 'C':
                valorHora = (blocoB.veiculo[i].convenio == 'S') ? TAXA_CAMINHONETE_SIM : TAXA_CAMINHONETE_NAO;
                break;
            default:
                printf("Tipo de veículo inválido!\n");
                return 0;
        }
        float valorParcial = valorHora * blocoB.veiculo[i].tempo;
        if (blocoB.veiculo[i].tempo > 3) {
            valorParcial *= 0.9; // Desconto de 10% será aplicado
        }
        valorTotal += valorParcial;
    }
    return valorTotal;
}
