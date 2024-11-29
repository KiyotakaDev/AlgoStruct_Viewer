#include <stdio.h>     // Func printf
#include "appfuncs.h"  // Header prototypes

void goto_algorithms(int *menu_id) {
  *menu_id = 1;
}

void go_back(int *menu_id) {
  *menu_id -= 1;
}

void exit_app(int *menu_id) {
  printf("\tExiting program... Goodbye!\n\n");
}
