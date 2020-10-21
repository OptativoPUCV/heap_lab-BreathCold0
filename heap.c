#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq->size != 0){
    return pq->heapArray[0].data;
  }
  return NULL;
}



void heap_push(Heap* pq, void* data, int priority){
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  int aux = pq->size;
  int parent = (aux-1)/2;
  pq->size++;
  if (pq->size == pq->capac) {
    pq->capac = (pq->capac)*2+1;
    pq->heapArray = realloc (pq->heapArray,(pq->capac)*sizeof(heapElem));  
  }
  heapElem axu;
  while (pq->heapArray[parent].priority <  pq->heapArray[aux].priority) {
    axu = pq->heapArray[aux];
    pq->heapArray[aux] = pq->heapArray[parent];
    pq->heapArray[parent] = axu;
    aux = parent;
    parent = (aux-1)/2;
  }

}


void heap_pop(Heap* pq){ 
  heapElem aux;
  pq->size--;
  aux = pq->heapArray[0];
  pq->heapArray[0] = pq->heapArray[pq->size];
  pq->heapArray[pq->size] = aux;
  if (pq->size == 0) {
  int son;
  if (pq->heapArray[2].priority < pq->heapArray[1].priority) {
    son = 1;
  }
  else {
    son = 2;
  }
  int axu = 0;
  while (pq->heapArray[axu].priority < pq->heapArray[son].priority) {
    if ((son < pq->size)&&(pq->size > 1)) {
      aux = pq->heapArray[axu];
      pq->heapArray[axu] = pq->heapArray[son];
      pq->heapArray[son] = aux;
      axu = son;
      //son = 2*son+2;
      if (2*son+1 > 2*son+2) {
        son = 2*son+1;
      }
      else {
        son = 2*son+2;
      }
    }
  }
  }
}

Heap* createHeap(){
  Heap * h = (Heap*) malloc(sizeof(Heap));
  h->heapArray = (heapElem*) malloc (sizeof(heapElem)*3);
  h->capac = 3;
  h->size = 0;
   return h;
}
