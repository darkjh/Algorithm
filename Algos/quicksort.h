p/* Quicksort Algo. (randomized) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  Interface
  int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));
  Return Value: 0 if sorting is successful, or –1 otherwise.
*/

void swap(char *a, char *b, unsigned size)
{
    do {
	char tmp = *a;
	*a++ = *b;
	*b++ = tmp;
    } while (--size > 0);
}

int partition(void *data, unsigned size, unsigned esize,
	      int (*compare) (const void *, const void *)) {

  void *pi, *pj, *pn;

  /* randomly pick a pivot */
  pi = data + (rand() % size) * esize;
  swap(data, pi, esize);
  pi = data;
  pj = pn = data + size * esize;

  for (;;) {
    do
      pi += esize;
    while (pi < pn && compare(pi, data) < 0);
    do
      pj -= esize;
    while (compare(pj, data) > 0);
    if (pj < pi)
      break;
    swap(pi, pj, esize);
  }
  swap(data, pj, esize);
  return (pj - data) / esize;
}

void
quicksort(void *data,
	  unsigned size,
	  unsigned esize, int (*compare) (const void *, const void *))
{
  /* base case */
  if (size <= 1)
    return;

  int q;
  q = partition(data, size, esize, compare);
  quicksort(data, q, esize, compare);
  quicksort(data + (q + 1) * esize, size - q - 1, esize, compare);
}
