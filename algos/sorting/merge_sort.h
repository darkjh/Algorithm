/* Merge Sort Algo.
   Complexity O(nlogn)*/

#include <stdlib.h>

/* merge help routine
   simple version*/
static int
merge(void *data,
      int esize,
      int p,
      int q,
      int r,
      int (*compare)(const void *, const void *)) {
  /* two temp arrays */
  char *a = data, *L, *R;
  int n1 = q - p + 1;
  int n2 = r - q;

  /* allocate mems */
  if((L = (char*)malloc(n1 * esize)) == NULL)
    return -1;
  if((R = (char*)malloc(n2 * esize)) == NULL)
    return -1;

  int i, j, k;

  /* copy the two halves into temp arrays */
  for (i = 0; i < n1; i++)
    memcpy(&L[i * esize], &a[(p + i) * esize], esize);
  for (j = 0; j < n2; j++)
    memcpy(&R[j * esize], &a[(q + j + 1) * esize], esize);

  i = j = 0;
  k = p;
  /* merging */
  while (i < n1 && j < n2 && k < r + 1) {
    if (compare(&L[i * esize], &R[j * esize]) < 0) {
      memcpy(&a[k++ * esize], &L[i++ * esize], esize);
    } else {
      memcpy(&a[k++ * esize], &R[j++ * esize], esize);
    }
  }

  /* simply add the rest of the not empty temp array, if any */
  while (i < n1 && k < r + 1)
    memcpy(&a[k++ * esize], &L[i++ * esize], esize);
  while (j < n2 && k < r + 1)
    memcpy(&a[k++ * esize], &R[j++ * esize], esize);

  return 0;
}

/* merge help routine
   more efficient version*/
static int
merge2(void *data,
       int esize,
       int p,
       int q,
       int r,
       int (*compare)(const void *, const void *)) {
  char *a = data, *b;
  int i, j, k;
  int n = q - p + 1;

  /* only one temp array needed */
  if((b = (char *)malloc(n * esize)) == NULL)
    return -1;

  i = 0;
  j = p;

  /* copy only the first half into temp array */
  while (j <= q)
    memcpy(&b[i++ * esize], &a[j++ * esize], esize);

  i = 0;
  k = p;
  /* copy back next-greatest number each time */
  while (k < j && j <= r)
    if (compare(&b[i * esize], &a[j * esize]) < 0)
      memcpy(&a[k++ * esize], &b[i++ * esize], esize);
    else
      memcpy(&a[k++ * esize], &a[j++ * esize], esize);

  /* copy back remaining numbers of first half, if any */
  /* no need to consider the remaining of second half, for
     they are just in place (in the original array) */
  while (k < j)
    memcpy(&a[k++ * esize], &b[i++ * esize], esize);

  return 0;
}

/*
  main routine with recursive calls
  params:
    - input data to sort
    - size of the input
    - size of a single element
    - compare function
  return value:
    - 0 if sorting is successful
    - –1 otherwise.
*/
int
merge_sort(void *data,
	   int esize,
	   int p,
	   int r,
	   int (*compare) (const void *, const void *)) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(data, esize, p, q, compare);
    merge_sort(data, esize, q + 1, r, compare);
    merge2(data, esize, p, q, r, compare);
  }
  return 0;
}
