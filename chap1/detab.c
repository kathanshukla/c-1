#include <stdio.h>
#define TABSTOP 4

int column = 0;

void output_char(char c) {
  putchar(c);
  if (c == '\n')
    column = 0;
  else
    column++;
}


int main() {
  char c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int cols_to_next_tabstop = column % TABSTOP;
      for (int i = 0; i < cols_to_next_tabstop; i++) {
        output_char(' ');
      }
    } else
      output_char(c);
  }
  return 0;
}
