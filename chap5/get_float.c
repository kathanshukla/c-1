#include <ctype.h>
#include <stdio.h>
#define SIZE 20


int main() {
  int n, getfloat(double *);
  double array[SIZE];

  for (n = 0; n < SIZE && getfloat(&array[n]) != 0 && getfloat(&array[n]) != EOF; n++)
    printf("%f\n", array[n]);
}

int getch(void);
void ungetch(int);

// Figure out why this doesnt work
int getfloat(double *pn) {
  int c, sign, decimal_places;

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
    for (decimal_places = 0; isdigit(c); c = getch()) {
      decimal_places++;
      *pn = 10 * *pn + (c - '0');
    }
    *pn /= 10 * decimal_places;
  }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
