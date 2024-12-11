#include "pizza.h"
#include "ingrediente.h"
#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int op = 0;
    float saldo = 0.0;

    ingredientes ingredVet[50];
    int totalIngredientes = 0;

    pizzas pizzaVet[20];
    int  totalPizzas = 0;

    do {
        // -----------------------Menu Principal-----------------------

        printf("------- Pizzaria -------\n");
        printf("Opcoes do sistema:\n\n");
        printf("[1] Configurar pizzas\n");
        printf("[2] Configurar ingredientes\n");
        printf("[3] Vender pizza\n");
        printf("[4] Exportar dados\n");
        printf("[5] Importar dados\n");
        printf("[6] Acessar saldo\n");
        printf("[7] Sair do sistema\n");
        printf("------------------------\n\n");

        printf("Digite a opcao: ");
        scanf("%d", &op);
        getchar();
        printf("\n");

        // ---------------------Menus Especificos----------------------

        switch (op) {
            case 1: { 
                int op1 = 0; 

                do {
                    printf("---- Configurar Pizzas ----\n");
                    printf("[1] Visualizar pizzas\n");
                    printf("[2] Adicionar pizza\n");
                    printf("[3] Remover pizza\n");
                    printf("[4] Editar pizza (preco)\n");
                    printf("[5] Voltar\n");
                    printf("-------------------------\n\n");

                    printf("Digite a opcao: ");
                    scanf("%d", &op1);
                    printf("\n");

                    switch (op1) {
                        case 1: {
                            visualizarPizzas(pizzaVet, &totalPizzas);
                            break;
                        }
                        case 2: {
                            adicionarPizzas(pizzaVet, &totalPizzas, ingredVet, &totalIngredientes);
                            break;
                        }
                        case 3: {
                            removerPizzas(pizzaVet, &totalPizzas);
                            break;
                        }
                        case 4: {
                            editarPizzas(pizzaVet, &totalPizzas);
                            break;
                        }
                        case 5: {
                            printf("Voltando ao menu principal...\n\n");
                            break;
                        }
                        default: {
                            printf("Opcao invalida!\n\n");
                            break;
                        }
                    }
                } while (op1 != 5);

                break;
            }
            
            // -------------------------------------------------------------

            case 2: {
                int op2 = 0; 

                do {
                    printf("--- Configurar Ingredientes ---\n");
                    printf("[1] Visualizar ingredientes\n");
                    printf("[2] Adicionar ingredientes\n");
                    printf("[3] Remover ingrediente\n");
                    printf("[4] Editar ingrediente (preco)\n");
                    printf("[5] Voltar\n");
                    printf("-------------------------\n\n");

                    printf("Digite a opcao: ");
                    scanf("%d", &op2);
                    printf("\n");

                    switch (op2) {
                        case 1: {
                            visualizarIngredientes(ingredVet, &totalIngredientes);
                            break;
                        }
                        case 2: {
                            adicionarIngredientes(ingredVet, &totalIngredientes);
                            break;
                        }
                        case 3: {
                            removerIngredientes(ingredVet, &totalIngredientes);
                            break;
                        }
                        case 4: {
                            editarIngredientes(ingredVet, &totalIngredientes);
                            break;
                        }
                        case 5: {
                            printf("Voltando ao menu principal...\n\n");
                            break;
                        }
                        default: {
                            printf("Opcao invalida!\n\n");
                            break;
                        }
                    }
                } while (op2 != 5);

                break;
            }

            // --------------------------------------------------------------

            case 3: {
                venderPizza(pizzaVet, &totalPizzas, ingredVet, &totalIngredientes, &saldo);
                break;
            }

            // --------------------------------------------------------------

            case 4: {
                exportarIngredientes(ingredVet, &totalIngredientes);

                exportarPizzas(pizzaVet, &totalPizzas);
                break;
            }

            // --------------------------------------------------------------

            case 5: {
                importarIngredientes(ingredVet, &totalIngredientes);

                importarPizzas(pizzaVet, &totalPizzas, ingredVet, &totalIngredientes);
                break;
            }

            // --------------------------------------------------------------

            case 6: {
                printf("Saldo Atual: %.2f\n\n", saldo);
                break;
            }

            // --------------------------------------------------------------

            case 7: {
                printf("Saindo do sistema...\n");
                break;
            }

            // --------------------------------------------------------------

            default: {
                printf("Opção inválida!\n");
                break;
            }
        }
    } while (op != 7);

    return 0;
}


// gcc main.c pizza.c ingrediente.c arquivo.c -o pizzaria

// ./pizzaria.exe