#include <stdlib.h>

void quicksort(void *v[], int left, int right, int reversed, int (*comp)(void *, void *))
{
  int i, last, rev_modifier = -2 * reversed + 1;
  void swap(void *v[], int, int);

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if ((*comp)(v[i], v[left]) * rev_modifier < 0)
      swap(v, ++last, i);
  }
  swap(v, left, last);
  quicksort(v, left, last-1, reversed, comp);
  quicksort(v, last+1, right, reversed, comp);
}

void swap(void *v[], int i, int j)
{
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
