
/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
 */

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    int sum[1000];
    int i;
    int c;
    int res;
    int k;

    memset(sum, -1, sizeof(int) * 1000);
    sum[0] = 1;
    c = 0;

    for (i = 0; i < 1000; i++) {
	c = 0;
	k = 0;
	while (sum[k] >= 0) {
	    res = sum[k] * 2 + c;
	    sum[k] = (int) (res % 10);
	    c = (int) (res / 10);
	    k++;
	}
	while (c != 0) {
	    sum[k++] = (int) (c % 10);
	    c /= 10;
	}
    }

    i = 0;
    res = 0;
    while (sum[i] >= 0) {
	res += sum[i++];
    }

    printf("%d\n", res);

    return 0;
}
