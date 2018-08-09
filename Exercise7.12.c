#include <stdio.h>
#include <string.h>
int check = 0;

void bipartite(int map[][110], int i, int bi[110], int side, int length[])
{
  for(int j=1; j<=length[i]; j++)
  {
    //printf("i is %d j is %d\n", i, j);
    // for(int k=1; k<=9; k++)
    //   printf("%d is %d\n", k, bi[k]);
    if(bi[map[i][j]] == -1*side)
    {
      //printf("%d %d return\n", i, j);
      printf("NO\n");
      check = 1;
      return;
    }
    bi[map[i][j]] = side;
    bipartite(map, map[i][j], bi, -1*side, length);
  }
}

int main()
{
  int n;
  scanf("%d\n", &n);
  for(int i=0; i<n; i++)
  {
    int m;
    scanf("%d", &m);
    int map[110][110];
    int length[110] = {0};
    for(int j=1; j<=m; j++)
      map[j][0] = j;
    int ban;
    int ma;
    while(1)
    {
      scanf("%d", &ban);
      if(ban==-1)
        break;
      scanf("%d", &ma);
      if(ban>ma){int temp = ban; ban = ma; ma = temp;}
      length[ban]++;
      //printf("length is %d\n", length[ban]);
      map[ban][length[ban]] = ma;
    }//build the map of connection
    // for(int j=1; j<=m; j++)
    // {
    //   for(int k=0; k<=length[j]; k++)
    //     printf("%d ", map[j][k]);
    //   printf("\n");
    // }//print the map
    int bi[110] = {0};//the final array
    for(int j=1; j<=m; j++)
    {
      if(check == 1)
        break;
      if(length[j] == 0)
        continue;
      for(int k=1; k<=m; k++)
        bi[k] = 0;
      bi[j] = 1;
      bipartite(map, j, bi, -1, length);
    }
    if(check == 0)
      printf("YES\n");
    check = 0;
  }
  return 0;
}
