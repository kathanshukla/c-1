#include <stdio.h>

#define MAXLINE 10000
#define LINE_WRAP_LENGTH 6


int get_line(char line[], int maxline);
void print_range(char line[], int start, int end);
int find_line_break_index(char line[], int start, int end);

int main() {
  char line[MAXLINE];
  int len, start, end;

  while ((len = get_line(line, MAXLINE)) > 0) {
    start = end = 0;
    if (len > LINE_WRAP_LENGTH) {
      while (end < len)
      {
        end = find_line_break_index(line, start, start+LINE_WRAP_LENGTH);
        print_range(line, start, end);
        start = end;
      }
    } else {
      print_range(line, start, len);
    }
  }
}

int get_line(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

void print_range(char line[], int position, int end) {
  while (position < end) {
    if (line[position] != '\n')
      putchar(line[position]);
    position++;
  }
  if (line[end-1] != '\n')
    putchar('\n');
}

int find_line_break_index(char line[], int start, int position) {
  int break_char_ix = position;
  while (position != start) {
    if (line[position] == ' ') {
      break_char_ix = position;
      break;
    }
    position--;
  }
  return break_char_ix;
}
