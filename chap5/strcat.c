#include <stdio.h>

int str_concat(char *, char *);
int str_end(char *, char *);

int main() {
  char s[100] = "string with the end";
  char t[] = "the end";
  int end_retval;

  end_retval = str_end(s, t);
  printf("%d\n", end_retval);
}

int str_concat(char *s, char *t) {
  while (*s++ != '\0')
    ;
  s--;
  while ((*s++ = *t++) != '\0')
    ;
  return 0;
}

int str_end(char *s, char *t) {
  char *t_start = t;

  while (*s++ != '\0')
    ;
  while (*t++ != '\0')
    ;
  while ((*s-- == *t--) && (t > t_start))
    ;
  return (t >= t_start);
}
