/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

#include <stdio.h>

int normal[13]={1,31,28,31,30,31,30,31,31,30,31,30,31};
int leap[13]={1,31,29,31,30,31,30,31,31,30,31,30,31};

int isleap(int year)
{
  if((year%100==0 && year%400==0) || (year%100!=0 && year%4==0))
    return 1;
  else
    return 0;
}

int isInArray(int num, int* array, int len)
{
  int i;

  for(i=0;i<len;i++)
    if(num==array[i])
      return 1;
  return 0;
}

int main(int argc, char *argv[])
{
  int year;
  int day;
  int i;
  int count;
  int c;

  for(i=1;i<13;i++)
    {
      normal[i]+=normal[i-1];
      leap[i]+=leap[i-1];
    }
  /* for(i=0;i<12;i++) */
  /*   printf("%d ", normal[i]); */
  /* scanf("%d",&year); */
  /* printf("\n%d\n", isleap(year)); */

  year=1900;
  count=0;
  c=7;

  while(year<2001)
    {
      if(c==0)
	c=7;
      day=c;
      if(isleap(year))
	{
	  while(day<=366)
	    {
	      if(isInArray(day,leap,12))
		count++;
	      day+=7;
	    }
	  c=day-365;
	  year++;
	}
      else
	{
	  while(day<=365)
	    {
	      if(isInArray(day,normal,12))
		count++;
	      day+=7;
	    }
	  c=day-366;
	  year++;
	}
    }

  printf ("res: %d\n", count);
  return 0;
}
