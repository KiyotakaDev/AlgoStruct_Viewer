#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

menu *create_main_menu(void) {
  menu *_menu = create_menu(0, "What do you want to view?", MAIN_OPTS);
  add_option(_menu, 1, "Algorithms", NULL);
  add_option(_menu, 2, "Data Structures", NULL);
  add_option(_menu, 0, "Exit", NULL);
  
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

menu *menu_to_render(int menu_id) {
  switch (menu_id) {
    case 0:
      return create_main_menu();
    case 1:
      return create_algorithms_menu();
    default:
      printf("\tThis menu does not exist | Invalid menu...");
      return NULL;
  } 
}
