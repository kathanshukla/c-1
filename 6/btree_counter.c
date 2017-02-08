#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

typedef struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
} Treenode;


Treenode *addtree(Treenode *, char *);
void treeprint(Treenode *);
int get_word(char *, int);

int main()
{
  Treenode *root;
  char word[MAXWORD];

  root = NULL;
  while (get_word(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) {
      root = addtree(root, word);
    }
  }
  treeprint(root);
  return 0;
}
