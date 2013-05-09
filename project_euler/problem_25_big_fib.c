#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) { \
  int *tmp=a; \
  a=b; \
  b=tmp; \
}

int MAX_BIT = 1000;

void cal(int *res, int *adder, int *pos)
{
    int c, i, tmp;
    for (i = c = 0; i < *pos; i++) { /* calculation with every digit */
	tmp = res[i] + adder[i] + c;
	res[i] = tmp % 10;
	c = (int) (tmp / 10);
    }
    while (c != 0) {		/* if c is not zero means that the result */
	res[(*pos)++] = c % 10;	/* has more digits  */
	c /= 10;
    }
}

int main(int argc, char *argv[])
{
    int *f1, *f2;
    int position, count;

    f1 = (int *) malloc(sizeof(int) * MAX_BIT);
    f2 = (int *) malloc(sizeof(int) * MAX_BIT);

    position = 0;
    memset(f1, 0, sizeof(int) * MAX_BIT);
    memset(f2, 0, sizeof(int) * MAX_BIT);
    f1[0] = f2[0] = 1;
    position = 1;
    count = 2;
    while (position < 1000) {
	cal(f1, f2, &position);
	swap(f1, f2);
	count++;
    }

    printf("res: %d\n", count);

    return 0;
}
