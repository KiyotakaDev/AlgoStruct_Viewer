#include <signal.h>       // Func signal | Type SIGINT
#include <stdio.h>        // Func printf
#include <stdlib.h>       // Func free
#include "ansi.h"         // ANSI colors
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
    printf(REVERSE BOLD"\n\tExiting program... Goodbye!\n\n"RESET);
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
  printf(UNDER BOLD"\t%s\n"RESET, renderer->title);
  if (renderer->id != ERROR_NUM) {
    for (int i = 1; i < renderer->opts_num; i++) {
      printf(GREEN"\t(%d).%s %s\n", renderer->options[i]->index, RESET, renderer->options[i]->option);
    }
    // Print exit at last
    printf(PURPLE"\t(%d).%s %s\n", renderer->options[0]->index, RESET, renderer->options[0]->option);
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
