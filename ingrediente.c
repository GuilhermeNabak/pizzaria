#include "ingrediente.h"
#include <stdio.h>
#include <string.h>

void visualizarIngredientes(ingredientes *ingredVet, int *totalIngredientes) {
    if (*totalIngredientes == 0) {
        printf("Nenhum ingrediente cadastrado.\n\n");
        return;
    }

    printf("Lista de Ingredientes:\n");
    for (int i = 0; i < *totalIngredientes; i++) {
        printf("ID: %d | Nome: %s | Preco: R$%.2f\n", ingredVet[i].id, ingredVet[i].nome, ingredVet[i].preco);
    }
    printf("\n");
}

void adicionarIngredientes(ingredientes *ingredVet, int *totalIngredientes) {
    ingredientes novo;

    printf("Digite o ID do ingrediente: ");
    scanf("%d", &novo.id);
    getchar();

    printf("Digite o nome do ingrediente: ");
    fgets(novo.nome, 30, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; 

    printf("Digite o preco do ingrediente: ");
    scanf("%f", &novo.preco);

    ingredVet[*totalIngredientes] = novo;
    (*totalIngredientes)++;

    printf("Ingrediente cadastrado!\n\n");
}

void removerIngredientes(ingredientes *ingredVet, int *totalIngredientes) {
    if (*totalIngredientes == 0) {
        printf("Nenhum ingrediente cadastrado.\n\n");
        return;
    }

    int removerId;
    printf("Digite o ID do ingrediente a ser removido: ");
    scanf("%d", &removerId);

    int encontrado = 0;

    for (int i = 0; i < *totalIngredientes; i++) {
        if (ingredVet[i].id == removerId) {
            encontrado = 1;

            for (int j = i; j < *totalIngredientes - 1; j++) {
                ingredVet[j] = ingredVet[j + 1];
            }

            (*totalIngredientes)--;
            printf("Ingrediente removido!\n\n");
        }
    }

    if (encontrado != 1) {
        printf("Ingrediente com ID %d não encontrado.\n\n", removerId);
    }
}

void editarIngredientes(ingredientes *ingredVet, int *totalIngredientes) {
    if (*totalIngredientes == 0) {
        printf("Nenhum ingrediente cadastrado.\n\n");
        return;
    }

    int editarId;
    printf("Digite o ID do ingrediente a ser editado: ");
    scanf("%d", &editarId);

    int encontrado = 0;

    for (int i = 0; i < *totalIngredientes; i++) {
        if (ingredVet[i].id == editarId) {
            encontrado = 1;

            float novopreco;
            printf("Digite o novo preco: ");
            scanf("%f", &novopreco);

            ingredVet[i].preco = novopreco;
            printf("Preco alterado!\n\n");
        }
    }

    if (encontrado != 1) {
        printf("Ingrediente com ID %d não encontrado.\n\n", editarId);
    }
}