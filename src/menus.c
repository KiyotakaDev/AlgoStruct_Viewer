#include <stdlib.h>    // NULL
#include "appfuncs.h"  // Funcs exit_app
#include "menuopts.h"  // Struct menu | Funcs create_menu, add_option
#include "menus.h"     // Header prototypes

menu *create_main_menu(void) {
  menu *_menu = create_menu(0, "What do you want to view?", MAIN_OPTS);
  add_option(_menu, 1, "Algorithms", NULL);
  add_option(_menu, 2, "Data Structures", NULL);
  add_option(_menu, 0, "Exit", exit_app);
  
  return _menu;
}

menu *create_algorithms_menu(void) {
  menu *_menu = create_menu(1, "Algorithms", ALGO_OPTS);
  add_option(_menu, 1, "Bubble Sort", NULL);
  add_option(_menu, 2, "Selection Sort", NULL);
  add_option(_menu, 3, "Merge Sort", NULL);
  add_option(_menu, 4, "Back", NULL);
  add_option(_menu, 0, "Exit", NULL);

  return _menu;
}

menu *error_menu_handler(void) {
  menu *_menu = create_menu(-1, "Error! This menu does not exist...", 0);
  return _menu;
}

menu *menu_to_render(int menu_id) {
  switch (menu_id) {
    case 0:
      return create_main_menu();
    case 1:
      return create_algorithms_menu();
    default:
      return error_menu_handler();
  } 
}
