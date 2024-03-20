#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "gestor.c"

// Função principal
main() {
    Gerenciador *gerenciador = criarTarefa();
    char comando[20];
    int prioridade;
    char id[50];

    while (1) {
        printf("\nDigite um comando (new, list, complete) ou 'quit' para sair: ");
        scanf("%s", comando);
        if (strcmp(comando, "quit") == 0) {
            break;
        } else if (strcmp(comando, "new") == 0) {
            scanf("%d %s", &prioridade, id);
            novaTarefa(gerenciador, prioridade, id);
        } else if (strcmp(comando, "list") == 0) {
            scanf("%d", &prioridade);
            listar(gerenciador, prioridade);
        } else if (strcmp(comando, "complete") == 0) {
            scanf("%s", id);
            completar(gerenciador, id);
        } else {
            printf("Comando inválido\n");
        }
    }

    free(gerenciador);
    
}





