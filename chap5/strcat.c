#include <stdio.h>

int str_concat(char *, char *);

int main() {
  char s[100] = "s";
  char t[] = "OK - longer this time";
  str_concat(s, t);
  printf("%s\n", s);
}

int str_concat(char *s, char *t) {
  while (*s++ != '\0')
    ;
  s--;
  while ((*s++ = *t++) != '\0')
    ;
  return 0;
}
