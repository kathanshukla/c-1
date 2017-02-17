#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

typedef struct list_el {
  char *word;
  struct list_el* next;
} LinkedListEl;

typedef struct tnode {
  LinkedListEl* words;
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
