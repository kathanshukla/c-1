#include <ctype.h>
#include <stdio.h>
#define SIZE 20



int main() {
  int retval, array[SIZE], getint(int *), *ap;
  ap = array;

  for (retval=getint(ap); retval != 0 && retval != EOF; retval=getint(++ap))
    printf("%d\n", *ap);
}

int getch(void);
void ungetch(int);

int getint(int *pn) {
  int c, sign;

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
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
