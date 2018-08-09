#include <stdio.h>

int main()
{
  int n;
  scanf("%d\n" ,&n);
  for(int i=0; i<n; i++)
  {
    int count = 0;
    int m;
    scanf("%d\n", &m);
    int num[100];
    for(int j=0; j<m; j++)
      scanf("%d", &num[j]);
    for(int j=0; j<m; j++)
      for(int k=j+1; k<m; k++)
      {
        if(num[j] > num[k])
          count++;
      }
    printf("%d\n", count);
  }
  return 0;
}
