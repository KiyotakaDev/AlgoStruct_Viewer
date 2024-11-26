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

  // Static
  clear_screen();
  print_app_title();

  // Pre-dynamic render
  menu *main_menu = create_menu(0, "What do you want to view?", MAIN_OPTS);
  // Assigning options to main_menu
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
