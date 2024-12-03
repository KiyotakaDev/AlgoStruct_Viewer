#include <stdio.h>        // Func printf
#include "apprenderer.h"  // Clear terminal
#include "datastructs.h"  // Header prototypes
#include "menuopts.h"     // Print title

// File prototypes
static void full_clear(void);
static void wait_char(void);


void show_linked_list(int *_) {
  full_clear();
  printf("\tLinked List\n");
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
