// 4. Você foi contratado para criar um software que calcule o custo da viagem dos veículos da empresa que todo dia saem para realizar as entregas e retornam ao final da tarde. O motorista entrega no final do dia uma anotação com as informações: data, km percorridos, litros abastecidos e valor total. Ao final mostre um relatório com somatório das informações.

#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

int relatorio()
{
    float kmTotal = 0, litrosAlcool = 0, litrosGasolina = 0;
    char result, resposta;
    while (1)
    {
        float kmP = 0, litros = 0;

        system("clear");
        printf("Informe Km Percorridos:\n");
        scanf("%d", &kmP);
        printf("Informe Litros Abastecidos:\n");
        scanf("%d", &litros);
        if (kmP < 0 || litros < 0)
        {
            printf("Informe uma entrada Valida!\n");
            return 0;
        }
        else
        {
            printf("\nA - Alcool\tG - Gasolina\n");
            scanf(" %c", &resposta);
            resposta = toupper(resposta);
            if (resposta != 'G' && resposta != 'A')
            {
                printf("Informe uma entrada Valida!\n");
                return 0;
            }
            else if (resposta == 'G')
            {
                kmTotal += kmP;
                litrosGasolina += litros;
            }
            else
            {
                kmTotal += kmP;
                litrosAlcool += litros;
            }
        }

        system("clear");
        printf("Informação registrada!\n");
        printf("Deseja Informar outra corrida?\nS - Sim\tN - Não\n");
        scanf(" %c", &result);
        result = toupper(result);
        if (result == 'N')
        {
            break;
        }
    }

    impressaoTotal(kmTotal, litrosAlcool, litrosGasolina);

    return 1;
}

void impressaoTotal(float kmTotal, float litrosAlcool, float litrosGasolina)
{
    float litrosTotais = litrosAlcool + litrosGasolina;
    float alcool = 2.79 * litrosAlcool;
    float gasolina = 5.19 * litrosGasolina;
    system("clear");
    printf("-------------------------------------------------------\n\n");
    printf("Relatório Final:\n");
    printf("Km Percorridos: %.f Km\n", kmTotal);
    printf("Litros Totais Abastecidos: %.2f Litros\n", litrosTotais);
    printf("Litros de Gasolina Abastecido: %.2f Litros\n", litrosGasolina);
    printf("Litros de Gasolina gastos: R$ %.2f reais\n", gasolina);
    printf("Litros de Alcool Abastecido: %.2f Litros\n", litrosAlcool);
    printf("Litros de Gasolina gastos: %.2f reais\n", gasolina);
    printf("Gastos Totais: R$ %.2f reais\n\n");
    printf("-------------------------------------------------------\n");
}

int main()
{
    system("clear");

    relatorio();
}
