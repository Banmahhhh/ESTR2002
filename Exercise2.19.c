#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s
{
  int data;
  struct node_s *next;
}node;

node *create_stack()
{
  node* stack;
  stack = (node*)malloc(sizeof(node));
  stack->next = NULL;
  return stack;
}

void Push(int in, node *stack)
{
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = in;
  newnode->next = stack->next;
  stack->next = newnode;
}

int Pop(node* stack)
{
  int temp;
  node* popped;
  if(stack->next != NULL)
  {
    temp = stack->next->data;
    popped = stack->next;
    stack->next = stack->next->next;
    free(popped);
    return temp;
  }
  else return 0;
}

int top(node* stack)
{
  if(stack->next != NULL)
    return stack->next->data;
  else return 0;
}

int main(void)
{
  int m;
  scanf("%d\n", &m);
  int check = 0;
  for(int i = 0; i<m; i++)
  {
    int n;
    scanf("%d\n", &n);
    int banma[1100];
    banma[0] = n+3;
    int order[1100];
    order[n] = n+1;
    for(int j = 0; j<n; j++)
    {
      //printf("j is %d\n", j);
      int temp;
      scanf("%d", &temp);
      banma[temp] = j+1;
      order[j] = temp;
    }
    node *s1 = create_stack();
    node *s2 = create_stack();
    int pos = 0;
    for(int j = 1; j<n+1; j++)
    {
      if(order[pos] == top(s1))
      {
        Pop(s1);
        pos++;
        j--;
      }
      else if(order[pos] == top(s2))
      {
        Pop(s2);
        pos++;
        j--;
      }
      else if(order[pos] == j)
        pos++;
      else if(banma[j] < banma[top(s1)])
        Push(j, s1);
      else if(banma[j] > banma[top(s1)] && banma[j] < banma[top(s2)])
        Push(j, s2);
      else if(banma[j] > banma[top(s2)])
      {
        printf("No\n");
        check = 1;
        break;
      }
    }
    if(check == 0)
      printf("Yes\n");
    check = 0;
  }
  return 0;
}
