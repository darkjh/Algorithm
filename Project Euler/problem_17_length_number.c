/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <stdio.h>

/* The arrays that contain predefined word length:
 digits for numbers from 1 to 19
 tens for 10, 20 to 90
*/
int digits[20] =
  { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
int ten[10] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
int tens[10] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };

int and = 3;
int hundred = 7;
int thousand = 8;

/*Parse out the number's lowest digit
 for the use of process function
 if the number is 0, then return -1
 if not return the digit parsed
*/
int
parser (int *num)
{
  int res;
  if (*num > 0)
    {
      res = (int) (*num % 10);
      (*num) /= 10;
    }
  else
    res = -1;
  return res;
}

/*Process the number given according to the level i
 i=0: one digit level
 i=1: tens level
 i=2: hundreds level
 i=3: thousands level
 Adds up the length then return it
*/
int
process (int num, int i)
{
  int res = 0;
  int result = 0;

  while ((res = parser (&num)) != -1)
    {
      if (i == 0)
	{
	  result += digits[res];
	  i++;
	}
      else if (i == 1)
	{
	  result += tens[res];
	  i++;
	}
      else if (i == 2)
	{
	  if (res != 0)
	    result += (hundred + and);
	  result += digits[res];
	  i++;
	}
      else if (i == 3)
	{
	  result += thousand;
	  result += digits[res];
	  i++;
	}
    }
  return result;
}

/*Iter through 1 to 1000 and call process for each number
 */
int
main (int argc, char *argv[])
{

  int result = 0;
  int num, tmp, iter;

  /* scanf("%d",&iter); */

  iter = 0;

  while ((iter++) <= 1000)
    {
      num = iter;
      tmp = (int) (num % 100);
      if (tmp < 20)
	{
	  result += digits[tmp];
	  result += process ((int) (num /= 100), 2);
	}
      else
	{
	  result += process (num, 0);
	}

    }

  printf ("res:%d\n", result);

  return 0;
}

