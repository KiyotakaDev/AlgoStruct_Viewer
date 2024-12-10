#include <stdio.h>     // Func printf
#include "ansi.h"      // ANSI colors
#include "appfuncs.h"  // Header prototypes

void goto_algorithms(int *menu_id) {
  *menu_id = 1;
}

void goto_datastructs(int *menu_id) {
  *menu_id = 2;
}

void go_back(int *menu_id) {
  *menu_id -= 1;
}

void exit_app(int *menu_id) {
  printf(REVERSE BOLD"\tExiting program... Goodbye!\n\n"RESET);
}
