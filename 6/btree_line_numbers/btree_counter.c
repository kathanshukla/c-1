#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define MAXLINE 10000

typedef struct tnode {
  char *word;
  int* line_numbers;
  int total_linenumbers;
  struct tnode *left;
  struct tnode *right;
} Treenode;


Treenode *addtree(Treenode *, char *);
void treeprint(Treenode *);
int get_word(char *, int);
int get_line(char *s, int lim);

int main()
{
  Treenode *root;
  char line[MAXWORD];

  root = NULL;
  while (get_word(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) {
      root = addtree(root, word);
    }
  }
  treeprint(root);
  return 0;
}
