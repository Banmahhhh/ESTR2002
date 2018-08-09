#include <stdio.h>
#include <string.h>

int main(void)
{
  int n;
  scanf("%d\n", &n);
  for(int i = 0; i<n; i++)
  {
    int check = 0;
    char strings[210];
    gets(strings);
    int length = strlen(strings);
    if(strings[length/2] != ' ' || length%2 == 0)
    {
      printf("NO\n");
      continue;
    }
    else
    {
      int s[30] = {0}, t[30] = {0};
      for(int j = 0; j<length/2; j++)
      {
        int sa = strings[j]-96;
        int ta = strings[j+length/2+1]-96;
        if(s[sa] == 0)
          s[sa] = ta;
        else if(s[sa] != ta)
          {
            check = 1;
            printf("NO\n");
            break;
          }
        if(t[ta] == 0)
          t[ta] = sa;
        else if(t[ta] != sa)
          {
            check = 1;
            printf("NO\n");
            break;
          }
      }
      if(check == 0)
        printf("YES\n");
    }
  }
  return 0;
}
