#define SWAP(x,y) {int t;t=x;x=y;y=t;}

/* Bubble Sort Algo.
   Complexity O(n^2) */

/* Bubble Sort routine */
/* Param: array, size */
/* Return: none */
void bubble_sort(int *a, int n) {
  int i,j;

  /* Outter loop */
  /* First i elements are smallest and in sorted order */
  for(i=1;i<n;i++)
    /* Inner loop */
    /* first element sub-array from j to n is the smallest */
    for(j=n-1;j>=i;j--) {
      if(a[j]<a[j-1])
	SWAP(a[j],a[j-1]);
    }
}

