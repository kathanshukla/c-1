#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#define MAXOP 100


// TODO: Add error function with message, clear and error flag setting

int main() {
  int type, errored;
  double op2, op1;
  char s[MAXOP];

  errored = 0;

  while ((type = getop(s)) != EOF) {
    if (errored) {
      if (type == '\n') {
        errored = 0;
      }
      continue;
    }
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
          errored = 1;
          clear();
        }
        break;
      case '%':
        op2 = pop();
        op1 = pop();
        if (op2 == 0.0) {
          printf("error: zero divisor\n");
          errored = 1;
          clear();
        } else if (op2 != (int)op2 || op1 != (int)op1 ) {
          printf("error: modulo operator only takes integer operands\n");
          errored = 1;
          clear();
        } else {
          push((int)op1 % (int)op2);
        }
        break;
      case SIN:
        push(sin(pop()));
        break;
      case COS:
        push(cos(pop()));
        break;
      case TAN:
        push(tan(pop()));
        break;
      case EXP:
        push(exp(pop()));
        break;
      case POW:
        op2 = pop();
        push(pow(pop(), op2));
        break;
      case '\n':
        printf("%.8g\n", pop());
        clear();
        break;
      default:
        printf("Error: unknown command %s\n", s);
        errored = 1;
        clear();
        break;
    }
  }
  return 0;
}
