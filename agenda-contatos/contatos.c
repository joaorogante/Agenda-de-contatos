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
   for (int i = 0; i < totalContatos; i++) {
        printf("Contato %d:\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Sobrenome: %s\n", contatos[i].sobrenome);
        printf("Email: %s\n", contatos[i].email);
        printf("Telefone: %s\n", contatos[i].telefone);
    }
}

void deletarContato(Contato *agenda, int *numContatos) {
    if (*numContatos == 0) {
        printf("A agenda está vazia.\n");
        return;
    }

    char telefone[20];
    printf("Digite o número de telefone do contato a ser deletado: ");
    scanf("%s", telefone);

    int indiceContato = -1;
    for (int i = 0; i < *numContatos; i++) {
        if (strcmp(agenda[i].telefone, telefone) == 0) {
            indiceContato = i;
            break;
        }
    }

    if (indiceContato == -1) {
        printf("Contato não encontrado.\n");
        return;
    }

    for (int i = indiceContato; i < *numContatos - 1; i++) {
        agenda[i] = agenda[i + 1];
    }

    (*numContatos)--;
    printf("Contato deletado com sucesso!\n");
}
void salvarAgendaBinario() {
    FILE *file = fopen("agenda.bin", "wb");
    if (file != NULL) {
        fwrite(contatos, sizeof(Contato), totalContatos, file);
        fclose(file);
        printf("Agenda salva com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

void carregarAgendaBinario() {
    FILE *file = fopen("agenda.bin", "rb");
    if (file != NULL) {
        totalContatos = fread(contatos, sizeof(Contato), MAX_CONTATOS, file);
        fclose(file);
        printf("Agenda carregada com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}

bool validarTelefone(const char *telefone) {
    for (int i = 0; telefone[i] != '\0'; i++) {
        if (!isdigit(telefone[i])) {
            return false;
        }
    }
    return true;
}
