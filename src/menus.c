#include <stdlib.h>
#include "menus.h"

menu *create_main_menu(void) {
  menu *_menu = create_menu(0, "What do you want to view?", MAIN_OPTS);
  add_option(_menu, 1, "Algorithms", NULL);
  add_option(_menu, 2, "Data Structures", NULL);
  add_option(_menu, 0, "Exit", NULL);
  
  return _menu;
}
