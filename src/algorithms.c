#include <stdio.h>        // Func printf
#include "algorithms.h"   // Header prototypes
#include "apprenderer.h"  // Clear terminal
#include "menuopts.h"     // Print title

static void full_clear(void) {
  clear_terminal();
  print_app_title();
}

void exec_bubble_sort(int *_) {
  int test;
  full_clear();
  printf("\tBubble sort\n");
  printf("\tPress any key to go back ");
  getchar();
}
