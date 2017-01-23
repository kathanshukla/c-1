#include <stdio.h>

int get_line(char *s, int lim) {
  int c;
  char *s_start = s, *pointer_lim = s + lim;

  while (s < pointer_lim && (c=getchar())!=EOF && c!='\n')
    *s++ = c;
  if (c == '\n') {
    *s++ = c;
  }
  *s = '\0';
  return s - s_start;
}
