#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IN 3
#define DE 2
#define RE 4

int min3(int a, int b, int c) {
  if(a <= b)
    if(a <= c)
      return a;
    else
      return c;
  else
    if(b <= c)
      return b;
    else
      return c;
}

int editDistance1(char *x, char *y, int i, int j) {

  if(i == 0 && j == 0)
    return 0;
  else if(i == 0)
    return 3*j;
  else if(j == 0)
    return 2*i;
  else if(i > 0 && j > 0 && x[i-1] == y[j-1])
    return editDistance1(x, y, i-1, j-1);

  int a = editDistance1(x, y, i-1, j-1) + 4; /* replace */
  int b = editDistance1(x, y, i-1, j) + 2;   /* delete */
  int c = editDistance1(x, y, i, j-1) + 3;   /* insert */

  return min3(a, b, c);
}

int editDistance2(char *x, char *y, int i, int j, int matrix[][16]) {

  if(matrix[i-1][j-1] > 0)
    return matrix[i-1][j-1];

  if(i == 0 && j == 0)
    return 0;
  else if(i == 0)
    return 3*j;
  else if(j == 0)
    return 2*i;
  else if(i > 0 && j > 0 && x[i-1] == y[j-1]) {
    int a = editDistance2(x, y, i-1, j-1, matrix);
    matrix[i-1][j-1] = a;
    return a;
  }

  int a = editDistance2(x, y, i-1, j-1, matrix) + 4; /* replace */
  int b = editDistance2(x, y, i-1, j, matrix) + 2;   /* delete */
  int c = editDistance2(x, y, i, j-1, matrix) + 3;   /* insert */

  matrix[i-1][j-1] = min3(a, b, c);
  return matrix[i-1][j-1];
}

int editDistance3(char *x, char *y, int i, int j){

  int b[i + 1][j + 1];
  int m, n;

  memset(b, 0, (i+1)*(j+1)*sizeof(int));
  for(m = 0; m < i + 1; m++)
    b[m][0] = DE * m;
  for(n = 0; n < j + 1; n++)
    b[0][n] = IN * n;

  for(m = 1; m < i + 1; m++)
    for(n = 1; n < j + 1; n++) {

      int re = b[m-1][n-1] + RE*(x[m-1] != y[n-1]);
      int de = b[m][n-1] + IN;
      int in = b[m-1][n] + DE;

      b[m][n] = min3(re, de, in);
    }

  return b[m-1][n-1];
}

int editDistance(char *x, char *y, int type) {

  int i = strlen(x);
  int j = strlen(y);
  int m[i][j];

  printf ("%s\n", x);
  printf ("%s\n", y);

  switch (type) {
  case 1:
    return editDistance1(x, y, i, j);
    break;
  case 2:
    memset(m, -1, i*j*sizeof(int));
    return editDistance2(x, y, i-1, j-1, m);
    break;
  case 3:
    return editDistance3(x, y, i, j);
    break;
  }
}

int main(int argc, char *argv[])
{
  char *x = "electrical engineering";
  char *y = "computer science";

  char *x1 = "C is a relatively \"low level\" language.";
  char *y1 = "Java is an object-oriented language.";

  int res = editDistance(x, y, 2);

  printf ("distance: %d\n", res);

  return 0;
}

