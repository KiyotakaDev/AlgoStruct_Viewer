#include <stdio.h>        // Func printf
#include <unistd.h>       // Func usleep
#include "algorithms.h"   // Header prototypes
#include "apprenderer.h"  // Clear terminal
#include "menuopts.h"     // Print title

#define SORT_DELAY 250000

// File prototypes
static void full_clear(void);
static void wait_char(void);
static void show_graph(char *text, int *arr, int current, int sorted_up_to);
static void swap(int *a, int *b);
static void copy_arr(int *copy);
static void merge_sort(int *arr, int left, int right);
static void merge(int *arr, int left, int mid, int right);

// File variables
static int cols_h_orig[] = {9, 6, 4, 8, 2, 7, 1, 5, 3};
static int arr_size = sizeof(cols_h_orig) / sizeof(cols_h_orig[0]);


void exec_bubble_sort(int *_) {
  int cols_h[arr_size];
  copy_arr(cols_h);

  // Iterate through every column
  for (int i = 0; i < arr_size; i++) {
    // Checks if column is ordered avoids re-checks with - i - 1
    for (int j = 0, av = arr_size - i - 1; j < av; j++) {
      // Print graph
      show_graph("Bubble Sort", cols_h, j, av);

      if (cols_h[j] > cols_h[j + 1])
        swap(&cols_h[j], &cols_h[j + 1]);

      usleep(SORT_DELAY);
    }
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

  merge_sort(cols_h, 0, arr_size - 1);

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

static void merge_sort(int *arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    // Divide halves
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    // Merge halves
    merge(arr, left, mid, right);
  }
}

static void merge(int *arr, int left, int mid, int right) {
  int n1 = mid - left + 1; // Elements in first half
  int n2 = right - mid;    // Elements in second half

  int L[n1], R[n2];        // Temp arrays to store each half

  // Copy data in temp variables
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[mid + 1 + i];

  // Iterate variables (i-L | j-R | k-arr)
  int i = 0, j = 0, k = left;

  // Merge arrays in a ordered one
  while(i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    show_graph("Merge Sort", arr, k, -1);
    usleep(SORT_DELAY);
    k++;
  }

  // Copy remaining items from L[]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
    show_graph("Merge Sort", arr, k, -1);
    usleep(SORT_DELAY);
  }
  // Copy remaining items from R[]
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
    show_graph("Merge Sort", arr, k, -1);
    usleep(SORT_DELAY);
  }
}
