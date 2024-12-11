#include "arquivo.h"
#include "pizza.h"
#include "ingrediente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exportarIngredientes(ingredientes *ingredVet, int *totalIngredientes) {
    FILE *file = fopen("dados_ingredientes.txt", "w");

    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n\n");
        return;
    }

    for (int i = 0; i < *totalIngredientes; i++) {
        fprintf(file, "%d,%s,%.2f\n", ingredVet[i].id, ingredVet[i].nome, ingredVet[i].preco);
    }

    fclose(file);
}

void exportarPizzas(pizzas *pizzaVet, int *totalPizzas) {
    FILE *file = fopen("dados_pizzas.txt", "w");

    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n\n");
        return;
    }

    for (int i = 0; i < *totalPizzas; i++) {
        fprintf(file, "%d,%s,%.2f", pizzaVet[i].id, pizzaVet[i].nome, pizzaVet[i].preco);

        for (int j = 0; j < pizzaVet[i].totalIngredientes; j++) {
            fprintf(file, ",%d", pizzaVet[i].ingred[j].id);
        }

        fprintf(file, "\n");
    }

    fclose(file);
    printf("Dados exportados!\n\n");
}

void importarIngredientes(ingredientes *ingredVet, int *totalIngredientes) {
    FILE *file = fopen("dados_ingredientes.txt", "r");

    while (fscanf(file, "%d,%29[^,],%f\n", &ingredVet[*totalIngredientes].id, ingredVet[*totalIngredientes].nome, &ingredVet[*totalIngredientes].preco) == 3) {
        (*totalIngredientes)++;
    }

    fclose(file);
}

void importarPizzas(pizzas *pizzaVet, int *totalPizzas, ingredientes *ingredVet, int *totalIngredientes) {
    FILE *file = fopen("dados_pizzas.txt", "r");

    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        pizzas novaPizza;
        novaPizza.totalIngredientes = 0;

        char ingredientesStr[200];
        int lidos = sscanf(linha, "%d,%29[^,],%f,%199[^\n]", &novaPizza.id, novaPizza.nome, &novaPizza.preco, ingredientesStr);

        char *token = strtok(ingredientesStr, ",");
        while (token != NULL && novaPizza.totalIngredientes < 10) {
            int idIngrediente = atoi(token);

            for (int i = 0; i < *totalIngredientes; i++) {
                if (ingredVet[i].id == idIngrediente) {
                    novaPizza.ingred[novaPizza.totalIngredientes] = ingredVet[i];
                    novaPizza.totalIngredientes++;
                }
            }
            token = strtok(NULL, ",");
        }

        pizzaVet[*totalPizzas] = novaPizza;
        (*totalPizzas)++;
    }

    fclose(file);
    printf("Dados importados!\n\n");
}