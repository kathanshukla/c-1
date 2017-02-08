#include <stdio.h>

int get_line(char *, int);

int main() {
  int LIM = 10, len;
  char line[LIM];

  while ((len = get_line(line, LIM)) != 0) {
    printf("Length: %d\n%s\n", len, line);
  }
}
