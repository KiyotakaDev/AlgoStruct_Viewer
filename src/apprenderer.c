#include <signal.h>       // Func signal | Type SIGINT
#include <stdio.h>        // Func printf
#include <stdlib.h>       // Func free
#include "apprenderer.h"  // Header prototypes
#include "menuopts.h"     // Struct menu | Func free_memory
#include "menus.h"        // Func menu_to_render 

#define ERROR_NUM -1

// Global variable
menu *renderer = NULL;

void clear_terminal(void) {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void handle_exit(int signo) {
  if (signo == SIGINT) {
    printf("\n\tExiting program... Goodbye!\n\n");
    free_memory(renderer);
    exit(0);
  }
}

void app_renderer(int *current_menu, int *u_opt) {
  // Select menu
  renderer = menu_to_render(*current_menu);

  // Detec CTRL+C
  signal(SIGINT, handle_exit);

  // Print menu
  printf("\t%s\n", renderer->title);
  if (renderer->id != ERROR_NUM) {
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
      if (renderer->options[i]->action) {
        renderer->options[i]->action(current_menu);
      } else {
        printf("\tNo action defined for this option.\n");
      }
      break; // Exit loop when option action is found
    }
  }

  // Clear input buffer
  while(getchar() != '\n');

  free_memory(renderer);
}
