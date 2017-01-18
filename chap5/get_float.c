#include <ctype.h>
#include <stdio.h>
#include <math.h>
#define SIZE 20


int main() {
  int getfloat(double *), ret_val;
  double array[SIZE];
  double *ap = array;

  for (ret_val=getfloat(ap); ret_val != 0 && ret_val != EOF; ret_val=getfloat(++ap)) {
    printf("Value: %f\tPointer: %p\n", *ap, ap);
  }
}

int getch(void);
void ungetch(int);

int getfloat(double *pn) {
  int c, sign, divide_factor;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    printf("%c is not a digit\n", c);
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (!isdigit(c)) {
    ungetch(c);
    return 0;
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if (c == '.') {
    c = getch();
    for (divide_factor = 1; isdigit(c); c = getch()) {
      divide_factor *= 10;
      *pn = 10 * *pn + (c - '0');
    }
    *pn /= divide_factor;
  }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
