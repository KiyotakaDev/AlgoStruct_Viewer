/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "menuopts.h"

/* PROTOTYPE */
void clear_screen(void);


/* ENTRY */
int main(void) {
  int u_opt = 2;

  // TODO: [x] create function for dynamic menu display

  // Static
  clear_screen();
  print_app_title();

  // Dynamic render
  menu *renderer = menu_to_render(u_opt);

  // Printer
  printf("\t%s\n", renderer->title);
  if (renderer->id == -1) {
    free(renderer->options);
    free(renderer);
    exit(1);
  }

  // Free memory
  free_memory(renderer);

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
