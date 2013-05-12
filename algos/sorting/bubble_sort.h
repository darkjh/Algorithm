/*
  Bubble Sort Algo.
  Complexity O(n^2)

  Simple algorithm for sorting
 */

#include <stdlib.h>

/* Bubble Sort routine */
/* Params:
     - input data to sort
     - size of input
     - size of a single element
     - compare function
   Return Value:
     - 0 if sorting is successful
     - –1 otherwise
*/
int bubble_sort(void *data,
		int size,
		int esize,
		int (*compare)(const void *, const void *)) {

  char *a = data, *m;
  int i, j;

  /* outter loop */
  /* first i elements are the i-ist smallest and in sorted order */
  for(i = 1; i < size; i++)
    for(j = size - 1; j >= i; j--)
      if(compare(&a[j * esize], &a[(j - 1) * esize]) < 0) {
	/* swap elements */
	if((m = (char *)malloc(esize)) == NULL)
	  return -1;
	memcpy(m, &a[j * esize], esize);
	memcpy(&a[j * esize], &a[(j - 1) * esize], esize);
	memcpy(&a[(j - 1) * esize], m, esize);
	free(m);
      }

  return 0;
}
