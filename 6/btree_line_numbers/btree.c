#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


#define debug(s) fprintf(stderr, s)
#define debug_arg(s, ...) fprintf(stderr, s, __VA_ARGS__)

// Struct to hold line numbers found for a word
typedef struct list_el {
  int line_no;
  struct list_el* next;
} LinkedListEl;


// Struct to hold a tree node representing a word and its line numbers
typedef struct tnode {
  char *word;
  LinkedListEl* line_numbers;
  int count;
  struct tnode *left;
  struct tnode *right;
} Treenode;


// Struct to hold linked list elements for rebalancing the btree
typedef struct node_list {
  Treenode* node;
  struct node_list* next;
} NodeList;


int num_nodes = 0;
static Treenode *talloc(void);
static char *strdup_(char *);
static LinkedListEl* new_list_el(int);
LinkedListEl* prepend_line_count_if_unique(LinkedListEl*, int);
void listprint(LinkedListEl*);
void treeprint_recur(Treenode *p);
int min_theoretical_depth_btree(int, int);
int max_depth_tree(Treenode*, int, int);
void append_element(NodeList*, NodeList*);
Treenode* balance_tree(Treenode*);


Treenode *addtree(Treenode *p, char *w, int line_no, int depth)
{
  int cond;

  if (p == NULL) {
    // Initialise a new node
    p = talloc();
    p->word = strdup_(w);
    p->count = 1;
    p->line_numbers = new_list_el(line_no);
    p->left = p->right = NULL;
    num_nodes++;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
    p->line_numbers = prepend_line_count_if_unique(p->line_numbers, line_no);
  } else if (cond < 0) {
    p->left = addtree(p->left, w, line_no, depth + 1);
  } else {
    p->right = addtree(p->right, w, line_no, depth + 1);
  }
  return p;
}


void treeprint(Treenode *p)
{
  debug("Printing tree\n");
  printf(
         "Number items: %d, "
         "Depth: %d, "
         "Theoretical min depth: %d\n\n"
         ,
         num_nodes,
         max_depth_tree(p, 0, 0),
         min_theoretical_depth_btree(num_nodes, 0));
  // treeprint_recur(p);
}

void treeprint_recur(Treenode *p)
{
  if (p != NULL) {
    treeprint_recur(p->left);
    printf("%s: ", p->word);
    listprint(p->line_numbers);
    printf("\n");
    treeprint_recur(p->right);
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


// calculate min depth of tree of n items
int min_theoretical_depth_btree(int n_remaining_items, int depth)
{
  if (n_remaining_items < 0) {
    return depth-1;
  }
  return min_theoretical_depth_btree(n_remaining_items - pow(2, depth), depth + 1);
}

// determine max depth of tree
int max_depth_tree(Treenode* root, int depth, int max_depth)
{
  int max_depth_left, max_depth_right;
  if (root == NULL) {
    return depth - 1;
  } else {
    max_depth_left = max_depth_tree(root->left, depth+1, max_depth);
    max_depth_right = max_depth_tree(root->right, depth+1, max_depth);
    return max_depth_left > max_depth_right ? max_depth_left : max_depth_right;
  }
}

// Returns a sorted linked list of Treenodes
NodeList* build_sorted_node_list(Treenode* root)
{
  NodeList *left_el = NULL, *right_el = NULL, *right_most_of_left_child;
  NodeList *el = malloc(sizeof(NodeList));
  el->node = root;
  el->next = NULL;
  if (root->left != NULL) {
    left_el = build_sorted_node_list(root->left);
    append_element(left_el, el);
  }
  if (root->right != NULL) {
    right_el = build_sorted_node_list(root->right);
    el->next = right_el;
  }
  return (left_el != NULL) ? left_el : el; // Return the leftmost element
}

NodeList* get_element_at_offset(NodeList* start, int offset)
{
  NodeList* el = start;
  while (offset-- > 0) {
    el = el->next;
  }
  return el;
}

void append_element(NodeList* start, NodeList* new_element)
{
  NodeList* el;
  for (el = start; el->next != NULL; el = el->next)
  ;
  el->next = new_element;
}

// Build tree from sorted list
Treenode* get_tree(NodeList* first, int num_items)
{
  int mid_offset = num_items / 2;
  NodeList* mid_node_el = get_element_at_offset(first, mid_offset);
  mid_node_el->node->left = NULL;
  mid_node_el->node->right = NULL;
  if (num_items > 1) {
    mid_node_el->node->left = get_tree(first, mid_offset);
  }
  if (num_items > 2) {
    mid_node_el->node->right = get_tree(mid_node_el->next, num_items - mid_offset - 1);
  }
  return mid_node_el->node;
}

void check_list_integrity(NodeList* first, int num_items) {
  NodeList* el = first;
  while (num_items-- > 0) {
    if (strlen(el->node->word) == 0) {
      debug("Word of zero length");
      exit(1);
    }
    el = el->next;
  }
}


// Free the memory acquired by the sorted node list
void free_sorted_list(NodeList* first) {
  NodeList* el = first;
  NodeList* next;
  for (; next != NULL; el = next) {
    next = el->next;
    free(el);
  }
}

Treenode* balance_tree(Treenode* root)
{
  Treenode* new_root;
  NodeList* sorted_list;
  sorted_list = build_sorted_node_list(root);
  check_list_integrity(sorted_list, num_nodes);
  new_root = get_tree(sorted_list, num_nodes);
  free_sorted_list(sorted_list);
  debug_arg("Built balanced tree. New root word is: %s\n", new_root->word);
  return new_root;
}
