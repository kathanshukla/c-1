#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;


// get a character from input
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}


// put a character onto input buffer
void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: buffer overflow\n");
  } else {
    buf[bufp++] = c;
  }
}
