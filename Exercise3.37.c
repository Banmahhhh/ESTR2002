#include <stdio.h>
#include <stdlib.h>

int s = 0;

int sum(int tree[11000], int i, int t, int length)
{
  if(tree[i] != 10001 )
    t += tree[i];
  if(2*i+1 < length && tree[2*i+1] != 10001)
    sum(tree, 2*i+1, t, length);
  if(2*i+2 < length && tree[2*i+2] != 10001)
    sum(tree, 2*i+2, t, length);
  else if(2*i+1>length || tree[2*i+1] == 10001)
  {
    if(t > s) s = t;
    return s;
  }
}

int main(void)
{
  int n;
  scanf("%d\n", &n);
  int num[11000];
  for(int i = 0; i<n; i++)
  {
    char temp[11000];
    int j = 0, k = 0;
    char t;
    int length=0;
    while(1)
    {
      scanf("%c", &t);
      if(t == ' ')
      {
        temp[j] = '\0';
        if(temp[0] != '#')  num[k] = atoi(temp);
        else num[k] = 10001;
        k++;
        j = 0;
        length++;
      }
      else if(t == 10)
      {
        temp[j] = '\0';
        length++;
        if(temp[0] != '#')  num[k] = atoi(temp);
        else num[k] = 10001;
        break;
      }
      else
      {
        temp[j] = t;
        j++;
      }
    }
    for(int k = 0; num[k] != 10001 && k<length; k = 2*k+1){
      s += num[k];
    }
    sum(num, 0, 0, length);
    printf("%d\n", s);
    s = 0;
  }
  return 0;
}
