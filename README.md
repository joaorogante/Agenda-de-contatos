# Gerenciador de Contatos

## Descrição do Projeto

Este projeto é um gerenciador de contatos em C que permite ao usuário adicionar, editar, listar, remover e salvar contatos em duas categorias: pessoais e de trabalho. O programa armazena os contatos em arquivos binários e inclui validação de email e verificação de unicidade de telefone.

## Funcionalidades

- Adicionar contatos (pessoais ou de trabalho)
- Editar contatos existentes
- Listar todos os contatos
- Remover contatos
- Salvar contatos em arquivos binários
- Carregar contatos de arquivos binários

## Estrutura do Projeto

- `main.c` - Contém a função principal e o menu de navegação.
- `contatos.c` - Implementa as funções para gerenciar os contatos.
- `contatos.h` - Define a estrutura do contato e declara as funções.

## Como Compilar

Para compilar o projeto, você precisa de um compilador C (como gcc). Abra o terminal na raiz do projeto e execute o seguinte comando:

gcc main.c contatos.c -o gerenciador_contatos
