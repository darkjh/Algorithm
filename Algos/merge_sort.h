/* Merge Sort Algo.
   Complexity O(nlogn)*/

/* Merge help routine
   Simple version*/
/* Param: array, low index, median index, high index */
/* Return: none */
void merge(int *a, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    int i, j, k;

    /* Copy the two halves into temp arrays */
    for (i = 0; i < n1; i++)
	L[i] = a[p + i];
    for (j = 0; j < n2; j++)
	R[j] = a[q + j + 1];

    i = j = 0;
    k = p;
    /* Merging */
    while (i < n1 && j < n2 && k < r + 1) {
	if (L[i] < R[j]) {
	    a[k++] = L[i++];
	} else {
	    a[k++] = R[j++];
	}
    }

    /* Simply add the rest of temp array, if any */
    while (i < n1 && k < r + 1)
	a[k++] = L[i++];
    while (j < n2 && k < r + 1)
	a[k++] = R[j++];
}

/* Merge help routine
   Efficient version*/
/* Param: array, low index, median index, high index */
/* Return: none */
void merge2(int *a, int p, int q, int r)
{
    int i, j, k;
    int b[r - q];

    i = 0;
    j = p;

    /* Copy only the first half into temp array */
    while (j <= q)
	b[i++] = a[j++];

    i = 0;
    k = p;
    /* Copy back next-greatest number each time */
    while (k < j && j <= r)
	if (b[i] < a[j])
	    a[k++] = b[i++];
	else
	    a[k++] = a[j++];
    /* Copy back remaining numbers of first half, if any */
    /* No need to consider the remaining of second half, for
       they are just in place (in the original array) */
    while (k < j)
	a[k++] = b[i++];
}

/* Main routine with recursive calls */
void merge_sort(int *a, int p, int r)
{
    if (p < r) {
	int q = (p + r) / 2;
	merge_sort(a, p, q);
	merge_sort(a, q + 1, r);
	merge2(a, p, q, r);
    }
}
