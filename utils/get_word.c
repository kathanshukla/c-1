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

// Get the next word from string "s" and put it in "word"
// Returns number of characters advanced
int sget_word(char* s, char* word, int lim)
{
  char* curpos;
  for (curpos=s; is_skippable(*curpos); curpos++)
  ;
  if (*curpos == '\0') {
    return 0; // No word found, so we have not advanced along string
  }
  for (*word=*curpos; !is_skippable(*curpos) && (*curpos != '\0'); *++word=*++curpos)
  ;
  *word = '\0';
  return curpos - s;
}

int is_skippable(char c)
{
  return (isspace(c) || (c == ',') || (c == '(') || (c == ')') ||
          (c == '"') || (c == '\'') || (c == '.') || (c == ';') ||
          (c == '[') || (c == ']') || (c == '{') || (c == '}') ||
          (c == '!') || (c == '?') || (c == '`'));
}
