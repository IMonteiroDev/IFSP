#include "curso.h"
#include <stdio.h>
#include <string.h>

// Preenchendo os Cursos

Curso cursos[] = {
    {"Técnicas de impressão 3D", "Aperfeiçoamento", 16, "Conhecimento em software AutoCAD", 10},
    {"Lógica de programação com microcontroladores", "Aperfeiçoamento", 14, "Nenhum", 10},
    {"Técnico em química", "Técnico", 16, "Nenhum", 10},
    {"Técnico em administração", "Técnico", 16, "Nenhum", 10},
    {"Técnico em informática", "Técnico", 16, "Nenhum", 10},
    {"Engenharia mecânica", "Graduação", 0, "Diploma ensino médio, Histórico escolar", 10},
    {"Engenharia florestal", "Graduação", 0, "Diploma ensino médio, Histórico escolar", 10},
    {"Licenciatura em física", "Graduação", 0, "Diploma ensino médio, Histórico escolar", 10},
};

int numCursos = sizeof(cursos)/sizeof(Curso);

int verificarRequisitos(Curso cursos, Aluno aluno){
    if (aluno.idade < cursos.idadeMinima) {
        return 0;
    }
    if (strcmp(cursos.categoria, "Graduação") == 0) {
        if (strlen(aluno.diploma) == 0 || strlen(aluno.historico) == 0) {
            return 0;
        }
    }
    return 1;
}

void matricula(Curso *cursos, Aluno aluno){
    if (cursos->vagas > 0 && verificarRequisitos(*cursos, aluno)) {
        cursos->vagas--;
        system("cls");
        printf("Matrícula realizada com sucesso!\n");
    } else {
        printf("Não foi possível realizar a matrícula. Verifique os requisitos e a disponibilidade de vagas.\n");
    }
}

void menu() {
    int opcao;
    Aluno aluno;
    int cursoSelecionado;
    char buffer[100]; // Buffer temporário para limpar o buffer de entrada

    while (1) {
        printf("Menu:\n");
        printf("1. Listar cursos\n");
        printf("2. Matricular aluno\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o caractere de nova linha do buffer de entrada

        switch (opcao) {
            case 1:
                for (int i = 0; i < numCursos; i++) {
                    printf("%d. %s (%s) - Vagas: %d\n", i + 1, cursos[i].nome, cursos[i].categoria, cursos[i].vagas);
                }
                break;
            case 2:
                printf("Informe o nome do aluno: ");
                fgets(aluno.nome, sizeof(aluno.nome), stdin);
                aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; // Remove o caractere de nova linha

                printf("Informe a idade do aluno: ");
                scanf("%d", &aluno.idade);

                getchar(); // Limpa o caractere de nova linha do buffer de entrada

                printf("Informe o RG do aluno: ");
                fgets(aluno.rg, sizeof(aluno.rg), stdin);
                aluno.rg[strcspn(aluno.rg, "\n")] = '\0';

                printf("Informe o endereço do aluno: ");
                fgets(aluno.endereco, sizeof(aluno.endereco), stdin);
                aluno.endereco[strcspn(aluno.endereco, "\n")] = '\0';
                
                printf("Escolha o curso para matrícula:\n");
                for (int i = 0; i < numCursos; i++) {
                    printf("%d. %s\n", i + 1, cursos[i].nome);
                }
                printf("Opção: ");
                scanf("%d", &cursoSelecionado);
                getchar();
                
                cursoSelecionado--; // Ajusta o índice para começar em 0

                if (cursoSelecionado >= 0 && cursoSelecionado < numCursos) {
                    if (aluno.idade < cursos[cursoSelecionado].idadeMinima) {
                        system("cls");
                        printf("O aluno não atende à idade mínima para este curso.\n");
                    } else {
                        if (strcmp(cursos[cursoSelecionado].categoria, "Graduação") == 0) {
                            printf("Informe o diploma do aluno: ");
                            fgets(aluno.diploma, sizeof(aluno.diploma), stdin);
                            aluno.diploma[strcspn(aluno.diploma, "\n")] = '\0'; // Remove o caractere de nova linha
                            printf("Informe o histórico escolar do aluno: ");
                            fgets(aluno.historico, sizeof(aluno.historico), stdin);
                            aluno.historico[strcspn(aluno.historico, "\n")] = '\0'; // Remove o caractere de nova linha
                        }
                        matricula(&cursos[cursoSelecionado], aluno);
                    }
                } else {
                    printf("Opção inválida.\n");
                }
                break;
            case 3:
                return;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
}