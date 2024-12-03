#include <stdlib.h>       // NULL
#include "algorithms.h"   // App algorithms
#include "appfuncs.h"     // Funcs exit_app
#include "datastructs.h"  // App data strucutres
#include "menuopts.h"     // Struct menu | Funcs create_menu, add_option
#include "menus.h"        // Header prototypes

menu *create_main_menu(void) {
  menu *_menu = create_menu(0, "What do you want to view?", MAIN_OPTS);
  add_option(_menu, 1, "Algorithms", goto_algorithms);
  add_option(_menu, 2, "Data Structures", goto_datastructs);
  add_option(_menu, 0, "Exit", exit_app);
  
  return _menu;
}

menu *create_algorithms_menu(void) {
  menu *_menu = create_menu(1, "Algorithms", ALGO_OPTS);
  add_option(_menu, 1, "Bubble Sort", exec_bubble_sort);
  add_option(_menu, 2, "Selection Sort", exec_selection_sort);
  add_option(_menu, 3, "Merge Sort", exec_merge_sort);
  add_option(_menu, 4, "Back", go_back);
  add_option(_menu, 0, "Exit", exit_app);

  return _menu;
}

menu *create_datastructs_menu(void) {
  menu *_menu = create_menu(2, "Data Structures", DATASTRUCTS_OPTS);
  add_option(_menu, 1, "Linked Lists", show_linked_list);
  add_option(_menu, 2, "Trees", NULL);
  add_option(_menu, 3, "Dictionaries", NULL);
  add_option(_menu, 4, "Hash Tables", NULL);
  add_option(_menu, 5, "Back", go_back);
  add_option(_menu, 0, "Exit", exit_app);

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
    case 2:
      return create_datastructs_menu();
    default:
      return error_menu_handler();
  } 
}
