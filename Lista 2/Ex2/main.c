// Desenvolva um sistema para auxiliar a escola no controle de matrículas dos cursos, atualmente a escola trabalha com as categorias dos cursos: aperfeiçoamento, técnico e graduação. Considere a documentação necessária abaixo para cada categoria de curso:

// Aperfeiçoamento: RG, Comprovante de endereço, idade mínima (depende do curso), requisitos (depende do curso);
// Técnico: RG, Comprovante de endereço, idade mínima 16 anos
// Graduação: RG, Comprovante de endereço, diploma ensino médio, histórico escolar;
// Atualmente a escola está ofertando os seguintes cursos:

// Aperfeiçoamento:
// Técnicas de impressão 3D: (16 anos, conhecimento em software AutoCAD);
// Lógica de programação com microcontroladores: (14 anos, nenhum);

// Técnicos:
// Técnico em química;
// Técnico em administração;
// Técnico em informática;

// Graduação:
// Engenharia mecânica;
// Engenharia florestal;
// Licenciatura em física;

// A todo momento novas pessoas procuram a escola para realizar matrícula e o atendente precisa verificar se ainda existem matrículas disponíveis para o curso desejado.

// gcc main.c curso.c -o matricula && matricula

#include "curso.h"
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "pt-BR");
    system("cls");
    menu();
    return 0;
}

