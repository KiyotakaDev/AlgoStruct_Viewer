#include <stdio.h>        // Func printf
#include <unistd.h>       // Func usleep
#include "algorithms.h"   // Header prototypes
#include "apprenderer.h"  // Clear terminal
#include "menuopts.h"     // Print title

#define SORT_DELAY 320000

// File prototypes
static void full_clear(void);
static void wait_char(void);
static void show_graph(int current, int sorted_up_to);
static void swap(int *a, int *b);

// File variables
static int cols_h[] = {9, 6, 4, 8, 2, 7, 1, 5, 3};
static int arr_size = sizeof(cols_h) / sizeof(cols_h[0]);


void exec_bubble_sort(int *_) {
  // Iterate through every column
  for (int i = 0; i < arr_size; i++) {
    int swaped = 0;
    // Checks if column is ordered avoids re-checks with - i - 1
    for (int j = 0; j < arr_size - i; j++) {
      // Print graph
      show_graph(j, arr_size - i);

      if (cols_h[j] > cols_h[j + 1]) {
        swap(&cols_h[j], &cols_h[j + 1]);
        swaped = 1;
      }

      usleep(SORT_DELAY); // 0.32 seg
    }

    if (!swaped)
      break;
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

static void show_graph(int current, int sorted_up_to) {
  full_clear();
  printf("\n\tBubble sort\n\n");

  // Print numbers
  printf("\t");
  for (int i = 0; i < arr_size; i++) {
    // colorize(i, current, sorted_up_to);
    printf("%d  ", cols_h[i]);
  }
  printf("\n\n");

  // For every number in array (row)
  for (int i = 0; i < arr_size; i++) {
    printf("\t");

    // colorize(i, current, sorted_up_to);

    // Print symbol
    for (int j = 0; j < cols_h[i]; j++) {
      printf("#");
    }
  
    // Reset format
    printf("\n");
  }
}

static void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
