#include <stdio.h>

int max=5000;

void cal(int num, int* pNow, int* c)
{
  int sum;
  int ten,one;

  sum=*pNow * num;
  one=sum%10+(*c);
  ten=(sum/10);

  printf("num:%d sum:%d c:%d one:%d ten:%d\n",num,sum,*c, one, ten);

  if(one>=10)
    {
      one=one%10;
      ten++;
    }
  if(sum<10)
    {
      *pNow=one;
      *c=0;
    }
  else
    {
      *pNow=one;
      *c=ten;
    }
}


int main(int argc, char *argv[])
{
  int a[7]={0,0,0,0,0,0,0};
  int position=0;
  int p=0;
  int i;
  int c=0;
  int limit;

  scanf("%d",&limit);
  a[0]=1;
  for(i=1;i<=limit;i++)
    {
      p=0;
      c=0;
      while(p<=position)
	{
	  cal(i,&a[p],&c);
	  p++;
	}
      //if(a[position+1]!=0) position++;
      while(c!=0)
	{
	  a[position++]=(int)(c%10);
	  c/=10;
	}
    }

  printf("result=%d%d%d%d%d%d%d\n",a[6],a[5],a[4],a[3],a[2],a[1],a[0]);

  return 0;
}
