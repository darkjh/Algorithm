#include <stdio.h>
#include <stdlib.h>

int max=5000;

void cal(int num, int* pNow, int* c)
{
  int sum;
  int ten,one;

  sum=*pNow * num + *c;
  one=sum%10;
  ten=(int)(sum/10);

  //printf("num:%d sum:%d c:%d one:%d ten:%d\n",num,sum,*c, one, ten);

  *pNow=one;
  *c=ten;
}

void show(int* array, int position)
{
    int i;
    for(i=position;i>=0;i--)
    {
        printf("%d",*(array+i));
    }
}

int main(int argc, char *argv[])
{
  int a[max];
  int position=0;
  int p=0;
  int i;
  int c=0;
  int limit;

  do
  {
      scanf("%d",&limit);
  }while(limit<=0);

  a[0]=1;
  for(i=1;i<=limit;i++)
    {
      p=0;
      c=0;
      while(p<=position)		//not sure
	{
	  cal(i,&a[p],&c);
	  p++;
	}

      //if(a[position+1]!=0) position++;
      position=p;
      while(c!=0)
	{
	  a[position++]=(int)(c%10);
	  c/=10;
	}
    }

    show(a,position-3);
    free(a);

  return 0;
}
