/*
  Simple LSD-Radix Sort Algo.
  Complexity O(k*n) with k the size of vocabulary

  Useful for sorting chains of elements with limited vocabulary, such
  as string (chain of chars, k ~ 40), or integers (chain of digits, k
  = 10)

  This code works only with integers
 */

#include <stdio.h>

/*
  Params:
    - input integers to sort
    - size of the int array
 */
void
radix_sort(int *data,
	   int size) {
  int i;
  int tmp[size];
  int m = data[0];
  int exp = 1;

  /* find the largest number */
  for (i = 1; i< size; i++) {
    if (m < data[i])
      m = data[i];
  }

  /* loop while there's digits */
  while (m / exp > 0) {
    /* counting sort */
    int bucket[10] = {0};
    /* counting into bucket */
    for (i = 0; i < size; i++)
      bucket[data[i] / exp % 10]++;
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    /* place ints according to counting */
    for (i = size - 1; i >= 0; i--)
      tmp[--bucket[data[i] / exp % 10]] = data[i];
    /* copy back to original array */
    for (i = 0; i < size; i++)
      data[i] = tmp[i];
    /* next digit */
    exp *= 10;
  }
}
