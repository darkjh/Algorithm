/*
  Simple Heap Sort Algo.
  Complexity O(nlgn)

  Sorting algorithm backed by a max heap data structure, not
  stable. It's slower than quicksort in practice because of data
  locality.
 */

#include <stdio.h>

/* get left child index in a binary heap */
inline int
left_child(int i) {
  return 2 * i;
}

/* swap two elements of given size */
inline void
swap(void *this, void *that, int esize) {
  void *tmp = (void *)malloc(esize);
  memcpy(tmp, this, esize);
  memcpy(this, that, esize);
  memcpy(that, tmp, esize);
  free(tmp);
}

/* adjust an element in the max heap to satisfy the max heap
   property */
void
adjust_down(void *data,
	    int esize,
	    int i,
	    int n,
	    int (*comp)(const void *, const void *)) {
  int child = i;
  void *key = &data[i * esize];

  while ((child = left_child(child)) < n) {
    /* find bigger one of the two children */
    if (child != n - 1
	&& comp(&data[child * esize],
		   &data[(child + 1) * esize]) < 0) {
      child++;
    }
    /* swap the key with its bigger child
       if violation of max heap property */
    if (comp(key, &data[child * esize]) < 0) {
      swap(key, &data[child * esize], esize);
      key = &data[child * esize];
    } else {
      break;
    }
  }
}

void
heap_sort(void *data,
	 int size,
	 int esize,
	 int (*comp)(const void *, const void *)) {
  /* construction of max heap */
  int i;
  for (i = size / 2; i >= 0; i--) {
    adjust_down(data, esize, i, size, comp);
  }

  /* take the max and place it in the right position
     shrink the heap */
  for (i = size - 1; i > 0; i--) {
    swap(&data[0], &data[i * esize], esize);
    adjust_down(data, esize, 0, i, comp);
  }
}
