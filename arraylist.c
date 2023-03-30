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

ArrayList *createList() 
{
  ArrayList * l ;
  l= (ArrayList *) malloc(sizeof(ArrayList));
  l->capacity = 2;
  
  l->data = (void **) malloc(sizeof(void*) * l->capacity);
  l->size = 0;
  
  return l;
}

void append(ArrayList * l, void * data)
{  
  //validar  que tiene espacion 
  if(l->size < l->capacity) 
  {
    l->data[l->size] = data;
  }
  else
    {
      l->capacity = 2 * l->capacity;
      l->data = (void **) realloc(l->data,sizeof(ArrayList) * l->capacity);
    }
  l->size++;
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
