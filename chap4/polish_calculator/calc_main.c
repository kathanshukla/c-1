#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#define MAXOP 100


int main() {
  int type;
  double op2, op1;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        } else {
          printf("error: zero divisor\n");
          return 1;
        }
        break;
      case '%':
        op2 = pop();
        op1 = pop();
        if (op2 == 0.0) {
          printf("error: zero divisor\n");
          return 1;
        } else if (op2 != (int)op2 || op1 != (int)op1 ) {
          printf("error: module operator only takes integer operands\n");
          return 1;
        } else {
          push((int)op1 % (int)op2);
        }
        break;
      case '\n':
        printf("%.8g\n", pop());
        break;
      default:
        printf("Error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}
