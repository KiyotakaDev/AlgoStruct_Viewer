#include <stdio.h>        // Func printf
#include <stdlib.h>       // Func free | Type NULL
#include <unistd.h>       // Func usleep
#include <ansi.h>         // ANSI colors
#include "apprenderer.h"  // Clear terminal
#include "datastructs.h"  // Header prototypes
#include "menuopts.h"     // Print title

#define DELAY 350000  // 350ms

// Structs
typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct tree {
  int value;
  struct tree *left;
  struct tree *right;
} tree;

// File prototypes
static void full_clear(void);
static void wait_char(void);
// Linked list
static node *build_linked_list(void);
static void print_linked_list(node *list);
static void free_linked_list(node *list);
// Tree
static tree *insert_node(tree *root, int value);
static tree *build_tree(void);
static void print_tree(tree *root, int spaces, char *format);
static void free_tree(tree *root);

// File variables
static int num_arr[] = {8, 4, 12, 2, 6, 10, 14, 1, 3};
static int arr_size = sizeof(num_arr) / sizeof(num_arr[0]);


void show_linked_list(int *_) {
  // Build linked list
  node *list = build_linked_list();
  if (list == NULL) return;

  // Printer
  full_clear();
  print_linked_list(list);

  // Free memory
  free_linked_list(list);


  wait_char();
}

void show_tree(int *_) {
  // Build tree
  tree *root = build_tree();

  // Printer
  full_clear();
  printf(BOLD UNDER"\n\tBinary Tree\n\n"RESET);
  printf(CYAN"\t\t[RIGHT]\n"RESET);
  printf(PURPLE"\t[HEAD]\n"RESET);
  printf(GREEN"\t\t[LEFT]\n\n"RESET);
  print_tree(root, 0, PURPLE);
  printf("\n");

  // Free memory
  free_tree(root);

  wait_char();
}


// Tree
static void free_tree(tree *root) {
  if (root == NULL) return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

static void print_tree(tree *root, int spaces, char *format) {
  int gap = 5;
  if (root == NULL) return;

  spaces += gap;

  // Print right nodes
  print_tree(root->right, spaces, CYAN);

  printf("\t");
  for (int i = gap; i < spaces; i++)
    printf(" ");

  printf("%s%d\n"RESET, format, root->value);

  // Print left nodes
  print_tree(root->left, spaces, GREEN);
}

static tree *build_tree(void) {
  tree *root = NULL;
  for (int i = 0; i < arr_size; i++) {
    root = insert_node(root, num_arr[i]);
  }
  return root;
}

static tree *insert_node(tree *root, int value) {
  if (root == NULL) {
    tree *new_node = malloc(sizeof(tree));
    if (new_node == NULL) return NULL;

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }

  if (value < root->value)
    root->left = insert_node(root->left, value);
  else
    root->right = insert_node(root->right, value);

  return root;
}

// Linked list
static void free_linked_list(node *list) {
  while (list != NULL) {
    node *temp = list;
    list = list->next; 
    free(temp);
  }
}

static void print_linked_list(node *list) {
  printf(BOLD UNDER"\n\tLinked List\n" RESET);
  printf("\n\t%s[ADDRESS]%s[VALUE]%s[NEXT]%s\n",
         GREEN, PURPLE, CYAN, RESET);
  printf("\n\t");
  node *ptr = list;
  // Print node address, node value, next node
  while (ptr != NULL) {
    // Node last digits
    unsigned long addr = (unsigned long)ptr;
    unsigned int ld = addr % 0x1000;
    unsigned long addr_p = (unsigned long)ptr->next;
    unsigned int ldp = addr_p % 0x1000;

    // Table
    printf(GREEN"[%03x]", ld);
    printf(PURPLE"[:%d]", ptr->value);
    printf(CYAN"[%03x] -> "RESET, ldp);
    fflush(stdout);
    ptr = ptr->next;
    usleep(DELAY);
  }
  printf("NULL\n");
}

static node *build_linked_list(void) {
  node *list = NULL; 

  for (int i = 0; i < arr_size; i++) {
    node *new_node = malloc(sizeof(node));  // Temp variable
    if (new_node == NULL) {
      while (new_node != NULL) {
        node *temp = list;
        list = list->next;
        free(temp);
      }
      return NULL;
    }
    new_node->value = num_arr[i];
    new_node->next = list;
    list = new_node;
  }
  return list;
}

// File functions
static void wait_char(void) {
  printf("\n\tPress any key to go back ");
  getchar();
}

static void full_clear(void) {
  clear_terminal();
  print_app_title();
}
