#include <stdio.h>
#include "contatos.h" 

int main() {
    Contato agenda[MAX_CONTATOS]; 
    int numContatos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Salvar agenda\n");
        printf("5. Carregar agenda\n");
        printf("0. Sair\n");
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
                salvarAgenda(agenda, numContatos);
                break;
            case 5:
                carregarAgenda(agenda, &numContatos);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
