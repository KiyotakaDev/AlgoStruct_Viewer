#include <stdio.h>        // Func printf
#include <stdlib.h>       // Func free | Type NULL
#include <unistd.h>       // Func usleep
#include "apprenderer.h"  // Clear terminal
#include "datastructs.h"  // Header prototypes
#include "menuopts.h"     // Print title

// File prototypes
static void full_clear(void);
static void wait_char(void);

// File variables
static int num_arr[] = {30, 22, 17, 5, 1, 28, 14, 2};
static int arr_size = sizeof(num_arr) / sizeof(num_arr[0]);


void show_linked_list(int *_) {
  // Create struct for node
  typedef struct node {
    int value;
    struct node *next;
  } node;

  node *list = NULL; 

  for (int i = 0; i < arr_size; i++) {
    node *new_node = malloc(sizeof(node));  // Temp variable
    if (new_node == NULL) return;

    new_node->value = num_arr[i];
    new_node->next = list;
    list = new_node;
  }

  // Printer
  full_clear();
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

  // Free
  while (list != NULL) {
    node *temp = list;
    list = list->next; 
    free(temp);
  }

  wait_char();
}


// File functions
static void full_clear(void) {
  clear_terminal();
  print_app_title();
}

static void wait_char(void) {
  printf("\n\tPress any key to go back ");
  getchar();
}
