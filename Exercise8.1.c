#include <stdio.h>
#include <string.h>

int min(int a, int b, int c)
{
  if(a>b)
    if(b>c)
      return c;
    else
      return b;
  else if(a>c)
    return c;
    else return a;
}

int main(void)
{
  int n;
  scanf("%d\n", &n);
  for(int i=0; i<n; i++)
  {
    char s[110];
    char t[110];
    int map[110][110];
    gets(s);
    gets(t);
    int m = strlen(s), n = strlen(t);
    for(int j = 0; j<=m; j++)
      map[j][0] = map[0][j] = j;
    for(int j = 1; j<=m; j++)
    {
      for(int k = 1; k<=n; k++)
      {
        if(s[j-1] == t[k-1])
          map[j][k] = map[j-1][k-1];
        else map[j][k] = (1+min(map[j-1][k-1], map[j-1][k], map[j][k-1]));
      }
    }
    printf("%d\n", map[m][n]);
  }
  return 0;
}
