#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  int sum=0;
  int n;

  scanf("%d",&n);
  for(i=3;i<n;i++) //it says 'below 1000'
    {
      if(i%3==0 || i%5==0) sum+=i;
    }
  printf("The result is: %d\n",sum);
}
