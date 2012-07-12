#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertion_sort.h"
#include "merge_sort.h"

#define SIZE 20

/* Sorting Functions */
void merge_sort(int *a, int p, int r);
void insertion_sort(int *a, int n);

/* Random Number Generation Function */
int getRand(int min, int max)
{
    static int Init = 0;
    int rc;

    if (Init == 0) {
	/*
	 *  As Init is static, it will remember it's value between
	 *  function calls.  We only want srand() run once, so this
	 *  is a simple way to ensure that happens.
	 */
	srand(time(NULL));
	Init = 1;
    }

    /*
     * Formula:
     *    rand() % N   <- To get a number between 0 - N-1
     *    Then add the result to min, giving you
     *    a random number between min - max.
     */
    rc = (rand() % (max - min + 1) + min);

    return (rc);
}

/* Printing Array Help Function */
void printArray(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
	printf("%d ", a[i]);
    printf("\n");
}


int main(void)
{
    int i, j;
    int array[SIZE];

    for (j = 0; j < SIZE; j++) {
	array[j] = getRand(0, 1000);
    }
    /* Print un-sorted array */
    printArray(array, SIZE);

    /* Call of sorting functions here */
    //insertion_sort(array, SIZE);
    merge_sort(array, 0, 11);

    /* Print sorted array */
    printArray(array, SIZE);
}
