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

}

Heap* createHeap(){
  Heap * h = (Heap*) malloc(sizeof(Heap));
  h->heapArray = (heapElem*) malloc (sizeof(heapElem)*3);
  h->capac = 3;
  h->size = 0;
   return h;
}
