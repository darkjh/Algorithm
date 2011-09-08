#include <stdio.h>
#include <math.h>

#define LIMIT 30000
#define S_LIMIT 20162

long sum_factors_1(int a)
{
    int i, t;
    long sum = 1;
    for (i = 2, t = sqrt(a); i < t + 1; i++) {
	if (a % i == 0) {
	    sum += i;
	    sum += a / i;
	}
    }
    if (t * t == a)		// ex. 25 = 5 * 5, and the proper divisors has only one 5
	sum -= t;
    return sum;
}

long sum_factors(int a)
{
    int i, sum;
    sum = 0;
    for (i = 1; i < (int) (a / 2 + 1); i++) {
	if (a % i == 0)
	    sum += i;
    }
    return sum;
}

int is_abundant(int a)
{
    return (sum_factors_1(a) > a) ? 1 : 0;
}

/* int is_sum_abundant(int num, int* a, int len) */
/* { */
/*   int i,j; */
/*   for(i=0;i<len;i++) */
/*     { */
/*       for(j=0;j<len;j++) */
/* 	{ */
/* 	  if((a[i]+a[j])==num) */
/* 	    return 1; */
/* 	  else if ((a[i]+a[j])>num) */
/* 	    break; */
/* 	} */
/*     } */
/*   return 0; */
/* } */

int main(int argc, char *argv[])
{
    int abundant[20000];
    int i, j, len, tmp;
    char candidate[LIMIT];	//from 0 to 20161
    long long sum;

    for (i = 1, j = 0; i < LIMIT; i++) {
	if (is_abundant(i))
	    abundant[j++] = i;
    }

    len = j;
    printf("%d\n", len);
    memset(candidate, 1, sizeof(char) * LIMIT);
    for (i = 0; i < len; i++) {
	for (j = i; j < len; j++) {
	    if ((tmp = abundant[i] + abundant[j]) < LIMIT)
		candidate[tmp] = 0;
	    else
		break;
	}
    }

    for (i = 1, sum = 0; i < LIMIT; i++) {
	if (candidate[i] == 1)
	    sum += i;
    }

    printf("res: %lli \n", sum);
    return 0;
}
