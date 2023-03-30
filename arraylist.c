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

  if(l->size < l->capacity)
  {
    unsigned short j;
    for(j = l->size; j>=i ;j--)
    {
      l->data[j+1] = l->data[j];
      
      if(j==i)
      {
        l->data[j] = data;
      }
    }
  }
  l->size++;
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
