#include <stdio.h>        // Func printf
#include <stdlib.h>       // Func free | Type NULL
#include <unistd.h>       // Func usleep
#include "apprenderer.h"  // Clear terminal
#include "datastructs.h"  // Header prototypes
#include "menuopts.h"     // Print title

// Structs
typedef struct node {
  int value;
  struct node *next;
} node;

// File prototypes
static void full_clear(void);
static void wait_char(void);
// Linked list
static node *build_linked_list(void);
static void print_linked_list(node *list);
static void free_linked_list(node *list);

// File variables
static int num_arr[] = {30, 22, 17, 5, 1, 28, 14, 2};
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


// Linked list
static void free_linked_list(node *list) {
  while (list != NULL) {
    node *temp = list;
    list = list->next; 
    free(temp);
  }
}

static void print_linked_list(node *list) {
  printf("\n\tLinked List\n");
  printf("\n\tNode Address, Node Value, Next Node\n");
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
    printf("[%03x]", ld);
    printf("[:%d]", ptr->value);
    printf("[%03x] -> ", ldp);
    ptr = ptr->next;
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



