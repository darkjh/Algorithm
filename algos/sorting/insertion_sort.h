/*
  Simple Insertion Sort Algo.
  Complexity O(n^2)

  Simple sorting algorithm, can accelerate to O(n) when input is
  already sorted or nearly sorted.
 */

#include <stdlib.h>
#include <string.h>

/*
  Interface
  Param:
    - input data to sort
    - size of input
    - size of a single element
    - compare function
  Return Value:
    - 0 if sorting is successful
    - –1 otherwise.
*/
int
insertion_sort(void *data,
	       unsigned size,
	       unsigned esize,
	       int (*comp)(const void *, const void *)) {

  char *a = data;
  void *key;
  int i, j;

  /* allocate storage for key */
  if((key = (char *)malloc(esize)) == NULL)
    return -1;

  /* main loop */
  for(j = 1; j < size; j++) {
    memcpy(key, &a[j * esize], esize);
    i = j - 1;

    /* seach for the position to insert key */
    while(i >= 0 && comp(&a[i * esize], key) > 0) {
      memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
      i--;
    }
    memcpy(&a[(i + 1) * esize], key, esize);
  }

  free(key);

  return 0;
}
