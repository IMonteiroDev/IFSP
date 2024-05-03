// 1. Crie um algoritmo utilizando struct que represente um aluno com as características nome, notas para três provas, média e se está aprovado ou não. As informações devem ser preenchidas pelo usuário. Use função para calcular a média e ao final mostre uma mensagem se está aprovado ou não.

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

struct Aluno
{
    char nome[50];
    float provas[3];
    float media;
    bool aprovado;
} aluno;

void media(struct Aluno *aluno)
{
    aluno->media = (aluno->provas[0]+aluno->provas[1]+aluno->provas[2])/3;
}

void aprovado(struct Aluno *aluno){
    float media = aluno->media;

    if (media>=6)
    {
        aluno->aprovado = true;
        printf("O Aluno %s, Foi Aprovado com Média: %.2f\n",aluno->nome, media);
    }else
    {
        printf("O Aluno %s, Foi Reprovado com Média: %.2f\n",aluno->nome, media);
    }
    
}

int main()
{
    setlocale(LC_ALL, "pt-BR");
    int qtd;
    system("clear");


    printf("Bem vindo ao E.E Jeni Apprilante!\n");
    float nota = 0;
    printf("Nome Aluno:\n");
    scanf(" %s", &aluno.nome);

    for (int i = 0; i < 3; i++)
    {
        printf("Nota Prova %i:\n", i+1);
        scanf("%f", &nota);
        if (nota < 0 || nota > 10)
        {
            printf("Entrada Invalida!\n");
            i--;
        }
        else
        {
            aluno.provas[i] = nota;
        }
    }
    media(&aluno);
    aprovado(&aluno);    

    return 0;
}