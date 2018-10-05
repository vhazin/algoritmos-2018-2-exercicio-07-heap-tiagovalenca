#include <stdio.h>
#include <stdlib.h>

typedef struct element{
  int priority;
  char label;
}element;

void sort(element **heap, int size, element **sorted, int iteration){
  if(size == 0){
    return;
  }
  int i = 0;
  while(heap[i]->priority != size){
    i++;
  }
  sorted[iteration] = heap[i];

  sort(heap, size-1, sorted, iteration + 1);
  return;
}

void outputPrint(int node, element **sorted, int size);

int main(void) {
  int strings;
  scanf("%d", &strings);
  while(strings != 0){
    element **heap;
    heap = malloc(sizeof(element) * strings);
      
    for(int j = 0; j < strings; j++){
      element *el;
      el = malloc(sizeof(element));
      scanf(" %c/%d", &el->label, &el->priority);
      heap[j] = el;
    }
    int i = 0;
    while(i != strings){
      printf("(");
      int j = 0;
      for(int i = j+1; i < strings; i++){
        if(heap[j]->priority < heap[i]->priority){
          printf("(");
        }
        j++;
      }
      printf("%c/%d", heap[0]->label, heap[0]->priority);
      if(heap[0]->priority < heap[1]->priority){
        printf(")");
      }
    }

    printf("\n");
    scanf("%d", &strings);
    free(heap);
  }
  printf("\n");
  return 0;
}

void outputPrint(int node, element **heap, int size) {
	if(node == size)	return;
	printf("(");
  int j = node;
  for(int i = j+1; i < size; i++){
    if(heap[j]->priority < heap[i]->priority){
      printf("(");
    }
    j++;
  }
  printf("%c/%d", heap[node]->label, heap[node]->priority);
	outputPrint(node+1, heap, size);
  if(heap[node]->priority < heap[node+1]->priority){
    printf(")");
  }
  return;
}
