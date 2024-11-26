/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include "menuopts.h"

/* DEFINES */
#define MAIN_OPTS 3

/* PROTOTYPE */
void clear_screen(void);
void say_som(void);


/* ENTRY */
int main(void) {
  // TODO: [ ] create function for dynamic menu display
    // TODO: [x] Allocate memory for menu.dicts property
    // TODO: [x] Assign values menu(id, *title, dict(index, *option))
    // TODO: [x] Print menu

  // Static
  clear_screen();
  print_app_title();

  // Pre-dynamic render
  /*
  menu *new_menu = malloc(sizeof(menu));
  new_menu->id = 0;
  new_menu->title = "\tWhat you want to view?";
  new_menu->options = malloc(MENU_OPTS * sizeof(dict *));
  new_menu->options[0] = malloc(sizeof(dict));
  new_menu->options[1] = malloc(sizeof(dict));
  new_menu->options[2] = malloc(sizeof(dict));

  // Assigning an option
  new_menu->options[0]->index = 1;
  new_menu->options[0]->option = "Algorithms";
  new_menu->action = say_som;

  new_menu->options[1]->index = 2;
  new_menu->options[1]->option = "Data Structures";

  new_menu->options[2]->index = 0;
  new_menu->options[2]->option = "Exit";

  // Print menu (not dynamic yet)
  printf("%s\tid: %d\n", new_menu->title, new_menu->id);
  for (int i = 0; i < MENU_OPTS; i++) {
    printf("\t(%d). %s\n", new_menu->options[i]->index, new_menu->options[i]->option);
  }
  new_menu->action(); printf("\n");
  for (int i = 0; i < MENU_OPTS; i++) {
    if (new_menu->options[i] != NULL)
      free(new_menu->options[i]);
  }
  free(new_menu->options);
  free(new_menu);
  new_menu = NULL;
  */

  // Testing function implementation
  menu *main_menu = create_menu(0, "What do you want to view?", MAIN_OPTS);
  // Using function to add_option
  add_option(main_menu, 1, "Algorithms", say_som);
  add_option(main_menu, 2, "Data Structures", say_som);
  add_option(main_menu, 0, "Exit", say_som);

  // Printing
  printf("\t%s  id:%d\n", main_menu->title, main_menu->id);
  for (int i = 0; i < MAIN_OPTS; i++) {
    printf("\t(%d). %s\n", main_menu->options[i]->index, main_menu->options[i]->option);
  }

  // Free memory
  free_memory(main_menu);

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

void say_som(void) {
  printf("\tUsing struct function :D\n");
}
