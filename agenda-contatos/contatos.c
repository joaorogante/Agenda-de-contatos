#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "contatos.h"

int validarEmail(const char *email) {
    // Simplificando a expressão regular para validação de email
    regex_t regex;
    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        return 0;
    }
    int result = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    return result == 0;
}
int telefoneUnico(const char *telefone, Contato contatos[], int totalContatos) {
    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(contatos[i].telefone, telefone) == 0) {
            return 0;
        }
    }
    return 1;
}
int adicionarContato(Contato contatos[], int *totalContatos) {
    char nome[50], sobrenome[50], email[50], telefone[15];
    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';  // Remove the newline character

    printf("Sobrenome: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';  // Remove the newline character

    printf("Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Telefone: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    if (!validarEmail(email)) {
        printf("Formato de email inválido.\n");
        return 0;
    }
    if (!telefoneUnico(telefone, contatos, *totalContatos)) {
        printf("Telefone já existe.\n");
        return 0;
    }
    if (*totalContatos >= MAX_CONTATOS) {
        printf("Lista de contatos cheia.\n");
        return 0;
    }
    snprintf(contatos[*totalContatos].nome, sizeof(contatos[*totalContatos].nome), "%s %s", nome, sobrenome);
    strcpy(contatos[*totalContatos].email, email);
    strcpy(contatos[*totalContatos].telefone, telefone);
    (*totalContatos)++;
    printf("Contato adicionado com sucesso!\n");
    return 1;
}
int editarContato(Contato contatos[], int totalContatos) {
    char telefone[15];
    printf("Telefone do contato a ser editado: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(contatos[i].telefone, telefone) == 0) {
            char novoNome[50], novoEmail[50], novoTelefone[15];
            printf("Novo nome (deixe em branco para não alterar): ");
            fgets(novoNome, sizeof(novoNome), stdin);
            novoNome[strcspn(novoNome, "\n")] = '\0';

            printf("Novo email (deixe em branco para não alterar): ");
            fgets(novoEmail, sizeof(novoEmail), stdin);
            novoEmail[strcspn(novoEmail, "\n")] = '\0';

            printf("Novo telefone (deixe em branco para não alterar): ");
            fgets(novoTelefone, sizeof(novoTelefone), stdin);
            novoTelefone[strcspn(novoTelefone, "\n")] = '\0';

            if (novoNome[0]) strcpy(contatos[i].nome, novoNome);
            if (novoEmail[0]) {
                if (!validarEmail(novoEmail)) {
                    printf("Formato de email inválido.\n");
                    return 0;
                }
                strcpy(contatos[i].email, novoEmail);
            }
            if (novoTelefone[0]) {
                if (!telefoneUnico(novoTelefone, contatos, totalContatos)) {
                    printf("Telefone já existe.\n");
                    return 0;
                }
                strcpy(contatos[i].telefone, novoTelefone);
            }
            printf("Contato editado com sucesso!\n");
            return 1;
        }
    }
    printf("Contato não encontrado.\n");
    return 0;
}
void listarContatos(Contato contatos[], int totalContatos) {
    printf("\nLista de Contatos:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < totalContatos; i++) {
        printf("Nome: %s\nEmail: %s\nTelefone: %s\n", contatos[i].nome, contatos[i].email, contatos[i].telefone);
        printf("-------------------------------------------------\n");
    }
}
int removerContato(Contato contatos[], int *totalContatos) {
    char telefone[15];
    printf("Telefone do contato a ser removido: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    for (int i = 0; i < *totalContatos; i++) {
        if (strcmp(contatos[i].telefone, telefone) == 0) {
            for (int j = i; j < *totalContatos - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            (*totalContatos)--;
            printf("Contato removido com sucesso!\n");
            return 1;
        }
    }
    printf("Contato não encontrado.\n");
    return 0;
}
int salvarAgendaBinaria(Contato contatos[], int totalContatos, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erro ao abrir o arquivo para escrita");
        return 0;
    }
    fwrite(&totalContatos, sizeof(int), 1, file);
    fwrite(contatos, sizeof(Contato), totalContatos, file);
    fclose(file);
    printf("Agenda salva com sucesso!\n");
    return 1;
}
int carregarAgendaBinaria(Contato contatos[], int *totalContatos, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    fread(totalContatos, sizeof(int), 1, file);
    fread(contatos, sizeof(Contato), *totalContatos, file);
    fclose(file);
    printf("Agenda carregada com sucesso!\n");
    return 1;
}
void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
