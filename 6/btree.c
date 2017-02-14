#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list_el {
  char* word;
  struct list_el* next;
} LinkedListEl;

typedef struct tnode {
  LinkedListEl* words;
  struct tnode *left;
  struct tnode *right;
} Treenode;


static Treenode *talloc(void);
static char *strdup_(char *);
void append_unique_new_word(LinkedListEl *, char *);
static LinkedListEl* new_list_with_word(char *);
void listprint(LinkedListEl*);

Treenode *addtree(Treenode *p, char *w)
{
  int cond;

  if (p == NULL) {
    // Initialise a new node
    p = talloc();
    p->words = new_list_with_word(w);
    p->left = p->right = NULL;
  } else if ((cond = strncmp(w, p->words->word, 2)) == 0) {
    // push the new word onto the linked list if unique
    append_unique_new_word(p->words, w);
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
    listprint(p->words);
    treeprint(p->right);
  }
}

void listprint(LinkedListEl* list)
{
  if (list != NULL) {
    printf("%s, ", list->word);
    listprint(list->next);
  } else {
    printf("\n");
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

// Returns a pointer to a new list element containing S
static LinkedListEl* new_list_with_word(char* s)
{
  char* stored_word = strdup_(s);
  LinkedListEl* new_el;
  new_el = malloc(sizeof(LinkedListEl));
  new_el->word = stored_word;
  new_el->next = NULL;
  return new_el;
}

// Iterates through the linked list and adds a new word if not found
void append_unique_new_word(LinkedListEl* list, char* s)
{
  if (strcmp(s, list->word) == 0) {
    // If word match is found, do nothing
    return;
  } else if (list->next == NULL) {
    // If at end of list, add new element
    list->next = new_list_with_word(s);
  } else {
    // Keep searching through list
    append_unique_new_word(list->next, s);
  }
}
