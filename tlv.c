#include <stdio.h>
#include <stdlib.h>

typedef struct element{
  int priority;
  char label;
}element;

void printPriority(element **heap, int size){
  if(size == 0){
    printf("\n");
    return;
  }
  int i = 0;
  while(heap[i]->priority != size){
    i++;
  }
  printf("%c/%d ", heap[i]->label, heap[i]->priority);
  printPriority(heap, size-1);
  return;
}


int main(void) {
  int strings;
  scanf("%d", &strings);
  while(strings != 0){
    element **heap;
    heap = malloc(sizeof(element) * strings + 1);
      
    for(int j = 0; j < strings; j++){
      element *el;
      el = malloc(sizeof(element));
      if(j!= strings -1){
        scanf(" %c/%d", &el->label, &el->priority);
      }else{
        scanf(" %c/%d", &el->label, &el->priority);
      }
      heap[j] = el;
    }
    printPriority(heap, strings);
    scanf("%d", &strings);
  }
  printf("\n");
  return 0;
}
