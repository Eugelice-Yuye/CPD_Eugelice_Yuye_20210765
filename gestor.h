#include <stdlib.h>
#include <stdio.h>

#define MAX_TAREFAS 100

// Estrutura para representar uma tarefa
typedef struct {
    char id[50];
    int prioridade;
    time_t criacao;
} Tarefa;

// Estrutura para representar o gerenciador de tarefas
typedef struct {
    Tarefa tarefas[MAX_TAREFAS];
    int contador;
} Gerenciador;

//gerenciador de tarefas

Gerenciador *criarTarefa();

//adicionar uma nova tarefa

void novaTarefa(Gerenciador *gerenciador, int prioridade, char *id);

//listar as tarefas com prioridade

void listar(Gerenciador *gerenciador, int min_prioridade);

//completar tarefa

void completar(Gerenciador *gerenciador, char *id);
