#include "pizza.h"
#include <stdio.h>
#include <string.h>

void visualizarPizzas(pizzas *pizzaVet, int *totalPizzas) {
    if (*totalPizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n\n");
        return;
    }

    printf("Lista de Ingredientes:\n");
    for (int i = 0; i < *totalPizzas; i++) {
        printf("ID: %d | Nome: %s | Preco: (Tam M) R$%.2f\n", pizzaVet[i].id, pizzaVet[i].nome, pizzaVet[i].preco);
    
        printf("Ingredientes:\n");
        for (int j = 0; j < pizzaVet[i].totalIngredientes; j++) {
            printf(" - %s\n", pizzaVet[i].ingred[j].nome);
        }
        printf("\n");
    }
}

void adicionarPizzas(pizzas *pizzaVet, int *totalPizzas, ingredientes *ingredVet, int *totalIngredientes) {
    if (totalIngredientes == 0) {
        printf("Nenhum ingrediente cadastrado. Cadastre ingredientes antes de adicionar pizzas.\n\n");
        return;
    }
    
    pizzas novo;

    printf("Digite o ID da pizza: ");
    scanf("%d", &novo.id);
    getchar();

    printf("Digite o nome da pizza: ");
    fgets(novo.nome, 30, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; 

    printf("Digite o preco da pizza (Tam P): ");
    scanf("%f", &novo.preco);

    printf("Quantos ingredientes a pizza possui? ");
    scanf("%d", &novo.totalIngredientes);
    getchar();

    for (int i = 0; i < novo.totalIngredientes; i++) {
        int ingredienteID;
        int encontrado = 0;

        do {
            printf("Digite o ID do ingrediente: ");
            scanf("%d", &ingredienteID);
            getchar();

            for (int j = 0; j < *totalIngredientes; j++) {
                if (ingredVet[j].id == ingredienteID) {
                    novo.ingred[i] = ingredVet[j];
                    encontrado = 1;
                }
            }

            if (encontrado != 1) {
                printf("Ingrediente com ID %d nao encontrado! Tente novamente.\n", ingredienteID);
            }
        } while (encontrado != 1);
    }

    pizzaVet[*totalPizzas] = novo;
    (*totalPizzas)++;

    printf("Pizza cadastrada!\n\n");
}

void removerPizzas(pizzas *pizzaVet, int *totalPizzas) {
    if (*totalPizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n\n");
        return;
    }

    int removerId;
    printf("Digite o ID da pizza a ser removida: ");
    scanf("%d", &removerId);

    int encontrado = 0;

    for (int i = 0; i < *totalPizzas; i++) {
        if (pizzaVet[i].id == removerId) {
            encontrado = 1;

            for (int j = i; j < *totalPizzas - 1; j++) {
                pizzaVet[j] = pizzaVet[j + 1];
            }

            (*totalPizzas)--;
            printf("Pizza removida!\n\n");
        }
    }

    if (encontrado != 1) {
        printf("Pizza com ID %d não encontrada.\n\n", removerId);
    }
}

void editarPizzas(pizzas *pizzaVet, int *totalPizzas) {
    if (*totalPizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n\n");
        return;
    }

    int editarId;
    printf("Digite o ID da pizza a ser editada: ");
    scanf("%d", &editarId);

    int encontrado = 0;

    for (int i = 0; i < *totalPizzas; i++) {
        if (pizzaVet[i].id == editarId) {
            encontrado = 1;

            float novopreco;
            printf("Digite o novo preco: ");
            scanf("%f", &novopreco);

            pizzaVet[i].preco = novopreco;
            printf("Preco alterado!\n\n");
        }
    }

    if (encontrado != 1) {
        printf("Pizza com ID %d não encontrada.\n\n", editarId);
    }
}

void venderPizza(pizzas *pizzaVet, int *totalPizzas, ingredientes *ingredVet, int *totalIngredientes, float *saldo) {
    if (*totalPizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n\n");
        return;
    }

    int pvendida;
    char addIngrediente[30];
    char SimOuNao, tam;
    float valorFinal;

    printf("------ Vender pizza ------\n");
    printf("Digite o ID da pizza a ser vendida, [0] Cancelar: ");
    scanf("%d", &pvendida);
    printf("\n");

    if(pvendida == 0) {
        printf("Voltando ao menu principal...\n\n");
        return;
    }

    printf("Digite o tamanho da pizza (P / M +R$10 / G +R$20): ");
    scanf(" %c", &tam);
    printf("\n");

    int encontrado;

    for(int i = 0; i < *totalPizzas; i++) {
        if(pvendida == pizzaVet[i].id) {
            encontrado = 1;
            valorFinal = pizzaVet[i].preco;
        }
    }

    if (encontrado != 1) {
        printf("Pizza nao encontrada.\n\n");
        return;
    }

    do{
        printf("Adicionar ingrediente? (S/N): ");
        scanf(" %c", &SimOuNao);
        getchar();
        printf("\n");

        if(SimOuNao == 'S') {
            printf("Digite o ingrediente: ");
            fgets(addIngrediente, 30, stdin);
            addIngrediente[strcspn(addIngrediente, "\n")] = '\0';

            for (int i = 0; i < *totalIngredientes; i++) {
                if(strcmp(addIngrediente, ingredVet[i].nome) == 0) {
                    valorFinal += ingredVet[i].preco;
                }
            }
            printf("\n");
        }
    }while(SimOuNao != 'N');
        
    if(tam == 'M') {
        valorFinal += 10.0;
    }
    if(tam == 'G') {
        valorFinal += 20.0;
    }

    *saldo += valorFinal;

    printf("Venda realizada! Valor final: %.2f\n\n", valorFinal);
    return;
}