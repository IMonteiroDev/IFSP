#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_NOME 100
#define MAX_TITULO 100

// Estrutura para Autor
typedef struct Autor
{
    int id;
    char nome[MAX_NOME];
    struct Autor *prox;
} Autor;

// Estrutura para Livro
typedef struct Livro
{
    int id;
    char titulo[MAX_TITULO];
    Autor *autor;
    int disponivel;
    struct Livro *prox;
} Livro;

// Estrutura para Usuário
typedef struct Usuario
{
    int id;
    char nome[MAX_NOME];
    struct Usuario *prox;
} Usuario;

// Limpar
void limpar();

// Create

Autor *addAutor(Autor *head, int id, char *nome);
Livro *addLivro(Livro *head, int id, char *titulo, Autor *autor);
Usuario *addUsuario(Usuario *head, int id, const char *nome);

void adicionarLivrosPredefinidos(Livro **livros, Autor *autores);
void adicionarAutoresPredefinidos(Autor **autores);

// Read

void listaAutor(Autor *head);
void listarLivros(Livro *head);
void listarUsuario(Usuario *head);

// Emprestimo
void emprestimoLivro(Livro *livros, int livroId);
void devolucao(Livro *livros, int livroId);
void emprestimoLivroPorUsuario(Livro *livros, Usuario *usuarios, int livroId, int usuarioId);

// Ordenação
void ordenarAutoresPorId(Autor **head);
void ordenarLivrosPorId(Livro **head);

#endif