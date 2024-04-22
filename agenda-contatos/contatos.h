#ifndef CONTATOS_H
#define CONTATOS_H

#define MAX_CONTATOS 255

typedef struct {
    char nome[50];
    char sobrenome[50];
    char email[100];
    char telefone[20];
} Contato;

void adicionarContato(Contato *agenda, int *numContatos);
void listarContatos(Contato *agenda, int numContatos);
void deletarContato(Contato *agenda, int *numContatos);
void salvarAgenda(Contato *agenda, int numContatos);
void carregarAgenda(Contato *agenda, int *numContatos);

#endif
