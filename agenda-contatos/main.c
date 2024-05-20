#include <stdio.h>
#include "contatos.h"

int main() {
    int opcao;
    int numContatos = 0;
    Contato agenda[MAX_CONTATOS];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Salvar agenda\n");
        printf("5. Carregar agenda\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(agenda, &numContatos);
                break;
            case 2:
                listarContatos(agenda, numContatos);
                break;
            case 3:
                deletarContato(agenda, &numContatos);
                break;
            case 4:
                salvarAgendaBinario(agenda, numContatos);
                break;
            case 5:
                carregarAgendaBinario(agenda, &numContatos);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 6);

    return 0;
}
