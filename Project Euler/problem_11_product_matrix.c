#include <stdio.h>
#include <string.h>

int matrix[20][20];

int cal_matrix(int startX, int startY)
{
  int product=0;
  int temp=1;
  int i,j;

  for(i=startX;i<startX+4;i++)
    {
      for(j=startY;j<startY+4;j++)
	{
	  temp*=matrix[i][j];
	}
      if(temp>product)
	product=temp;
      temp=1;
    }
  for(j=startY;j<startY+4;j++)
    {
      for(i=startX;i<startX+4;i++)
	{
	  temp*=matrix[i][j];
	}
      if(temp>product)
	product=temp;
      temp=1;
    }
  i=startX;
  j=startY;
  while(i<startX+4)
    {
      temp*=matrix[i][j];
      i++;
      j++;
    }
  if(temp>product)
    product=temp;
  temp=1;
  i=startX+3;
  j=startY;
  while(j<startY+4)
    {
      temp*=matrix[i][j];
      i--;
      j++;
    }
  if(temp>product)
    product=temp;


  return product;
}

int main(int argc, char *argv[])
{
  int i,j;
  char tmp_1,tmp_2,waste;
  FILE* fp;
  //int matrix[20][20];
  int temp[20*20];
  int tmp;
  int product=0;

  memset(matrix,0,sizeof(int)*400);
  fp=fopen("file_problem_11","r");

  for(i=0;i<20*20;i++)
    {
      fscanf(fp,"%c%c",&tmp_1,&tmp_2);
      *(temp+i)=((int)tmp_1-'0')*10 + ((int)tmp_2-'0');
      fscanf(fp,"%c",&waste);
    }
  for(i=0;i<20;i++)
    for (j=0;j<20;j++)
      matrix[i][j]=temp[i*20+j];

  for(i=0;i<=16;i++)
    for(j=0;j<=16;j++)
      {
	tmp=cal_matrix(i,j);
	if(product<tmp)
	  product=tmp;
      }


  return product;;
}
