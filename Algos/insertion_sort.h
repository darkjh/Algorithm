/* Simple Insertion Sort Algo.
   Complexity O(n^2)*/

/* Param: array adress, array length */
/* Return: none */
void insertion_sort(int *a, int n)
{
    int i, j, key;
    for (j = 1; j < n; j++) {
	key = a[j];
	i = j - 1;
	while (i >= 0 && a[i] > key) {
	    a[i + 1] = a[i];
	    i--;
	}
	a[i + 1] = key;
    }
}
