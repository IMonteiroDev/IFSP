// 2. Crie um algoritmo utilizando struct que calcule o custo de uma viagem considerando as variáveis:

// - Cidade de saída e destino;

// - Distância e custo;

// - Descrição, combustível do veículo;

// - Valor do litro do combustível e média por km que o veículo faz;

#include <stdio.h>
#include <locale.h>
#include <ctype.h>

struct Carro
{
    char descricao[150];
    char combustivel;
    float litro;
    float kmLitro;
};

struct Viagem
{
    char cidadeSaida[50];
    char cidadeDestino[50];
    float distancia;
    struct Carro carro1;
} viagem;

void valorCombustivel(struct Viagem *viagem)
{
    float custoCombustivel = 0;
    printf("Terá Gasto um valor de: ");
    
    viagem->carro1.combustivel = toupper(viagem->carro1.combustivel);

    viagem->carro1.litro = viagem->distancia / viagem->carro1.kmLitro;

    printf("\n%.2f\n", viagem->carro1.litro);
    if (viagem->carro1.combustivel == 'G')
    {
        custoCombustivel = viagem->carro1.litro * 5.31;
        printf("Gasolina R$ %.2f Reais\n", custoCombustivel);
    }
    else if (viagem->carro1.combustivel == 'A')
    {
        custoCombustivel = viagem->carro1.litro * 3.66;
        printf("Álcool: R$ %.2f Reais\n", custoCombustivel);
    }
    else
    {
        printf("Tipo de combustível inválido!\n");
    }
}

void impressao(struct Viagem *viagem)
{
    viagem->carro1.litro = 0;
    viagem->carro1.litro = viagem->distancia / viagem->carro1.kmLitro;

    printf("---------------------------------------------------------\n");
    printf("A Viagem Saindo de: %s\n", viagem->cidadeSaida);
    printf("Com destino há: %s\n", viagem->cidadeDestino);
    printf("No veiculo: %s\n", viagem->carro1.descricao);
    printf("Percorrerá uma distância de: %.fKm\n", viagem->distancia);
    printf("Com médias de: %.f Km/L\n", viagem->carro1.kmLitro);
    printf("Tendo abastecido: %.f Litros\n", viagem->carro1.litro);
    valorCombustivel(viagem);
    printf("---------------------------------------------------------\n");
}

// O Erro passado foi encontrado nessa Linha aonde a passagem como parametro na Struct encontrava-se de forma incorreta
void carro(struct Carro *carro)
{
    printf("Qual o Carro A ser Utilizado:\n");
    scanf("%s", carro->descricao);
    printf("Qual Combustivel do Veiculo?\nG - Gasolina\tA - Alcool\n");
    scanf(" %c", &carro->combustivel);
    printf("Qual a Média do Veiculo?\n");
    scanf("%f", &carro->kmLitro);
}

void informacao()
{
    carro(&viagem.carro1);

    printf("Cidade Saída:\n");
    scanf("%s", viagem.cidadeSaida);
    printf("Cidade Destino:\n");
    scanf("%s", viagem.cidadeDestino);
    printf("Distancia a ser Percorrida em KM:\n");
    scanf("%f", &viagem.distancia);

    
    system("clear");
    impressao(&viagem);
}

int main()
{

    system("clear");
    setlocale(LC_ALL, "pt-BR");

    printf("Olá, Passe a descrição\n");
    informacao();

    return 0;
}