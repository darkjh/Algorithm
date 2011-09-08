#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(char *a, char *b, unsigned size)
{
  do
    {
      char tmp = *a;
      *a++ = *b;
      *b++ = tmp;
    } while (--size > 0);
}

void
quicksort(void* base,
	  unsigned num,
	  unsigned width,
	  int (*comp)(const void *, const void *))
{
  int j;
  void *pi, *pj, *pn;

  if(num <= 1) return;
  pi = base + (rand() % num) * width;
  swap(base, pi, width);
  pi=base;
  pj = pn = base + num * width;
  for(;;){
    do pi += width; while (pi < pn && comp(pi, base) < 0);
    do pj -= width; while (comp(pj, base) > 0);
    if(pj < pi) break;
    swap(pi, pj, width);
  }
  swap(base, pj, width);
  j = (pj - base) / width;
  quicksort(base, j, width, comp);
  quicksort(base + (j + 1) *width, num-j-1, width, comp);
}

void printlist(int list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
	printf("%d ", list[i]);
    printf("\n");
}

