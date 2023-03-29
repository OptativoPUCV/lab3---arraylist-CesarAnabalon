#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) 
{
    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    assert(list != NULL);
    list->data = (void **) malloc(sizeof(void *) * 10); // Inicialmente se reserva espacio para 10 elementos
    assert(list->data != NULL);
    list->capacity = 10;
    list->size = 0;
    return list;
}

void append(ArrayList *l, void *data)
{
    // Si no hay suficiente espacio en el arreglo, se duplica la capacidad
    if (l->size == l->capacity) {
        l->capacity *= 2;
        l->data = (void **) realloc(l->data, sizeof(void *) * l->capacity);
        assert(l->data != NULL);
    }
    l->data[l->size] = data;
    l->size++;
}

void push(ArrayList *l, void *data, int i)
{
    // Si no hay suficiente espacio en el arreglo, se duplica la capacidad
    if (l->size == l->capacity) {
        l->capacity *= 2;
        l->data = (void **) realloc(l->data, sizeof(void *) * l->capacity);
        assert(l->data != NULL);
    }
    // Se desplazan los elementos a la derecha del índice i para hacer espacio para el nuevo elemento
    for (int j = l->size; j > i; j--) {
        l->data[j] = l->data[j-1];
    }
    l->data[i] = data;
    l->size++;
}

void *pop(ArrayList *l, int i)
{
    void *data = l->data[i];
    // Se desplazan los elementos a la izquierda del índice i para eliminar el elemento
    for (int j = i; j < l->size-1; j++) {
        l->data[j] = l->data[j+1];
    }
    l->size--;
    return data;
}

void *get(ArrayList *l, int i)
{
    assert(i >= 0 && i < l->size);
    return l->data[i];
}

int get_size(ArrayList *l)
{
    return l->size;
}

void clean(ArrayList *l)
{
    free(l->data);
    free(l);
}
