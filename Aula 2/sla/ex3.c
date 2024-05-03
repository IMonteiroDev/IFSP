/*
Crie um algoritmo em C para pizzaria, considerando informações de cardápio e setor entrega o Algoritmo deve perguntar quantas vendas foram executadas. Ao final mostrar um relatório com o total de vendas do dia.

Indice  |Sabor       | Individual    | 8 pedaços | 12 pedaços    |
1       |Mussarela   |   24,90       |   39,90   |   49,90       |
2       |Frango      |   26,90       |   49,90   |   59,90       |
3       |Marguerita  |   28,90       |   54,90   |   64,90       |
4       |Calabresa   |   29,90       |   56,90   |   66,90       |
5       |FranBacon   |   31,90       |   61,90   |   71,90       |

Setor   |   Entrega     |
1       |   9,90        |
2       |   14,90       |
3       |   17,90       |
4       |   21,90       |

*/

#include <stdio.h>

int main(){
    float vendaDia;
    int indice, setor;
    int pedido[5]= {0, 0, 0, 0, 0};
    char tamanho;

    printf("Olá, Bem vinda a Pizzaria TUTU\nSegue abaixo o Cardápio\n\n");
    do
    {
        float valorTotal;

        printf("Indice  | Sabor       | Individual    | 8 pedaços | 12 pedaços    |\n\
1       |Mussarela   |   24,90       |   39,90   |   49,90       |\n\
2       |Frango      |   26,90       |   49,90   |   59,90       |\n\
3       |Marguerita  |   28,90       |   54,90   |   64,90       |\n\
4       |Calabresa   |   29,90       |   56,90   |   66,90       |\n\
5       |FranBacon   |   31,90       |   61,90   |   71,90       |\n\
            ");
    printf("Qual o Pedido:\n");
    scanf("%i", &indice);

    switch (indice)
    {
    case 1:
        printf("Qual o tamanho?\n");
        scanf("%c", &tamanho);

        if (tamanho='i')
        {
            valorTotal+=24.90;
        
        }else if (tamanho='8')
        {
            valorTotal+=39.90;
        }
        else if (tamanho='12')
        {
            valorTotal+=49.90;
        }
        else{
            printf("Erro, Opção Invalido\n");
        }
        
        pedido[1]++;

        break;

    case 2:
        printf("Qual o tamanho?\n");
        scanf("%c", &tamanho);

        if (tamanho='i')
        {
            valorTotal+=26.90;
        
        }else if (tamanho='8')
        {
            valorTotal+=49.90;
        }
        else if (tamanho='12')
        {
            valorTotal+=59.90;
        }
        else{
            printf("Erro, Opção Invalido\n");
        }
        pedido[2]++;

    case 3:
        printf("Qual o tamanho?\n");
        scanf("%c", &tamanho);

        if (tamanho='i')
        {
            valorTotal=28.90;
        
        }else if (tamanho='8')
        {
            valorTotal+=54.90;
        }
        else if (tamanho='12')
        {
            valorTotal+=64.90;
        }
        else{
            printf("Erro, Opção Invalido\n");
        }
        pedido[3]++;

    case 4:
        printf("Qual o tamanho?\n");
        scanf("%c", &tamanho);

        if (tamanho='i')
        {
            valorTotal=29.90;
        
        }else if (tamanho='8')
        {
            valorTotal+=56.90;
        }
        else if (tamanho='12')
        {
            valorTotal+=66.90;
        }
        else{
            printf("Erro, Opção Invalido\n");
        }
        pedido[4]++;

    case 5:
        printf("Qual o tamanho?\n");
        scanf("%c", &tamanho);

        if (tamanho='i')
        {
            valorTotal=31.90;
        
        }else if (tamanho='8')
        {
            valorTotal+=61.90;
        }
        else if (tamanho='12')
        {
            valorTotal+=71.90;
        }
        else{
            printf("Erro, Opção Invalido\n");
        }
        pedido[5]++;
    
    default:
        break;
    }

    printf("\n\
Setor   |   Entrega     |\n\
1       |   9,90        |\n\
2       |   14,90       |\n\
3       |   17,90       |\n\
4       |   21,90       |\n\
");
    
    printf("\n");
    printf("Para aonde entregar?\n");
    scanf("%i", &setor);

    switch (setor)
    {
    case 1:
        valorTotal+=9.9;
        break;
    
    case 2:
        valorTotal+=14.90;
        break;
    
    case 3:
        valorTotal+=17.90;
        break;
    
    case 4:
        valorTotal+=21.90;
        break;
    
    default:
        printf("Erro. Código Incorreto!\n");
        break;
    }

    valorTotal+=vendaDia;
    } while (indice = 's');
    
    system("clear");
    
    printf("O Valor Total de Hoje foi : R$ %.2f", vendaDia);

}