#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char banma[], int start)
{
  int rep = 0;
  char num[200000]; num[0] = '\0';
  for(int i = start; i<strlen(banma); i++)
  {
    int bran = 0;
    if(banma[i] == 40)
    {
      bran++;
      int k;
      for(k = i-1; banma[k] >=48 && banma[k] <= 57; k--)
        num[strlen(num)] = banma[k];
      for(int b = 0; b<strlen(num)/2; b++)
      {int temp=num[b]; num[b]=num[strlen(num)-b-1]; num[strlen(num)-b-1]=temp;}
      rep = atoi(num);
      num[0] = '\0';
      for(int j = 0; j<rep; j++)
        print(banma, i+1);
      i++;
      while(bran != 0)
      {
        if(banma[i] == ')')
          bran--;
        else if(banma[i] == '(')
          bran++;
        i++;
      }
      i--;
    }
    else if(banma[i] == 41)
      break;
    else
    {
      if(banma[i]>=48 && banma[i]<=57)
      {
        int b;
        for(b = 0; banma[i+b]>=48 && banma[i+b]<=57; b++){};
        if(banma[i+b] != 40)
          printf("%c", banma[i]);
      }
      else
        printf("%c", banma[i]);
    }
  }
}

int main(void)
{
  int m;
  scanf("%d\n", &m);
  for(int i = 0; i<m; i++)
  {
    char banma[20000];
    gets(banma);
    print(banma, 0);
    printf("\n");
  }
  return 0;
}
