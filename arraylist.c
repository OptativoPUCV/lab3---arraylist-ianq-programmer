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

ArrayList *createList(void) {
  ArrayList *listAux = NULL;
  listAux = (ArrayList *)malloc(sizeof(ArrayList));
  listAux->capacity = 2;
  listAux->size = 0;
  listAux->data = malloc(sizeof(void *) * (listAux->capacity));
    return listAux;
}

void append(ArrayList * l, void * data){
  if(l->size < l->capacity)
    l->data[l->size] = data;
  else{
    l->capacity = l->capacity * 2;
    l->data = realloc(l->data, sizeof(void *) * (l->capacity));
    l->data[l->size] = data;
    }
  l->size++;

}

void push(ArrayList * l, void * data, int i){
  if(i > l->size) 
    return;
  
  if(l->size == l->capacity){
    l->capacity = l->capacity * 2;
    l->data = realloc(l->data, sizeof(void *) * (l->capacity));
  }

  if(i < l->size)
  {
    int j;
    for(j = (l->size) ; j > (i) ; j--)
    {
      l->data[j] = l->data[j-1];
    }
  }
  l->data[i] = data;
  l->size++;
}

void* pop(ArrayList * l, int i){
  if(l->data[i] == NULL){
    l->size = 0;
    return NULL;
  }
  if(i < 0)
    i = l->size+i;

  void * aux = l->data[i];
  
  for(int k = i; k < l->size; k++)
  {  
   l->data[k] = l->data[k+1];
   l->size--;
  }
  return aux;
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
