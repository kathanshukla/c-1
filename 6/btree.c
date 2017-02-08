#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
} Treenode;


static Treenode *talloc(void);
static char *strdup_(char *);

Treenode *addtree(Treenode *p, char *w)
{
  int cond;

  if (p == NULL) {
    // Initialise a new node
    p = talloc();
    p->word = strdup_(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
  } else if (cond < 0) {
    p->left = addtree(p->left, w);
  } else {
    p->right = addtree(p->right, w);
  }
  return p;
}

void treeprint(Treenode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%s %d\n", p->word, p->count);
    treeprint(p->right);
  }
}

static Treenode *talloc(void)
{
  return (Treenode *) malloc(sizeof(Treenode));
}

static char *strdup_(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s) + 1);
  if (p != NULL) {
    strcpy(p, s);
  }
  return p;
}
