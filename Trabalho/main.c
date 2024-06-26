
// gcc main.c biblioteca.c -o bibliotec && bibliotec

#include "biblioteca.h"
#include <stdio.h>

int main()
{
    Autor *autores = NULL;
    Livro *livros = NULL;
    Usuario *usuarios = NULL;

    printf("Bem Vindo!!\n");

    int opcao;
    
    adicionarAutoresPredefinidos(&autores);
    adicionarLivrosPredefinidos(&livros, autores);
    
        limpar();
    do
    {
        printf("\nMenu:\n");
        printf("1. Adicionar Autor\n");
        printf("2. Adicionar Livro\n");
        printf("3. Adicionar Usuário\n");
        printf("4. Listar Autores\n");
        printf("5. Listar Livros\n");
        printf("6. Listar Usuários\n");
        printf("7. Emprestar Livro\n");
        printf("8. Devolver Livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            int id;
            char nome[MAX_NOME];
            printf("Digite o ID do autor: ");
            scanf("%d", &id);
            printf("Digite o nome do autor: ");
            scanf(" %[^\n]", nome); // Lê a string com espaços
            autores = addAutor(autores, id, nome);
            break;
        }
        case 2:
        {
            int id, autorId;
            char titulo[MAX_TITULO];
            printf("Digite o ID do livro: ");
            scanf("%d", &id);
            printf("Digite o título do livro: ");
            scanf(" %[^\n]", titulo); // Lê a string com espaços
            printf("Digite o ID do autor: ");
            scanf("%d", &autorId);

            // Encontrar o autor pelo ID
            Autor *autor = autores;
            while (autor != NULL && autor->id != autorId)
            {
                autor = autor->prox;
            }

            if (autor == NULL)
            {
                printf("Autor não encontrado!\n");
            }
            else
            {
                livros = addLivro(livros, id, titulo, autor);
            }
            break;
        }
        case 3:
        {
            int id;
            char nome[MAX_NOME];
            printf("Digite o ID do usuário: ");
            scanf("%d", &id);
            printf("Digite o nome do usuário: ");
            scanf(" %[^\n]", nome); // Lê a string com espaços
            usuarios = addUsuario(usuarios, id, nome);
            break;
        }
        case 4:
            printf("\nAutores:\n");
            listaAutor(autores);
            break;
        case 5:
            printf("\nLivros:\n");
            listarLivros(livros);
            break;
        case 6:
            printf("\nUsuários:\n");
            listarUsuario(usuarios);
            break;
        case 7:
        {
            int livroId;
            printf("Digite o ID do livro para emprestar: ");
            scanf("%d", &livroId);
            emprestimoLivro(livros, livroId);
            break;
        }
        case 8:
        {
            int livroId;
            printf("Digite o ID do livro para devolver: ");
            scanf("%d", &livroId);
            devolucao(livros, livroId);
            break;
        }
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
