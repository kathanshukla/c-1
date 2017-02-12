#include <stdio.h>
#include <stdlib.h>


char* func_returning_char_pointer(void);
int* range(int, int);

int main()
{
  int* a = range(1, 10);
  int i = 0;
  while (*(a++)) {
    printf("%d\n", *a);
  }

}

char* func_returning_char_pointer(void)
{
  char* a = "hello";
  return a;
}

int* range(int start, int stop)
{
  // int a[] = {1, 2, 3, 4, 5, 6};
  // return a;
  // Cant do this - array is stored in stack memory and so
  // the array destroyed when the stack frame for the function is popped
  // Need to use heap memory rather than stack memory
  int* a = malloc((stop - start) * sizeof(int));
  int i;
  for (i=start; i<stop; i++) {
    *(a++) = i;
  }
  return a - (stop - start);
}

// range(1, 5) = {1, 2, 3, 4}
