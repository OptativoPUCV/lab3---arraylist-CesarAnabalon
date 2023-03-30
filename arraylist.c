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
  
  if(l->data[l->size] == 0) 
  {
    l->data[l->size] = data;
  }
  if(l->capacity == l->size)
  {
    l->capacity = 2 * l->capacity;
    l->data = (void**) realloc(l->data,sizeof(void)*l->capacity);
    l->data[l->size] = data;
  }
  l->size++;
}

void push(ArrayList * l, void * data, int i)
{
  if(i > l->size) EXIT_FAILURE;
  
  if(l->capacity == l->size)
  {
    l->capacity = 2 * l->capacity;
    l->data = (void**) realloc(l->data,sizeof(void)*l->capacity);
  }
  for(int j = l->size - 1; j >= i; j--) {
    l->data[j+1] = l->data[j];
  }

  l->data[i] = data;

  l->size++;  
}

void* pop(ArrayList * l, int i)
{
  if (index < 0) {
        index = l->size + index;
    }
    
    if (index < 0 || index >= l->size) {
        return NULL;
    }
    
    void *data = l->data[index];
    
    for (int i = index; i < l->size - 1; i++) {
        l->data[i] = l->data[i+1];
    }
    
    l->size--;

    if (l->size <= l->capacity/4) {
        l->capacity /= 2;
        l->data = (void**) realloc(l->data, sizeof(void*) * l->capacity);
    }
    
    return data;

}

void* get(ArrayList * l, int i){
  if (i < 0) {
    i += l->size;
  }
  if (i < 0 || i >= l->size) {
    return NULL;
  }
  return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l)
{
  l->capacity = 2;
  l->size = 0;
  l->data = (void **)realloc(l->data, sizeof(void *) * l->capacity);
}
