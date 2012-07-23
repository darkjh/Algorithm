#include <stdio.h>
#include <time.h>

#include "insertion_sort.h"
#include "merge_sort.h"
#include "bubble_sort.h"
#include "quicksort.h"
#include "counting_sort.h"

#define SIZE 20
#define MAX 1000


/* Compare Function */
int compare(const void *key1, const void *key2) {
  if(*(int*)key1 > *(int*)key2)
    return 1;
  else if(*(int*)key1 == *(int*)key2)
    return 0;
  else
    return -1;
}


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
    int j;
    int array[SIZE];

    for (j = 0; j < SIZE; j++) {
	array[j] = getRand(0, MAX);
    }
    /* Print un-sorted array */
    printArray(array, SIZE);

    /* Call of sorting functions here */
    //issort(array, SIZE, sizeof(int), compare);

    //quicksort(array, SIZE, sizeof(int), compare);

    //merge_sort(array, sizeof(int), 0, 19, compare);

    // bubble_sort(array, SIZE, sizeof(int), compare);

    counting_sort(array, SIZE, MAX);

    /* Print sorted array */
    printArray(array, SIZE);

    return 0;
}
