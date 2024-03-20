#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gestor.h"


// Função para criar um novo gerenciador de tarefas
Gerenciador *criarTarefa() {
    Gerenciador *gerenciador = (Gerenciador *)malloc(sizeof(Gerenciador));
    if (gerenciador == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o gerenciador de tarefas\n");
        exit(EXIT_FAILURE);
    }
    gerenciador->contador = 0;
    return gerenciador;
}

// Função para adicionar uma nova tarefa ao gerenciador
void novaTarefa(Gerenciador *gerenciador, int prioridade, char *id) {
    if (gerenciador->contador >= MAX_TAREFAS) {
        fprintf(stderr, "Limite máximo de tarefas\n");
        return;
    }
    Tarefa tarefa;
    strcpy(tarefa.id, id);
    tarefa.prioridade = prioridade;
    tarefa.criacao = time(NULL);
    gerenciador->tarefas[gerenciador->contador++] = tarefa;
}

// Função para listar as tarefas com prioridade igual ou superior
void listar(Gerenciador *gerenciador, int min_prioridade) {
    printf("Tarefas:\n");
    int i;
    for (i = 0; i < gerenciador->contador; i++) {
        Tarefa tarefa = gerenciador->tarefas[i];
        if (tarefa.prioridade >= min_prioridade) {
            printf("ID: %s, Prioridade: %d, Criada em: %s", tarefa.id, tarefa.prioridade, ctime(&tarefa.criacao));
        }
    }
}

// Função para completar uma tarefa
void completar(Gerenciador *gerenciador, char *id) {
    int encontrado = 0;
    int i;
    for (i = 0; i < gerenciador->contador; i++) {
        if (strcmp(gerenciador->tarefas[i].id, id) == 0) {
            encontrado = 1;
            int j;
            for (j = i; j < gerenciador->contador - 1; j++) {
                gerenciador->tarefas[j] = gerenciador->tarefas[j + 1];
            }
            gerenciador->contador--;
            printf("Tarefa '%s' concluída com sucesso\n", id);
            break;
        }
    }
    if (!encontrado) {
        printf("TAREFA INEXISTENTE\n");
    }
}


