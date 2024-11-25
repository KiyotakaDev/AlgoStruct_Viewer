/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include "menuopts.h"

/* PROTOTYPE */
void clear_screen(void);


/* ENTRY */
int main(void) {
  // TODO: [ ] create function for dynamic menu display
    // TODO: [x] Allocate memory for menu.dicts property
    // TODO: [x] Assign values menu(id, *title, dict(index, *option))
    // TODO: [x] Print menu

   // Maybe data can be extractef from a CSV file

  // Static
  clear_screen();
  print_app_title();

  // Pre-dynamic render
  menu *new_menu = malloc(sizeof(menu));
  new_menu->id = 0;
  new_menu->title = "\tWhat you want to view?";
  new_menu->options = malloc(sizeof(dict *));
  new_menu->options[0] = malloc(sizeof(dict));

  // Assigning an option
  new_menu->options[0]->index = 1;
  new_menu->options[0]->option = "Algorithms";

  // Print menu (not dynamic yet)
  printf("%s\tid: %d\n", new_menu->title, new_menu->id);
  printf("\t(%d). %s\n", new_menu->options[0]->index, new_menu->options[0]->option);
  printf("\n");

  free(new_menu->options[0]);
  free(new_menu->options);
  free(new_menu);
  new_menu = NULL;

  return 0;
}


/* FUNCTIONS */
void clear_screen(void) {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
