#include <stdio.h>

int main()
{
    int sum = 0;
    int tmp;
    int fib_s = 1;
    int fib_res = 2;
    int limit;

    scanf("%d", &limit);

    do {
	tmp = fib_res;
	fib_res += fib_s;
	fib_s = tmp;

	if (fib_res % 2 == 1)
	    sum += fib_res;
    } while ((fib_res + fib_s) <= limit);
    sum++;
    printf("Result: %d\n", sum);
    return 0;
}
