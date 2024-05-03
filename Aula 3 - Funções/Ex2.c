// 2. Crie uma função para calcular a área de figuras geométricas, considere círculo e quadrado.

#include <stdio.h>
#include <locale.h>
#include <ctype.h>

float geometria(float tamanho, char figura)
{
    float resultado = 0;
    if (figura == 'C')
    {
        resultado = (tamanho*tamanho) * 3.14;

        printf("O Tamanho da Área do Circulo é: %.2f", resultado);
    }
    else
    {
        resultado = tamanho * tamanho;

        printf("O Tamanho da Área do Quadrado é: %.2f", resultado);
    }
    return resultado;
}

int main()
{
    setlocale(LC_ALL, "pt-BR");
    char figura;
    float tamanho = 0;
    float result;

    printf("Tamanho:\n");
    scanf("%f", &tamanho);

    printf("Qual Figura?\nC - Circulo\tQ - Quadrado\n");
    scanf(" %c", &figura);
    figura = toupper(figura);

    if (figura != 'C' && figura != 'Q' && tamanho < 0)
    {
        printf("Entrada Invalida");
    }
    result = geometria(tamanho, figura);
}