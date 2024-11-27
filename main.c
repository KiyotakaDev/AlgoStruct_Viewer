/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "menuopts.h"

/* PROTOTYPE */
void clear_screen(void);
void say_som(void);


/* ENTRY */
int main(void) {
  // TODO: [ ] create function for dynamic menu display

  int u_opt = -1;

  // Static
  clear_screen();
  print_app_title();

  // Pre-dynamic render
  menu *main_menu = create_main_menu();
  /* 
  menu *main_menu = create_menu(0, "What do you want to view?", MAIN_OPTS);
  // Assigning options to main_menu
  add_option(main_menu, 1, "Algorithms", say_som);
  add_option(main_menu, 2, "Data Structures", say_som);
  add_option(main_menu, 0, "Exit", NULL);
  */

  // Printing
  printf("\t%s  id:%d\n", main_menu->title, main_menu->id);
  for (int i = 0; i < MAIN_OPTS; i++) {
    printf("\t(%d). %s\n", main_menu->options[i]->index, main_menu->options[i]->option);
  }
  

  printf("\t$ ");
  scanf("%d", &u_opt);

  switch (u_opt) {
    case 0:
      printf("\tExiting program... Godbye!\n\n");
      break;
    case 1:
      main_menu->options[1]->action();
      break;
    case 2:
      main_menu->options[2]->action();
      break;
    default:
      printf("\tPlease select a valid option...\n");
      break;
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
