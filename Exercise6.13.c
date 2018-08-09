#include <stdio.h>
#define min(x, y) (x<y?x:y)
#define max(x, y) (x>y?x:y)

int main()
{
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++)
  {
    int m, n;
    int in1=0, in2=0;
    scanf("%d %d", &m, &n);
    double a1[1010], a2[1010];
    int j, k;
    for(j=0; j<m; j++)
      scanf("%lf", &a1[j]);
    for(k=0; k<n; k++)
      scanf("%lf", &a2[k]);
    double ban = a1[--j], ma = a2[--k];
    a1[++j] = a2[++k] = max(ban, ma);
    double middle;
    for(j=0; j<(m+n)/2; j++)
    {
      if(a1[in1]<=a2[in2])
      {
        middle = a1[in1];
        in1++;
      }
      else {middle = a2[in2]; in2++;}
    }
    if((m+n)%2 == 0)
      printf("%.1f\n", (middle+min(a1[in1], a2[in2]))/2);
    else printf("%.1f\n", min(a1[in1], a2[in2]));
  }
  return 0;
}
