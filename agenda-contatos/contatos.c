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
