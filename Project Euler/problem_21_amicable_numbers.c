#include <stdio.h>
#include <math.h>

long d(int n)
{
    int i;
    int sum;

    sum = 1;
    for (i = 2; i < sqrt(n) + 1; i++) {
	if (n % i == 0) {
	    sum += i;
	    sum += n / i;
	}
    }
    return sum;
}

void search(int limit)
{
    long result[limit + 1];
    int i, j;
    int sum;

    memset(result, 0, sizeof(long) * (limit + 1));
    for (i = 100; i <= limit; i++) {
	result[i] = d(i);
    }

    sum = 0;

    for (i = 100; i <= limit; i++) {
	for (j = 100; j <= limit; j++) {
	    if (i != j && result[j] == i && result[i] == j) {
		sum = sum + i + j;
		printf("Pair Found: %d : %d \n", i, j);
		if (j > i)
		  result[j] = 0; //mark off the repeated result
	    }

	}
    }

    printf("%d\n", sum);
}

int main(int argc, char *argv[])
{
    int n;

    scanf("%d", &n);
    search(n);

    return 0;
}
