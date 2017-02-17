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

// Put the next word in string "s" into "word"
int sget_word(char* s, char* word, int lim)
{
  static char* pos; // Pointer to current position in "s". Maintains state between calls
  static char* cur_string; // Pointer to the string being processed
  char c;
  int wordlen;

  if (s != cur_string) {
    cur_string = s;
    pos = s;
  }

  for (c=*pos; is_skippable(c); c=*++pos)
  ;
  if ((c == '\0') || (c == EOF)) {
    return 0;
  }
  for (*(word++)=c; ++wordlen < lim; c=*++pos) {
    if (!is_skippable(c)) {
      
    }
  }
}

int is_skippable(char c)
{
  return (isspace(c) || (c == ',') || (c == '(') || (c == ')') ||
          (c == '"') || (c == '\'') || (c == '.') || (c == ';') ||
          (c == '[') || (c == ']') || (c == '{') || (c == '}') ||
          (c == '!') || (c == '?') || (c == '`'));
}
