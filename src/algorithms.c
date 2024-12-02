#include <stdio.h>        // Func printf
#include <unistd.h>       // Func usleep
#include "algorithms.h"   // Header prototypes
#include "apprenderer.h"  // Clear terminal
#include "menuopts.h"     // Print title


// File prototypes
static void full_clear(void);
static void wait_char(void);
static void show_graph();

// File variables
static int cols_h[] = {9, 6, 4, 8, 2, 7, 1, 5, 3};
static int arr_size = sizeof(cols_h) / sizeof(cols_h[0]);


void exec_bubble_sort(int *_) {
  show_graph();
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
static void show_graph() {
  full_clear();
  printf("\n\tBubble sort\n\n");

  for (int i = 0; i < arr_size; i++) {
    printf("\t");
    for (int j = 0; j < cols_h[i]; j++) {
      printf("#");
    }
    printf("\n");
  }
}
