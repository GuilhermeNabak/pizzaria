#ifndef PIZZA_H
#define PIZZA_H
#include "ingrediente.h"

typedef struct pizzas{
    int id;
    char nome[30];
    float preco;
    int totalIngredientes;
    ingredientes ingred[10];
}pizzas;

void visualizarPizzas(pizzas*, int*);

void adicionarPizzas(pizzas*, int*, ingredientes*, int*);

void removerPizzas(pizzas*, int*);

void editarPizzas(pizzas*, int*);

void venderPizza(pizzas*, int*, ingredientes*, int*, float*);

#endif