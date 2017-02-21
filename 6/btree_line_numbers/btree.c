#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct list_el {
  int line_no;
  struct list_el* next;
} LinkedListEl;


typedef struct tnode {
  char *word;
  LinkedListEl* line_numbers;
  int count;
  struct tnode *left;
  struct tnode *right;
} Treenode;


static Treenode *talloc(void);
static char *strdup_(char *);
static LinkedListEl* new_list_el(int);
LinkedListEl* prepend_line_count_if_unique(LinkedListEl*, int);
void listprint(LinkedListEl*);


Treenode *addtree(Treenode *p, char *w, int line_no)
{
  int cond;

  if (p == NULL) {
    // Initialise a new node
    p = talloc();
    p->word = strdup_(w);
    p->count = 1;
    p->line_numbers = new_list_el(line_no);
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
    p->line_numbers = prepend_line_count_if_unique(p->line_numbers, line_no);
  } else if (cond < 0) {
    p->left = addtree(p->left, w, line_no);
  } else {
    p->right = addtree(p->right, w, line_no);
  }
  return p;
}

void treeprint(Treenode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%s: ", p->word);
    listprint(p->line_numbers);
    printf("\n");
    treeprint(p->right);
  }
}

void listprint(LinkedListEl* list)
{
  if (list != NULL) {
    listprint(list->next);
    printf("%d, ", list->line_no); // print in reverse order
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
static LinkedListEl* new_list_el(int line_no)
{
  LinkedListEl* new_el;
  new_el = malloc(sizeof(LinkedListEl));
  new_el->line_no = line_no;
  new_el->next = NULL;
  return new_el;
}

/*
  Checks if the line number is at the front of the linkedlist already
  and prepends it if its now

  Returns a pointer to the new head of the list
*/
LinkedListEl* prepend_line_count_if_unique(LinkedListEl* list_el, int line_no)
{
  LinkedListEl* new_el;

  if (list_el->line_no == line_no) {
    // Word already found in this line, return list_el
    return list_el;
  } else {
    new_el = new_list_el(line_no);  // Create a new list element
    new_el->next = list_el;  // Put in front of list_el
    return new_el;
  }
}
