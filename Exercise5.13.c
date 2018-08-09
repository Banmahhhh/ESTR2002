#include <stdio.h>
#include <stdlib.h>

void insert(int heap[], int pos, int num)
{
  heap[pos] = num;
  for(int i = pos; i>0; i=(i-1)/2)
  {
    if(heap[i] > heap[(i-1)/2])
    {
      heap[i] = heap[(i-1)/2];
      heap[(i-1)/2] = num;
    }
  }
}

void remov(int heap[], int k, int num)
{
  heap[0] = num;
  for(int i = 0; (2*i+1)<k; )
  {
    i = i*2+1;
    if(heap[i] < heap[i+1] && i+1<k)
      i++;
    if(heap[(i-1)/2] > heap[i])
      break;
    heap[(i-1)/2] = heap[i];
    heap[i] = num;
  }
  for(int i = 0; i<k; i++)
    printf("%d ", heap[i]);
  printf("\n");
}

int main(void)
{
  int k;
  scanf("%d\n", &k);
  int *heap;
  heap = (int*)malloc(sizeof(int) * k);
  for(int i = 0; i<k; i++)
  {
    char op[10];
    gets(op);
    heap[i] = atoi(&op[2]);
    insert(heap, i, heap[i]);
  }
  while(1)
  {
    char op[10];
    gets(op);
    if(op[0] == 'S')
      return 0;
    else if(op[0] == 'I')
    {
      int temp = atoi(&op[2]);
      if(temp < heap[0])
        remov(heap, k, temp);
    }
    else if(op[0] == 'O')
      printf("%d\n", heap[0]);
  }
}
