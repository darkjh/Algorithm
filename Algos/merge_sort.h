/* Merge Sort Algo.
   Complexity O(nlogn)*/

#include <stdlib.h>

/*
  Interface
  int mgsort(void *data, int size, int esize, int i, int k, int (*compare) (const void *key1, const void *key2));
  Return Value
  0 if sorting is successful, or –1 otherwise.
*/

/* Merge help routine
   Simple version*/
static int merge(void *data, int esize, int p, int q, int r,
	   int (*compare)(const void *, const void *)) {
  /* Two temp arrays */
  char *a = data, *L, *R;
  int n1 = q - p + 1;
  int n2 = r - q;

  /* Allocate mems */
  if((L = (char*)malloc(n1 * esize)) == NULL)
    return -1;
  if((R = (char*)malloc(n2 * esize)) == NULL)
    return -1;

  int i, j, k;

  /* Copy the two halves into temp arrays */
  for (i = 0; i < n1; i++)
    memcpy(&L[i * esize], &a[(p + i) * esize], esize);
  for (j = 0; j < n2; j++)
    memcpy(&R[j * esize], &a[(q + j + 1) * esize], esize);

  i = j = 0;
  k = p;
  /* Merging */
  while (i < n1 && j < n2 && k < r + 1) {
    if (compare(&L[i * esize], &R[j * esize]) < 0) {
      memcpy(&a[k++ * esize], &L[i++ * esize], esize);
    } else {
      memcpy(&a[k++ * esize], &R[j++ * esize], esize);
    }
  }

  /* Simply add the rest of the not empty temp array, if any */
  while (i < n1 && k < r + 1)
    memcpy(&a[k++ * esize], &L[i++ * esize], esize);
  while (j < n2 && k < r + 1)
    memcpy(&a[k++ * esize], &R[j++ * esize], esize);

  return 0;
}

/* Merge help routine
   More Efficient version*/
static int merge2(void *data, int esize, int p, int q, int r,
		  int (*compare)(const void *, const void *)) {

  char *a = data, *b;
  int i, j, k;
  int n = q - p + 1;

  /* Only one temp array needed */
  if((b = (char *)malloc(n * esize)) == NULL)
    return -1;

  i = 0;
  j = p;

  /* Copy only the first half into temp array */
  while (j <= q)
    memcpy(&b[i++ * esize], &a[j++ * esize], esize);

  i = 0;
  k = p;
  /* Copy back next-greatest number each time */
  while (k < j && j <= r)
    if (compare(&b[i * esize], &a[j * esize]) < 0)
      memcpy(&a[k++ * esize], &b[i++ * esize], esize);
    else
      memcpy(&a[k++ * esize], &a[j++ * esize], esize);

  /* Copy back remaining numbers of first half, if any */
  /* No need to consider the remaining of second half, for
     they are just in place (in the original array) */
  while (k < j)
    memcpy(&a[k++ * esize], &b[i++ * esize], esize);

  return 0;
}

/* Main routine with recursive calls */
int merge_sort(void *data, int esize, int p, int r,
	       int (*compare) (const void *, const void *)) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(data, esize, p, q, compare);
    merge_sort(data, esize, q + 1, r, compare);
    merge2(data, esize, p, q, r, compare);
  }
  return 0;
}
