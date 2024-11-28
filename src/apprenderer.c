#include <stdio.h>        // Func printf
#include <stdlib.h>       // Func free
#include "apprenderer.h"  // Header prototypes
#include "menuopts.h"     // Struct menu | Func free_memory
#include "menus.h"        // Func menu_to_render 

void clear_terminal(void) {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void app_renderer(int *current_menu, int *u_opt) {
  // Variable
  int found = 0;

  // Select menu
  menu *renderer = menu_to_render(*current_menu);

  // Print menu
  printf("\t%s\n", renderer->title);
  if (renderer->id != 1) {
    for (int i = 0; i < renderer->opts_num; i++) {
      printf("\t(%d). %s\n", renderer->options[i]->index, renderer->options[i]->option);
    } 
  } else {
    free(renderer->options);
    free(renderer);
    exit(0);
  }

  // Get user input
  printf("\t$ ");
  scanf("%d", u_opt);

  // Search option and execute its action
  for (int i = 0; i < renderer->opts_num; i++) {
    if (renderer->options[i]->index == *u_opt) {
      found = 1;
      if (renderer->options[i]->action) {
        renderer->options[i]->action(current_menu);
      } else {
        printf("\tNo action defined for this option.\n");
      }
//      break;
    }
  }

 // if (!found)
  //  printf("\tInvalid option, try again...\n");
  //
  // Clear input buffer
  while(getchar() != '\n');

  free_memory(renderer);
}
