#include <stdio.h>
#define TABSTOP 4

void output_replaced_tab() {
  for (int i = 0; i < TABSTOP; i++) {
    putchar(' ');
  }
}


int main() {
  char c;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      output_replaced_tab();
    } else putchar(c);
  }
  return 0;
}
