#include <stdio.h>

int main(void)
{
  int t;
  scanf("%d", &t);
  for(int i = 0; i<t; i++)
  {
    int n;
    scanf("%d", &n);
    int pre[1100];
    int in[1100][2];
    int str[11000][3];
    str[10001][0] = str[10001][1] = 0;
    for(int j = 0; j<n; j++){
      scanf("%d", &pre[j]);
      str[pre[j]][0] = str[pre[j]][1] = -1;
    }
    for(int j = 0; j<n; j++){
      scanf("%d", &in[j][0]);
      in[j][1] = 0;
    }
    int l = 10001, r = 10001;
    int num;
    for(int j = 0; j<n; j++)//find the parent
    {
      num = pre[j];//parent
      int k;
      for(k = 0; k<n; k++)
      {
        if(in[k][0] == num)
          break;//no left child
        else if(in[k][1] == 1)
          l = in[k][0];
      }//find the left one in in-order
      in[k][1] = 1;
      for(++k; k<n; k++)
      {
        if(in[k][1] == 1)
        {
          r = in[k][0];
          break;
        }
      }//find the right one in in-order
      if(str[l][1] == -1)
        str[l][1] = num;
      else
        str[r][0] = num;
    }
    int k;
    for(k = 0; k<n; k++)
      if(str[in[k][0]][0] == -1 && str[in[k][0]][1] == -1)
      {
       printf("%d", in[k][0]);
       break;
      }
    k++;
    for(; k<n; k++)
      if(str[in[k][0]][0] == -1 && str[in[k][0]][1] == -1)
       printf(" %d", in[k][0]);
    printf("\n");
  }
  return 0;
}
