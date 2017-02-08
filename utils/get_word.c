#include <ctype.h>
#include <stdio.h>

int is_valid_var_char(char c);
int is_valid_var_start_char(char c);

int get_word(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    ;
  if (c != EOF) {
    *w++ = c;
  }
  if (c == '#')
    ; // Do nothing
  else if (!is_valid_var_start_char(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++) {
    if (!is_valid_var_char(*w = getch())) {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}

int is_valid_var_char(char c)
{
  return (isalnum(c) || (c == '_'));
}

int is_valid_var_start_char(char c)
{
  return (isalpha(c) || (c == '_'));
}
