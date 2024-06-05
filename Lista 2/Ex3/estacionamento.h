#ifndef ESTACIONAMENTO.H
#define ESTACIONAMENTO.H

#define MAX_VEIC 4
#define TAXA_CARRO_PEQUENO_SIM 3.00
#define TAXA_CARRO_PEQUENO_NAO 3.50
#define TAXA_CARRO_MEDIO_SIM 4.00
#define TAXA_CARRO_MEDIO_NAO 4.50
#define TAXA_CAMINHONETE_SIM 5.50
#define TAXA_CAMINHONETE_NAO 6.50

typedef struct{
    char tipo;
    char convenio;
    int tempo;
} Veiculo;

typedef struct{
    int numVeiculos;
    Veiculo veiculo[MAX_VEIC];
} Blocos;

void iniciarBloco(Blocos *bloco);
void estacionarVeiculo(Blocos *bloco);
void mostrarVeiculos(Blocos bloco);
float calcularValorTotal(Blocos blocoA, Blocos blocoB);


#endif