#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct emprestar_no {
    char nome[50];
    struct emprestar_no *prox;
}emprestar;

typedef struct livro_no {
    char titulo[30];
    char autor[30];
    int paginas;
    char ano_publicacao[5];
    int id;
    int estoque;
    struct emprestar_no *emprestar;
    struct livro_no *prox;
} livro;

typedef struct head {
    livro *head;
} head;

void inserir_livro(head *h) {
    livro *novo = malloc(sizeof(livro));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    printf("Escolha os dados\n");

    printf("Insira o título:\n");
    getchar();
    fgets(novo->titulo, 30, stdin);

    printf("Insira o autor:\n");
    fgets(novo->autor, 30, stdin);

    printf("Insira o número de páginas:\n");
    scanf("%d", &novo->paginas);

    printf("Insira o ano de publicação:\n");
    getchar();
    fgets(novo->ano_publicacao, 5, stdin);

    int estoque;
    printf("Quanto de estoque?\n");
    scanf("%d", &estoque);

    novo->estoque = 1;
    novo->emprestar = NULL;
    novo->prox = NULL;
    novo->id = 0;
    novo->estoque = estoque;
    int cont = 1;

    livro *aux = h->head;
    while (aux != NULL) {
        if (strcmp(aux->titulo, novo->titulo) == 0) {
            aux->estoque += estoque;
            free(novo);
            printf("Livro já existente. Estoque incrementado.\n");
            return;
        }
        if (aux->prox == NULL)
        {
            novo->id = aux->id + cont;
        }
        cont++;
        aux = aux->prox;
    }

    novo->prox = h->head;
    h->head = novo;
}

void empresto(head *h)
{
    livro *aux = h->head;

    int id;
    char nome[50];

    printf("Escolha o ID do livro para emprestar:\n");
    scanf("%d", &id);
    printf("Qual o seu nome?\n");
    getchar();
    fgets(nome, 50, stdin);

    while (aux!=NULL)
    {
        if (aux->id == id)
        {
            break;
        }
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        printf("Livro não encontrado\n");
        return;
    }
    emprestar *e = aux->emprestar;

    while (e != NULL)
    {
        if (strcmp(nome, e->nome) == 0)
        {
            printf("Você ja pegou emprestado esse livro!\n");
            return;
        }
        e = e->prox;
    }
    if (aux->estoque == 0)
    {
        printf("Sem estoque disponível!!\n");
        return;
    }
    emprestar *novo = malloc(sizeof(emprestar));
    strcpy(novo->nome, nome);
    novo->prox = aux->emprestar;
    aux->emprestar = novo;
    aux->estoque -= 1;
}

void devolver(head *h)
{
    int id;
    char nome[50];

    printf("Qual livro quer devolver(ID)\n");
    scanf("%d", &id);
    printf("Qual seu nome?\n");
    getchar();
    fgets(nome, 50, stdin);

    livro *aux = h->head;
    while (aux != NULL)
    {
        if (aux->id == id)
        {
            break;
        }
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        printf("ID não encontrado!\n");
        return;
    }
    emprestar *e = aux->emprestar;
    emprestar *anterior = NULL;

    while (e != NULL)
    {
        if (strcmp(nome, e->nome) == 0)
        {
            if (anterior == NULL)
            {
                aux->emprestar = e->prox;
            } else
            {
                anterior->prox = e->prox;
            }
            printf("Empréstimo foi devolvio", e->nome);
            free(e);
            aux->estoque += 1;
            return;
        }
        anterior = e;
        e = e->prox;
    }

    printf("Pessoa não encontrado\n");
}

void remover_livro(head *h)
{
    printf("Qual livro você deseja remover?");
    int id;
    scanf("%d", &id);

    livro *aux = h->head;
    livro *anterior = NULL;

    while (aux != NULL)
    {
        if (aux->id == id)
        {
            if (aux->emprestar != NULL)
            {
                printf("Não pode remover, pessoas pegaram esse livro emprestado!\n");
                return;
            }
            if (anterior == NULL)
            {
                h->head = aux->prox;
            } else
            {
                anterior->prox = aux->prox;
            }
            printf("Livro excluído!\n");
            free(aux);
            return;

        }
        anterior = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("Não existe!\n");
        return;
    }

}

