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
  ArrayList * arreglo = (ArrayList *) malloc(sizeof(ArrayList));
  arreglo->data = (void **) malloc(2 * sizeof(void*));
  arreglo->capacity = 2;
  arreglo->size = 5;

  if(arreglo == NULL) exit(1);
  
  return arreglo;
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
