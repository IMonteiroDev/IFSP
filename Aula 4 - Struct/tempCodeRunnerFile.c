// 1. Crie um algoritmo utilizando struct que represente um aluno com as características nome, notas para três provas, média e se está aprovado ou não. As informações devem ser preenchidas pelo usuário. Use função para calcular a média e ao final mostre uma mensagem se está aprovado ou não.

#include <stdio.h>
#include <locale.h>

struct Aluno
{
    char nome[50];
    float provas[3];
    float media;
} aluno;

void media()
{
    for (int i = 0; i < 3; i++)
    {
        aluno.media += aluno.provas[i];
    }

    aluno.media = aluno.media / 3;

    if (aluno.media >= 6)
    {
        printf("O Aluno %c, foi Aprovado com Média %.2f\n");
    }
    else
    {
        printf("O Aluno %c, foi Reprovado com Média %.2f\n");
    }
}

int main()
{
    setlocale(LC_ALL, "pt-BR");
    int qtd;

    printf("Bem vindo ao E.E Jeni Apprilante!\n");
    float nota = 0;
    printf("Nome Aluno:\n");
    scanf(" %c", &aluno.nome);

    for (int i = 0; i < 3; i++)
    {
        printf("Nota Prova 1:\n");
        scanf("%f", &nota);
        if (nota < 0 || nota > 10)
        {
            printf("Entrada Invalida!\n");
            return;
        }
        else
        {
            aluno.provas[i] = nota;
        }
    }
    media();

    return 0;
}