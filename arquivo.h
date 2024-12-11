#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "pizza.h"
#include "ingrediente.h"

void exportarIngredientes(ingredientes*, int*);

void exportarPizzas(pizzas*, int*);

void importarIngredientes(ingredientes*, int*);

void importarPizzas(pizzas*, int*, ingredientes*, int*);

#endif