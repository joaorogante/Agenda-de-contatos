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
void salvarAgenda(Contato *agenda, int numContatos) {
    FILE *arquivo = fopen("agenda.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }

    fwrite(&numContatos, sizeof(int), 1, arquivo);

    for (int i = 0; i < numContatos; i++) {
        fwrite(agenda[i].nome, sizeof(char), strlen(agenda[i].nome) + 1, arquivo);
        fputc('|', arquivo); 
        fwrite(agenda[i].sobrenome, sizeof(char), strlen(agenda[i].sobrenome) + 1, arquivo);
        fputc('|', arquivo); 
        fwrite(agenda[i].email, sizeof(char), strlen(agenda[i].email) + 1, arquivo);
        fputc('|', arquivo); 
        fwrite(agenda[i].telefone, sizeof(char), strlen(agenda[i].telefone) + 1, arquivo);
        fputc('\n', arquivo); 
    }

    fclose(arquivo);
    printf("Agenda salva com sucesso!\n");
}
void carregarAgenda(Contato *agenda, int *numContatos) {
    FILE *arquivo = fopen("agenda.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de agenda não encontrado.\n");
        return;
    }

    fread(numContatos, sizeof(int), 1, arquivo);
    for (int i = 0; i < *numContatos; i++) {
        fscanf(arquivo, "%[^|]|", agenda[i].nome);
        fscanf(arquivo, "%[^|]|", agenda[i].sobrenome);
        fscanf(arquivo, "%[^|]|", agenda[i].email);
        fscanf(arquivo, "%[^\n]\n", agenda[i].telefone);
    }

    fclose(arquivo);
    printf("Agenda carregada com sucesso!\n");
    printf("A agenda foi carregada com %d contatos.\n", *numContatos);
}