void imprimir_lista(head *h) {
    livro *aux = h->head;
    if (aux == NULL) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    emprestar *e = NULL;

    while (aux != NULL) {
        e = aux->emprestar;
        printf("\n----------------------------\n");
        printf("ID: %d\n", aux->id);
        printf("Titulo: %s", aux->titulo);
        printf("Autor: %s", aux->autor);
        printf("Paginas: %d\n", aux->paginas);
        printf("Ano de Publicação: %s \n", aux->ano_publicacao);
        printf("Estoque: %d\n", aux->estoque);
        printf("-----Empréstimos------\n");
        if (e == NULL) {
            printf("  Ninguém pegou emprestado ainda.\n");
        } else {
            printf("  Emprestado para:\n");
            while (e != NULL) {
                printf("    - %s\n", e->nome);
                e = e->prox;
            }
        }
        printf("------Empréstimos------\n");
        aux = aux->prox;
    }
    printf("\n");
}

void buscar_por_id(head *h)
{
    livro *aux = h->head;
    if (aux==NULL)
    {
        printf("Lista vazia\n");
        return;
    }

    int escolhido;

    printf("Qual id deseja buscar?");
    scanf("%d", &escolhido);

    emprestar *e = NULL;

    while (aux != NULL)
    {
        if (aux->id == escolhido)
        {
            break;
        }
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("ID não encontrado\n");
        return;
    }
    e = aux->emprestar;
    printf("\n----------------------------\n");
    printf("ID: %d\n", aux->id);
    printf("Titulo: %s", aux->titulo);
    printf("Autor: %s", aux->autor);
    printf("Paginas: %d\n", aux->paginas);
    printf("Ano de Publicação: %s\n", aux->ano_publicacao);
    printf("Estoque: %d\n", aux->estoque);
    printf("-----Empréstimos------\n");
    if (e == NULL) {
        printf("  Ninguém pegou emprestado ainda.\n");
    } else {
        printf("  Emprestado para:\n");
        while (e != NULL) {
            printf("    - %s\n", e->nome);
            e = e->prox;
        }
    }
    printf("------Empréstimos------\n");
    printf("----------------------------\n");
}

void consultar(head *h) {
    system("clear");
    if (h == NULL || h->head == NULL) {
        printf("A lista está vazia\n");
        return;
    }
    printf("ESCOLHA UMA OPÇÃO\n");
    printf("0 - Voltar\n");
    printf("1 - Listar todos os livros\n");
    printf("2 - Buscar por ID\n");
    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
        case 0:
            break;
        case 1:
            imprimir_lista(h);
            break;
        case 2:
            buscar_por_id(h);
            break;
        default:
            printf("Valor incorreto ou opção não implementada.\n");
    }
}

void emprestimo(head *h)
{
    system("clear");
    printf("Escolha uma opção\n");
    printf("0 - Voltar\n");
    printf("1 - Emprestar\n");
    printf("2 - Devolver\n");

    int escolha;
    scanf("%d", &escolha);

    if (h == NULL || h->head == NULL) {
        printf("A lista está vazia\n");
        return;
    }

    switch (escolha) {
    case 0:
        break;
    case 1:
        empresto(h);
        break;
    case 2:
        devolver(h);
        break;
    default:
        printf("Valor incorreto ou opção não implementada.\n");
    }
}

int menu() {
    system("clear");
    printf("ESCOLHA UMA OPÇÃO:\n");
    printf("0 - Sair\n");
    printf("1 - Visualizar livros\n");
    printf("2 - Adicionar Livro\n");
    printf("3 - Empréstimo\n");
    printf("4 - Remover livro\n");
    int opt;
    scanf("%d", &opt);
    return opt;
}

void escolher(head *h, int opt) {
    switch (opt) {
        case 0:
            break;
        case 1:
            consultar(h);
            break;
        case 2:
            inserir_livro(h);
            break;
        case 3:
            emprestimo(h);
            break;
        case 4:
            remover_livro(h);
            break;
        default:
            printf("Opção inválida.\n");
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR");
    int opt;
    head *h = malloc(sizeof(head));
    h->head = NULL;

    do {
        opt = menu();
        escolher(h, opt);
        printf("Pressione Enter para continuar...\n");
        getchar();getchar();
    } while (opt != 0);

    return 0;
}