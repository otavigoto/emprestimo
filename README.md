📚 Sistema de Gerenciamento de Biblioteca em C
Este projeto é um sistema de gerenciamento de biblioteca desenvolvido em linguagem C, com o objetivo de cadastrar, emprestar, devolver, consultar e remover livros através de um menu interativo no terminal.

✨ Funcionalidades
O sistema oferece as seguintes funcionalidades:

✅ Cadastro de Livros
Permite cadastrar novos livros com as seguintes informações:

Título

Autor

Número de páginas

Ano de publicação

Código único (ID)

Estoque disponível

Lista com os nomes das pessoas que pegaram o livro emprestado

Caso o título do livro já exista no sistema, o estoque é incrementado automaticamente sem duplicar o cadastro.

🔎 Consulta de Livros
Possibilita consultar todos os livros cadastrados.

Permite buscar um livro específico pelo seu ID.

Exibe informações completas do livro, incluindo:

Detalhes técnicos

Estoque atual

Lista de pessoas que emprestaram o livro

Emite aviso se o livro não for encontrado.

📤 Empréstimo de Livros
Permite que um usuário empreste um livro pelo seu ID.

Verifica se o usuário já pegou o livro emprestado antes.

Reduz a quantidade disponível no estoque.

Caso o estoque esteja zerado, um aviso é emitido e o empréstimo é bloqueado.

📥 Devolução de Livros
Permite que um usuário devolva um livro pelo seu ID.

Remove o nome do usuário da lista de empréstimo.

Aumenta a quantidade disponível no estoque.

Emite aviso caso o nome informado não esteja na lista de empréstimo.

❌ Remoção de Livros
Permite a exclusão de um livro pelo seu ID.

A remoção só será permitida se não houver nenhum exemplar emprestado.

🧭 Menu Interativo
Sistema de navegação no terminal:

Listar livros

Buscar livro por ID

Adicionar livro

Realizar empréstimo ou devolução

Remover livro

Sair do sistema

🛠️ Como Executar
Compile o código com um compilador C (como gcc):

bash
Copiar
Editar
gcc -o biblioteca main.c
Execute o programa:

bash
Copiar
Editar
./biblioteca
⚠️ Este código foi desenvolvido para ser executado em sistemas Linux. A função system("clear") pode não funcionar corretamente em outros sistemas operacionais. Para Windows, substitua por system("cls").

🗃️ Estrutura de Dados
struct livro: Representa o livro com todas suas propriedades, incluindo a lista de pessoas que o pegaram emprestado.

struct emprestar: Lista encadeada com os nomes dos usuários que realizaram empréstimos.

struct head: Representa o início da lista encadeada de livros.

📌 Pontos de Atenção
O ID do livro é atribuído de forma incremental com base no último livro da lista.

As strings são lidas com fgets, que inclui o \n no final. Cuidado ao comparar strings.

O sistema ainda pode ser melhorado com persistência em arquivo e melhorias de validação de entrada.

📄 Licença
Este projeto é de livre uso para fins educacionais e de aprendizado.
