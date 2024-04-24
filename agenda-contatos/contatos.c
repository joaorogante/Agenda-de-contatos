#include <stdio.h>
#include <string.h>
#include "contatos.h"

void adicionarContato(Contato *agenda, int *numContatos) {
    if (*numContatos >= MAX_CONTATOS) {
        printf("A agenda está cheia. Não é possível adicionar mais contatos.\n");
        return;
    }

    Contato novoContato;
    printf("Digite o nome: ");
    scanf("%s", novoContato.nome);
    printf("Digite o sobrenome: ");
    scanf("%s", novoContato.sobrenome);
    printf("Digite o email: ");
    scanf("%s", novoContato.email);
    printf("Digite o telefone: ");
    scanf("%s", novoContato.telefone);

    agenda[*numContatos] = novoContato;
    (*numContatos)++;
    printf("Contato adicionado com sucesso!\n");
}
void listarContatos(Contato *agenda, int numContatos) {
    if (numContatos == 0) {
        printf("A agenda está vazia.\n");
        return;
    }

    printf("Lista de contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("%d. %s %s, %s, %s\n", i + 1, agenda[i].nome, agenda[i].sobrenome, agenda[i].email, agenda[i].telefone);
    }
}
