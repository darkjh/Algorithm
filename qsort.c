#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int partition(int A[], int p, int r)
{
    int pivot;
    int i, j;

    pivot = A[r];
    i = p - 1;
    for (j = p; j < r; j++) {
	if (A[j] <= pivot) {
	    i++;
	    swap(&A[i], &A[j]);
	}
    }
    swap(&A[i + 1], &A[r]);
    return i + 1;
}

void quicksort(int A[], int p, int r)
{
    if (p < r) {
	int q = partition(A, p, r);
	quicksort(A, p, q - 1);
	quicksort(A, q + 1, r);
    }
}

void printlist(int list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
	printf("%d ", list[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    const int MAX = 10;
    int list[MAX];

    int i = 0;
    srand(time(NULL));
    for (i = 0; i < MAX; i++)
	list[i] = rand() >> 24;

    printlist(list, MAX);
    quicksort(list, 0, MAX - 1);
    printlist(list, MAX);

    //free(list);
    return 0;
}
