/*
  Quicksort Algo. (randomized)
  Complexity O(nlgn)

  Very popular and efficient sorting algorithm.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
swap(char *a, char *b, unsigned size)
{
    do {
	char tmp = *a;
	*a++ = *b;
	*b++ = tmp;
    } while (--size > 0);
}

int
partition(void *data,
	  unsigned size,
	  unsigned esize,
	  int (*comp) (const void *, const void *)) {

  void *pi, *pj, *pn;

  /* randomly pick a pivot */
  pi = data + (rand() % size) * esize;
  swap(data, pi, esize);
  pi = data;
  pj = pn = data + size * esize;

  for (;;) {
    do
      pi += esize;
    while (pi < pn && comp(pi, data) < 0);
    do
      pj -= esize;
    while (comp(pj, data) > 0);
    if (pj < pi)
      break;
    swap(pi, pj, esize);
  }
  swap(data, pj, esize);
  return (pj - data) / esize;
}

/* main function
   param:
     - input data to sort
     - size of input data
     - size of a sinlge element
     - compare function
   return Value:
     - 0 if sorting is successful
     - –1 otherwise.
*/
void
quicksort(void *data,
	  unsigned size,
	  unsigned esize,
	  int (*comp) (const void *, const void *))
{
  /* base case */
  if (size <= 1)
    return;

  int q;
  q = partition(data, size, esize, comp);
  quicksort(data, q, esize, comp);
  quicksort(data + (q + 1) * esize, size - q - 1, esize, comp);
}
