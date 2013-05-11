/* Simple Counting Sort Algo. */
/* Complexity O(n) with assumption that the elements are bounded by k*/
/* k ~ O(n) */
/* for integer sorting only */

#include <stdlib.h>
#include <string.h>

/*
  params:
    - input data to be sort (int)
    - size of the input
    - max value occured in input
  return value:
    - 0 if sorting is successful
    -  –1 otherwise
*/
int
counting_sort(int *data, int size, int k) {

  int *a = data, *counts, *tmp;
  int i,j;

  /* allocate the counts array and initialization */
  if ((counts = (int *)malloc(k * sizeof(int))) == NULL)
    return -1;
  memset(counts, 0, k * sizeof(int));

  /* temp array for storing results */
  if ((tmp = (int *)malloc(size * sizeof(int))) == NULL) {
    free(counts);
    return -1;
  }

  /* counting */
  for(j = 0; j < size; j++)
    counts[a[j]]++;

  /* count[i] is the number of elements that are inferior to i
     in the array to sort */
  for(i = 1; i < k; i++)
    counts[i] = counts[i] + counts[i - 1];

  /* put every elements in the right position */
  for(j = size - 1; j >= 0; j--) {
    tmp[counts[a[j]] - 1] = a[j];
    counts[a[j]]--;
  }

  memcpy(data, tmp, size * sizeof(int));
  free(tmp);
  free(counts);

  return 0;
}
