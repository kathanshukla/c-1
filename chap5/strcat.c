#include <stdio.h>

int str_concat(char *, char *);
int str_end(char *, char *);

int main() {
  char s[100] = "string with the end";
  char t[] = "";
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

// str_end - returns 1 if second string argument occurs at end of first string
// if t is empty string, returns 1
int str_end(char *s, char *t) {
  char *t_start = t;

  if (*t == '\0') {
    return 1;
  } else if (*s == '\0') {
    // s is empty string but t is not
    return 0;
  }

  while (*++s != '\0')
    ;
  while (*++t != '\0')
    ;
  while ((*--s == *--t) && (t >= t_start))
    ;
  return (t == t_start - 1);
}
