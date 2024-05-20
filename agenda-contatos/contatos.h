#ifndef CONTATO_H
#define CONTATO_H

#include <stdbool.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[50];
    char sobrenome[50];
    char email[50];
    char telefone[20];
} Contato;

void adicionarContato(Contato *agenda, int *numContatos);
void listarContatos(Contato *agenda, int numContatos);
void deletarContato(Contato *agenda, int *numContatos);
void salvarAgendaBinario(Contato *agenda, int numContatos);
void carregarAgendaBinario(Contato *agenda, int *numContatos);
bool validarTelefone(const char *telefone);

#endif // CONTATO_H

