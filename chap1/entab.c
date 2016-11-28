#include <stdio.h>
#define TABSTOP 4
#define SPACE '*'
#define TAB '$'

int column = 0;
int spaces_read = 0;

int should_output_tab(char c) {
  if ((c == SPACE) && (column % TABSTOP == 0))
    return 1;
  else
    return 0;
}

int should_output_spaces(char c) {
  if ((c != SPACE) && (spaces_read > 0)) return 1;
  else return 0;
}

void output_char(char c) {
  putchar(c);
  if (c == '\n')
    column = 0;
}

char read_a_char() {
  char c = getchar();
  column++;
  if (c == SPACE)
    spaces_read++;
  return c;
}


int main() {
  char c;

  while ((c = read_a_char()) != EOF) {
    if (should_output_tab(c)) {
      output_char(TAB);
      spaces_read = 0;
    } else if (should_output_spaces(c)) {
      while (spaces_read > 0) {
        output_char(SPACE);
        spaces_read--;
      }
    }
    if (c != SPACE) {
      output_char(c);
    }
  }
}
