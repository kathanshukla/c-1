#include <ctype.h>
#include <stdio.h>

int is_skippable(char c);

int get_word(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (is_skippable(c = getch()))
    ;
  if (c != EOF) {
    *w++ = c;
  }
  for ( ; --lim > 0; w++) {
    if (is_skippable(*w = getch())) {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}

int is_skippable(char c)
{
  return (isspace(c) || (c == ',') || (c == '(') || (c == ')') ||
          (c == '"') || (c == '\'') || (c == '.') || (c == ';') ||
          (c == '[') || (c == ']') || (c == '{') || (c == '}') ||
          (c == '!') || (c == '?') || (c == '`'));
}
