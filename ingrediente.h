#ifndef INGREDIENTE_H
#define INGREDIENTE_H

typedef struct ingredientes{
    int id;
    char nome[30];
    float preco;
}ingredientes;

void visualizarIngredientes(ingredientes*, int*);

void adicionarIngredientes(ingredientes*, int*);

void removerIngredientes(ingredientes*, int*);

void editarIngredientes(ingredientes*, int*);

#endif