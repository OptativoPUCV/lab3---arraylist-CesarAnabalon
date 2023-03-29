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
    list->data = (void **) malloc(sizeof(void *) * 10); 
  // Inicialmente se reserva espacio para 10 elementos
    assert(list->data != NULL);
    list->capacity = 10;
    list->size = 0;
    return list;
  return
}

void append(ArrayList * l, void * data)
{
  
}

void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
