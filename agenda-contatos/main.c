#include <stdio.h>
#include "contatos.h"

#define MAX_CONTATOS 100

Contato agenda[MAX_CONTATOS];
int totalContatos = 0;

int main() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Salvar agenda\n");
        printf("5. Carregar agenda\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(agenda, &totalContatos);
                break;
            case 2:
                listarContatos(agenda, totalContatos);
                break;
            case 3:
                deletarContato(agenda, &totalContatos);
                break;
            case 4:
                salvarAgendaBinaria(agenda, totalContatos);
                break;
            case 5:
                carregarAgendaBinaria(agenda, &totalContatos);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
