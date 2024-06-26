#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar()
{
    system("cls");
}

// Create
Autor *addAutor(Autor *head, int id, char *nome)
{
    Autor *novoAutor = (Autor *)malloc(sizeof(Autor));
    novoAutor->id = id;
    strcpy(novoAutor->nome, nome);
    novoAutor->prox = head;
    return novoAutor;
}

Livro *addLivro(Livro *head, int id, char *titulo, Autor *autor)
{
    Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
    novoLivro->id = id;
    strcpy(novoLivro->titulo, titulo);
    novoLivro->autor = autor;
    novoLivro->disponivel = 1;
    novoLivro->prox = head;
    return novoLivro;
}

Usuario *addUsuario(Usuario *head, int id, const char *nome)
{
    Usuario *novoUsuario = (Usuario *)malloc(sizeof(Usuario));
    novoUsuario->id = id;
    strcpy(novoUsuario->nome, nome);
    novoUsuario->prox = head;
    return novoUsuario;
}

void adicionarLivrosPredefinidos(Livro **livros, Autor *autores)
{
    *livros = addLivro(*livros, 1, "1984", autores);
    *livros = addLivro(*livros, 2, "O Grande Gatsby", autores);
    *livros = addLivro(*livros, 3, "Dom Quixote", autores);
    *livros = addLivro(*livros, 4, "Moby Dick", autores);
    *livros = addLivro(*livros, 5, "Hamlet", autores);
    *livros = addLivro(*livros, 6, "A Odisseia", autores);
    *livros = addLivro(*livros, 7, "Orgulho e Preconceito", autores);
    *livros = addLivro(*livros, 8, "Guerra e Paz", autores);
    *livros = addLivro(*livros, 9, "A Divina Comédia", autores);
    *livros = addLivro(*livros, 10, "Ulisses", autores);

    *livros = addLivro(*livros, 11, "Estruturas de Dados e Algoritmos em C", autores->prox);
    *livros = addLivro(*livros, 12, "Código Limpo", autores->prox);
    *livros = addLivro(*livros, 13, "O Programador Pragmático", autores->prox);
    *livros = addLivro(*livros, 14, "Projeto de Compiladores", autores->prox);
    *livros = addLivro(*livros, 15, "Padrões de Projetos", autores->prox);
}

void adicionarAutoresPredefinidos(Autor **autores)
{
    *autores = addAutor(*autores, 1, "George Orwell");
    *autores = addAutor(*autores, 2, "F. Scott Fitzgerald");
    *autores = addAutor(*autores, 3, "Miguel de Cervantes");
    *autores = addAutor(*autores, 4, "Herman Melville");
    *autores = addAutor(*autores, 5, "William Shakespeare");
    *autores = addAutor(*autores, 6, "Homero");
    *autores = addAutor(*autores, 7, "Jane Austen");
    *autores = addAutor(*autores, 8, "Liev Tolstói");
    *autores = addAutor(*autores, 9, "Dante Alighieri");
    *autores = addAutor(*autores, 10, "James Joyce");
    *autores = addAutor(*autores, 11, "Mark Allen Weiss");
    *autores = addAutor(*autores, 12, "Robert C. Martin");
    *autores = addAutor(*autores, 13, "Andrew Hunt");
    *autores = addAutor(*autores, 14, "Alfred V. Aho");
    *autores = addAutor(*autores, 15, "Erich Gamma");
}

// Read

void listaAutor(Autor *head)
{
    ordenarAutoresPorId(&head);
    Autor *atual = head;
    while (atual != NULL)
    {
        printf("ID: %d, Nome: %s\n", atual->id, atual->nome);
        atual = atual->prox;
    }
}

void listarLivros(Livro *head)
{
    ordenarLivrosPorId(&head);
    Livro *atual = head;
    while (atual != NULL)
    {
        printf("ID: %d, Título: %s, Autor: %s, Disponível: %s\n", atual->id, atual->titulo, atual->autor->nome, atual->disponivel ? "Sim" : "Não");
        atual = atual->prox;
    }
}

void listarUsuario(Usuario *head)
{
    Usuario *atual = head;
    while (atual != NULL)
    {
        printf("ID: %d, Nome: %s\n", atual->id, atual->nome);
        atual = atual->prox;
    }
}

// Emprestimo

void emprestimoLivro(Livro *livros, int livroId)
{
    Livro *atual = livros;
    while (atual != NULL)
    {
        if (atual->id == livroId && atual->disponivel)
        {
            atual->disponivel = 0;
            printf("Livro emprestado com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }
    printf("Livro não disponível para empréstimo.\n");
}

void emprestimoLivroPorUsuario(Livro *livros, Usuario *usuarios, int livroId, int usuarioId)
{
    Usuario *usuarioAtual = usuarios;
    while (usuarioAtual != NULL)
    {
        if (usuarioAtual->id == usuarioId)
        {
            Livro *livroAtual = livros;
            while (livroAtual != NULL)
            {
                if (livroAtual->id == livroId && livroAtual->disponivel)
                {
                    livroAtual->disponivel = 0;
                    printf("Livro ID %d emprestado ao usuário ID %d com sucesso!\n", livroId, usuarioId);
                    return;
                }
                livroAtual = livroAtual->prox;
            }
            printf("Livro não disponível para empréstimo.\n");
            return;
        }
        usuarioAtual = usuarioAtual->prox;
    }
    printf("Usuário não encontrado.\n");
}

void devolucao(Livro *livros, int livroId)
{
    Livro *atual = livros;
    while (atual != NULL)
    {
        if (atual->id == livroId && !atual->disponivel)
        {
            atual->disponivel = 1;
            printf("Livro devolvido com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }
    printf("Erro ao devolver o livro.\n");
}

// Ordenando
void ordenarAutoresPorId(Autor **head)
{
    if (*head == NULL)
        return;

    Autor *sorted = NULL;
    Autor *atual = *head;
    while (atual != NULL)
    {
        Autor *prox = atual->prox;
        if (sorted == NULL || sorted->id >= atual->id)
        {
            atual->prox = sorted;
            sorted = atual;
        }
        else
        {
            Autor *temp = sorted;
            while (temp->prox != NULL && temp->prox->id < atual->id)
            {
                temp = temp->prox;
            }
            atual->prox = temp->prox;
            temp->prox = atual;
        }
        atual = prox;
    }
    *head = sorted;
}

void ordenarLivrosPorId(Livro **head)
{
    if (*head == NULL)
        return;

    Livro *sorted = NULL;
    Livro *atual = *head;
    while (atual != NULL)
    {
        Livro *prox = atual->prox;
        if (sorted == NULL || sorted->id >= atual->id)
        {
            atual->prox = sorted;
            sorted = atual;
        }
        else
        {
            Livro *temp = sorted;
            while (temp->prox != NULL && temp->prox->id < atual->id)
            {
                temp = temp->prox;
            }
            atual->prox = temp->prox;
            temp->prox = atual;
        }
        atual = prox;
    }
    *head = sorted;
}
