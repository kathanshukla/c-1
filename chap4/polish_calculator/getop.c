#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"


int is_operator(char c);

// getop - get number or operator from input
int getop(char s[]) {
  int i, c, next, retval;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  i = 0;

  if (is_operator(c)) {
    if (c == '+' || c == '-') {
      next = getch();
      if (isdigit(next)) {
        s[++i] = next;
        while (isdigit(s[++i] = c = getch()))
          ;
        if (c == '.') {
          while (isdigit(s[++i] = c = getch()))
            ;
        }
        s[i] = '\0';
        ungetch(c);
        retval = NUMBER;
      } else {  // Its a + or - followed by something that isnt a digit (its an operator)
        ungetch(next);
        retval = c;
      }
    } else {  // its a *, /, %
      retval = c;
    }
  } else if (isalpha(c)) {
    while (isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    ungetch(c);
    if (strncmp(s, "sin", 3) == 0) {
      retval = SIN;
    } else if (strncmp(s, "tan", 3) == 0) {
      retval = TAN;
    } else if (strncmp(s, "cos", 3) == 0) {
      retval = COS;
    } else if (strncmp(s, "pow", 3) == 0) {
      retval = POW;
    } else if (strncmp(s, "exp", 3) == 0) {
      retval = EXP;
    } else {
      retval = UNKNOWN;
    }
  } else if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
    if (c == '.') {
      while (isdigit(s[++i] = c = getch()))
        ;
    }
    s[i] = '\0';
    ungetch(c);
    retval = NUMBER;
  } else if (c == EOF || c == '\n') {
    retval = c;
  } else {
    retval = UNKNOWN;
  }
  return retval;
}

int is_operator(char c) {
  return (c == '+' || c == '-' || c == '/' || c == '*' || c == '%');
}
