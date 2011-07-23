/*
Starting in the top left corner of a 2*2 grid, there are 6 routes (without backtracking) to the bottom right corner.
How many routes are there through a 20*20 grid?
*/

#include <stdio.h>
#include <stdlib.h>

#define grid_size 8

/*
Simple recursive approache
Inside the function, with every recursive call, we move forward a little.
 */
int path_rec(int x, int y)
{
  int i=0;

  if (x < grid_size)
    i += path_rec(x+1,y);
  if (y < grid_size)
    i+= path_rec(x,y+1);

  if(x==grid_size && y==grid_size)
    return 1;

  return i;
}

/*
A backtracing method
With one point in the grid given, we have its routes possibilities:
   routes[point] = routes[its right point] + routes[its downside point]
And in the far right column and the button line, we can only go strait down or right, so thest points' routes are all 1
Then we can calculate one by one all others' routes, and finally, we calculate the first point, that is the answer.
 */

long long path(int size)
{
  //must have the long long int
  long long int grid[size][size];
  int i,j;

  memset(grid,0,sizeof(long long)*(size*size));
  //set the far right colunm and bottom line points to 1
  for(i=0;i<size;i++)
    {
      grid[i][size-1]=1;
      grid[size-1][i]=1;
    }

  //calculate loop
  for(i=size-2;i>=0;i--)
    {
      //calculate the pivot point (grid[i][i])
      grid[i][i]=grid[i+1][i]+grid[i][i+1];
      j=i;
      //calculate others
      while((--j)>=0)
  	{
    	  grid[i][j]=grid[i+1][j]+grid[i][j+1];
	  grid[j][i]=grid[j+1][i]+grid[j][i+1];
  	}
    }
  return grid[0][0];
}

int main(int argc, char *argv[])
{
  int size;
  scanf("%d",&size);
  //printf ("%d\n",path_rec(0,0));
  printf ("%lli\n",path(size));
  return 0;
}
