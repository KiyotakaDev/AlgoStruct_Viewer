#include <stdio.h>        // Func printf
#include <unistd.h>       // Func usleep
#include "algorithms.h"   // Header prototypes
#include "apprenderer.h"  // Clear terminal
#include "menuopts.h"     // Print title

#define SORT_DELAY 320000

// File prototypes
static void full_clear(void);
static void wait_char(void);
static void show_graph(char *text, int *arr, int current, int sorted_up_to);
static void swap(int *a, int *b);
static void copy_arr(int *copy);

// File variables
static int cols_h_orig[] = {9, 6, 4, 8, 2, 7, 1, 5, 3};
static int arr_size = sizeof(cols_h_orig) / sizeof(cols_h_orig[0]);


void exec_bubble_sort(int *_) {
  int cols_h[arr_size];
  copy_arr(cols_h);

  // Iterate through every column
  for (int i = 0; i < arr_size; i++) {
    int swaped = 0;
    // Checks if column is ordered avoids re-checks with - i - 1
    for (int j = 0; j < arr_size - i; j++) {
      // Print graph
      show_graph("Bubble Sort", cols_h, j, arr_size - i);

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

void exec_selection_sort(int *_) {
  int cols_h[arr_size];
  copy_arr(cols_h);

  // Iterate through every element
  for (int i = 0; i < arr_size; i++) {
    int max_index = i;
    
    // Iterate through unsorted
    for (int j = i; j < arr_size; j++) {
      show_graph("Selection Sort", cols_h, j, arr_size - i);

      if (cols_h[j] < cols_h[max_index]) {
        max_index = j;
      }

      usleep(SORT_DELAY);
    }

    if (max_index != i)
      swap(&cols_h[i], &cols_h[max_index]);
  }

  wait_char();
}

void exec_merge_sort(int *_) {
  int cols_h[arr_size];
  copy_arr(cols_h);

  show_graph("Merge Sort", cols_h, -1, -1);

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

static void show_graph(char *text, int *arr, int current, int sorted_up_to) {
  full_clear();
  printf("\n\t%s\n\n", text);
  // Print numbers
  printf("\t");
  for (int i = 0; i < arr_size; i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n\n");

  // For every number in array (row)
  for (int i = 0; i < arr_size; i++) {
    printf("\t");
    // Print symbol
    for (int j = 0; j < arr[i]; j++) {
      printf("#");
    }
    printf("\n");
  }
}

static void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

static void copy_arr(int *copy) {
  for (int i = 0; i < arr_size; i++)
    copy[i] = cols_h_orig[i];
}
