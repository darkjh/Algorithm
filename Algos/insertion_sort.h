/* Simple Insertion Sort Algo. */

#include <stdlib.h>
#include <string.h>

/*
  Interface
  int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));
  Return Value: 0 if sorting is successful, or –1 otherwise.
*/

/* Main routine */
int issort(void *data, int size, int esize,
	   int (*compare)(const void *key1, const void *key2)) {

  char *a = data;
  void *key;
  int i, j;

  /* Allocate storage for key */
  if((key = (char *)malloc(esize)) == NULL)
    return -1;

  /* Main loop */
  for(j = 1; j < size; j++) {
    memcpy(key, &a[j * esize], esize);
    i = j - 1;

    /* Seach for the position to insert key */
    while(i >= 0 && compare(&a[i * esize], key) > 0) {
      memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
      i--;
    }
    memcpy(&a[(i + 1) * esize], key, esize);
  }

  free(key);

  return 0;
}
