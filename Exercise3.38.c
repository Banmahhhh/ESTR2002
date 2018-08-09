#include <stdio.h>
#include <stdlib.h>
#define min(x, y) (x<y?x:y)
#define max(x, y) (x>y?x:y)

int main(void)
{
  int n, l;
  scanf("%d %d\n", &n, &l);
  int *flag;
  int *cnt;
  int fm=0, bm=0;
  int fmt=0, bmt=0;
  flag = (int*)malloc(n*(sizeof(int)));
  cnt = (int*)malloc(n*(sizeof(int)));
  for(int j = 0; j<n; j++)
    flag[j] = cnt[j] = 0;
  for(int i=0; i<l; i++)
  {
    //printf("i is %d\n", i);
    char operation;
    scanf("%c", &operation);
    //printf("operation is %d\n" ,operation);
    if(operation == 'T')
    {
      int s, e;
      scanf("%d %d", &s, &e);
      i--;
      flag[s-1]++;
      flag[e]--;
    }
    if(operation == 'O')
    {
      i--;
      cnt[0] = flag[0];
      if(cnt[0]%2 == 0)
        bmt++;
      else fmt++;
      for(int j = 1; j<n; j++)
      {
        cnt[j] = cnt[j-1]+flag[j];
        if(cnt[j]%2 == 0)
        {
          fm = max(fm, fmt);
          fmt = 0;
          bmt++;
        }
        else
        {
          bm = max(bm, bmt);
          bmt = 0;
          fmt++;
        }
      }
      fm = max(fm, fmt);
      bm = max(bm, bmt);
      printf("%d %d\n", fm, bm);
      fm = fmt = bm = bmt = 0;
    }
  }
  return 0;
}
