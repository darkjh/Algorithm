#include <stdio.h>
#include <stdlib.h>



int max = 5000;

void cal(int num, int *pNow, int *c)
{
    int multiplier;
    int ten, one;

    //calculate multiplier then parse it into two parts
    multiplier = *pNow * num + *c;
    one = multiplier % 10;
    ten = (int) (multiplier / 10);

    //set the one-digit part to the active array case
    *pNow = one;
    //then set the rest of the multiplier to carry
    *c = ten;
}

void show(int *array, int position)
{
    int i;
    for (i = position; i >= 0; i--) {
	printf("%d", *(array + i));
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int a[max];
    int position = 0;
    int p = 0;
    int i;
    int c = 0;
    int limit;

    do {
	scanf("%d", &limit);
    } while (limit <= 0);

    a[0] = 1;

    //main loop
    for (i = 1; i <= limit; i++) {
	p = 0;
	c = 0;
	//multiply with every member in the array, which represents result of faltorial precedent, (n-1)!
	while (p <= position) {
	    cal(i, &a[p], &c);
	    //move to another array member
	    p++;
	}

	//after one round, if the carry is not 0, then put it in higher positions
	while (c != 0) {
	    a[++position] = (int) (c % 10);
	    c /= 10;
	}
    }

    show(a, position);

    return 0;
}
