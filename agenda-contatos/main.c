#include <stdio.h>
#include "contatos.h"

#define MAX_CONTATOS 255

Contato contatosPessoais[MAX_CONTATOS];
Contato contatosTrabalho[MAX_CONTATOS];
int totalContatosPessoais = 0;
int totalContatosTrabalho = 0;

void menuContato(Contato *agenda, int *numContatos, const char *tipo) {
    int opcao;
    do {
        printf("\nMenu %s:\n", tipo);
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Alterar contato\n");
        printf("5. Salvar agenda\n");
        printf("6. Carregar agenda\n");
        printf("7. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                adicionarContato(agenda, numContatos);
                break;
            case 2:
                listarContatos(agenda, *numContatos);
                break;
            case 3:
                removerContato(agenda, numContatos);
                break;
            case 4:
                editarContato(agenda, *numContatos);
                break;
            case 5:
                if (strcmp(tipo, "Pessoal") == 0) {
                    salvarAgendaBinaria(agenda, *numContatos, "agenda_pessoal.bin");
                } else {
                    salvarAgendaBinaria(agenda, *numContatos, "agenda_trabalho.bin");
                }
                break;
            case 6:
                if (strcmp(tipo, "Pessoal") == 0) {
                    carregarAgendaBinaria(agenda, numContatos, "agenda_pessoal.bin");
                } else {
                    carregarAgendaBinaria(agenda, numContatos, "agenda_trabalho.bin");
                }
                break;
            case 7:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);
}

int main() {
    int opcao;
    do {
        printf("\nMenu Principal:\n");
        printf("1. Gerenciar contatos pessoais\n");
        printf("2. Gerenciar contatos de trabalho\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                menuContato(contatosPessoais, &totalContatosPessoais, "Pessoal");
                break;
            case 2:
                menuContato(contatosTrabalho, &totalContatosTrabalho, "Trabalho");
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
