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
