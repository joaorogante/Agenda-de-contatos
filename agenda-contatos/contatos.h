#ifndef CONTATOS_H
#define CONTATOS_H

#define MAX_CONTATOS 255

typedef struct {
    char nome[50];
    char email[50];
    char telefone[15];
} Contato;

int validarEmail(const char *email);
int telefoneUnico(const char *telefone, Contato contatos[], int totalContatos);
int adicionarContato(Contato contatos[], int *totalContatos);
int editarContato(Contato contatos[], int totalContatos);
void listarContatos(Contato contatos[], int totalContatos);
int removerContato(Contato contatos[], int *totalContatos);
int salvarAgendaBinaria(Contato contatos[], int totalContatos, const char *filename);
int carregarAgendaBinaria(Contato contatos[], int *totalContatos, const char *filename);
void limparBufferEntrada(void);

#endif

