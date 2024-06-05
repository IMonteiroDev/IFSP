#ifndef CURSO.H
#define CURSO.H

typedef struct{
    char nome[250];
    char categoria[20];
    int idadeMinima;
    char requisito[250];
    int vagas;
} Curso;

typedef struct{
    char nome[250];
    int idade;
    char rg[20];
    char endereco[100];
    char diploma[50];
    char historico[100];
} Aluno;


int verificarRequisitos(Curso cursos, Aluno aluno);

void matricula(Curso *curso, Aluno aluno);

void menu();

#endif